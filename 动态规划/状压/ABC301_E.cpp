#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
vector<pair<ll, ll>>dir = {{1, 0}, {0, -1}, { -1, 0}, {0, 1}};
void solve() {
	ll H, W, T;
	std::cin >> H >> W >> T;
	vector<string>G(H + 5);
	for (ll i = 1; i <= H; i++) {
		std::cin >> G[i];
		G[i] = " " + G[i];
	}
	ll tot = 0;
	for (ll i = 1; i <= H; i++) {
		for (ll j = 1; j <= W; j++)if (G[i][j] == 'o')tot++;
	}
	vector dis(tot + 5, vector<ll>(tot + 5, 0));
	std::map<pair<ll, ll>, ll>sk;
	std::map<ll, pair<ll, ll>>ks;
	vector tmpdis(H + 5, vector<ll>(W + 5, 0));
	ll sx, sy, tx, ty;
	ll cnt = 0;
	for (ll i = 1; i <= H; i++) {
		for (ll j = 1; j <= W; j++) {
			if (G[i][j] == 'o') {
				cnt++;
				sk[ {i, j}] = cnt;
				ks[cnt] = {i, j};
			} else if (G[i][j] == 'S') {
				sx = i; sy = j;
			} else if (G[i][j] == 'G') {
				tx = i; ty = j;
			}
		}
	}
	auto check = [&](ll x, ll y) {
		return G[x][y] != '#' and x >= 1 and x <= H and y >= 1 and y <= W;
	};
	auto bfs = [&](ll x, ll y) {
		for (ll i = 1; i <= H; i++) {
			std::fill(tmpdis[i].begin(), tmpdis[i].end(), inf);
		}
		tmpdis[x][y] = 0;
		queue<pair<ll, ll>>q;
		q.push({x, y});
		while (q.size()) {
			auto [cx, cy] = q.front(); q.pop();
			for (auto [dx, dy] : dir) {
				ll nx = cx + dx, ny = cy + dy;
				if (check(nx, ny) and tmpdis[nx][ny] == inf) {
					tmpdis[nx][ny] = tmpdis[cx][cy] + 1;
					q.push({nx, ny});
				}
			}
		}
	};
	for (auto [k, idx] : sk) {
		bfs(k.first, k.second);
		for (auto [k2, idx2] : sk) {
			dis[idx][idx2] = tmpdis[k2.first][k2.second];
		}
	}
	vector dp((1 << tot) + 5, vector<ll>(tot + 5, inf));
	bfs(sx, sy);
	if (tmpdis[tx][ty] > T) {
		puts("-1"); return;
	}
	for (auto [k, idx] : sk) {
		dp[(1 << (idx - 1))][idx - 1] = tmpdis[k.first][k.second];
	}
	bfs(tx, ty);
	ll ans = 0;
	for (ll i = 1; i < (1 << tot); i++) {
		for (ll j = 0; j < tot; j++) {
			if ((i >> j) & 1) {
				for (ll k = 0; k < tot; k++) {
					if (((~i >> k) & 1) and dp[i][j] + dis[j + 1][k + 1] <= T) {
						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dis[j + 1][k + 1]);
					}
				}
				if (dp[i][j] + tmpdis[ks[j + 1].first][ks[j + 1].second] <= T) {
					ans = max(ans, (ll)__builtin_popcount(i));
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}