#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
vector<pair<ll, ll>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<string>s(n + 5);
	for (ll i = 1; i <= n; i++) {
		cin >> s[i]; s[i] = " " + s[i];
	}
	vector vis(n + 5, vector<bool>(m + 5, 0));
	auto vi = vis;
	auto bfs = [&]() {
		queue<pair<ll, ll>>q;
		q.push({2, 2}); vis[2][2] = 1; vi[2][2] = 1;
		while (not q.empty()) {
			auto [x, y] = q.front(); q.pop();
			for (auto [dx, dy] : dir) {
				ll nx = x, ny = y;
				while (s[nx][ny] == '.') {
					vis[nx][ny] = 1;
					nx += dx; ny += dy;
				}
				nx -= dx, ny -= dy;
				if (vi[nx][ny])continue;
				vi[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	};
	bfs();
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++)if (vis[i][j])cnt++;
	}
	cout << cnt << endl;
}
signed main() {
	solve();
}