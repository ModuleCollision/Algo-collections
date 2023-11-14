#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
vector<pair<ll, ll>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
void solve() {
	ll n, m, r1, r2;
	std::cin >> n >> m >> r1 >> r2;
	vector<string>G(n + 5);
	for (ll i = 1; i <= n; i++) {
		std::cin >> G[i];
		G[i] = " " + G[i];
	}
	ll ex, ey, sx, sy;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (G[i][j] == 'P') {
				ex = i; ey = j;
			} else if (G[i][j] == 'M') {
				sx = i; sy = j;
			}
		}
	}
	auto check = [&](ll x, ll y) {
		return x >= 1 and x <= n and y >= 1 and y <= m;
	};
	vector<vector<ll>>dis1(n + 5, vector<ll>(m + 5, inf));
	vector<vector<bool>>vis1(n + 5, vector<bool>(m + 5, 0));
	auto dis2 = dis1; auto vis2 = vis1;
	auto bfs1 = [&]() {
		queue<pair<ll, ll>>q;
		q.push({ex, ey});
		vis1[ex][ey] = 1;
		dis1[ex][ey] = 0;
		while (q.size()) {
			auto [x, y] = q.front();
			q.pop();
			for (auto [dx, dy] : dir) {
				ll xx = x + dx; ll yy = y + dy;
				if ((not check(xx, yy)) or vis1[xx][yy] or G[xx][yy] == '*') {
					continue;
				}
				dis1[xx][yy] = dis1[x][y] + 1;
				vis1[xx][yy] = 1; q.push({xx, yy});
			}
		}
	};
	auto bfs2 = [&]() {
		queue<pair<ll, ll>>q;
		q.push({sx, sy});
		vis2[sx][sy] = 1;
		dis2[sx][sy] = 0;
		while (q.size()) {
			auto [x, y] = q.front();
			q.pop();
			for (auto [dx, dy] : dir) {
				ll xx = x + dx; ll yy = y + dy;
				if ((not check(xx, yy)) or vis2[xx][yy] or G[xx][yy] == '*') {
					continue;
				}
				dis2[xx][yy] = dis2[x][y] + 1;
				vis2[xx][yy] = 1; q.push({xx, yy});
			}
		}
	};
	bfs1(); bfs2(); ll ans = inf;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (vis1[i][j] and vis2[i][j] and (abs(i - ex) + abs(j - ey) <= r1) and abs(i - sx) + abs(j - sy) <= r2) {
				ans = min(ans, dis1[i][j] + dis2[i][j]);
			}
		}
	}
	if (ans == inf) {
		puts("-1"); return;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}