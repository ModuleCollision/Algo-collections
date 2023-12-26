#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

vector<pair<i64, i64>>dir = {{1, 0}, {0, -1}, { -1, 0}, {0, 1}};
void solve() {
	i64 H, W, T;
	std::cin >> H >> W >> T;
	vector<string>G(H + 5);
	for (i64 i = 1; i <= H; i++) {
		std::cin >> G[i];
		G[i] = " " + G[i];
	}
	i64 tot = 0;
	for (i64 i = 1; i <= H; i++) {
		for (i64 j = 1; j <= W; j++)if (G[i][j] == 'o')tot++;
	}
	vector dis(tot + 5, vector<i64>(tot + 5, 0));
	std::map<pair<i64, i64>, i64>sk;
	std::map<i64, pair<i64, i64>>ks;
	vector tmpdis(H + 5, vector<i64>(W + 5, 0));
	i64 sx, sy, tx, ty;
	i64 cnt = 0;
	for (i64 i = 1; i <= H; i++) {
		for (i64 j = 1; j <= W; j++) {
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
	auto check = [&](i64 x, i64 y) {
		return G[x][y] != '#' and x >= 1 and x <= H and y >= 1 and y <= W;
	};
	auto bfs = [&](i64 x, i64 y) {
		for (i64 i = 1; i <= H; i++) {
			std::fii64(tmpdis[i].begin(), tmpdis[i].end(), inf);
		}
		tmpdis[x][y] = 0;
		queue<pair<i64, i64>>q;
		q.push({x, y});
		while (q.size()) {
			auto [cx, cy] = q.front(); q.pop();
			for (auto [dx, dy] : dir) {
				i64 nx = cx + dx, ny = cy + dy;
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
	vector dp((1 << tot) + 5, vector<i64>(tot + 5, inf));
	bfs(sx, sy);
	if (tmpdis[tx][ty] > T) {
		puts("-1"); return;
	}
	for (auto [k, idx] : sk) {
		dp[(1 << (idx - 1))][idx - 1] = tmpdis[k.first][k.second];
	}
	bfs(tx, ty);
	i64 ans = 0;
	for (i64 i = 1; i < (1 << tot); i++) {
		for (i64 j = 0; j < tot; j++) {
			if ((i >> j) & 1) {
				for (i64 k = 0; k < tot; k++) {
					if (((~i >> k) & 1) and dp[i][j] + dis[j + 1][k + 1] <= T) {
						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dis[j + 1][k + 1]);
					}
				}
				if (dp[i][j] + tmpdis[ks[j + 1].first][ks[j + 1].second] <= T) {
					ans = max(ans, (i64)__builtin_popcount(i));
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}