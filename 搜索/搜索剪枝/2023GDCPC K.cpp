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

void solve() {
	i64 n, m, k;
	std::cin >> n >> m >> k;
	vector<vector<i64>> G(n + 5, vector<i64>(m + 5, 0));
	i64 ans = k;
	i64 u, v; i64 s = 0;
	for (i64 i = 1; i <= k; i++) {
		cin >> u >> v;
		G[u][v] = 1;
	}
	vector<pair<i64, i64>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};
	function<void(i64)> dfs = [&](i64 s) {
		ans = min(ans, s);
		for (i64 i = 1; i <= n; i++) {
			for (i64 j = 1; j <= m; j++) {
				if (not G[i][j])continue;
				for (auto [dx, dy] : dir) {
					i64 x = i + dx; i64 y = j + dy;
					if (not (x >= 1 and x <= n and y >= 1 and y <= m))continue;
					i64 xx = x + dx, yy = y + dy;
					if (not (xx >= 1 and xx <= n and yy >= 1 and yy <= m))continue;
					if ((G[i][j] == 1 and G[x][y] == 1 and G[xx][yy] == 0)) {
						G[i][j] = 0; G[x][y] = 0; G[xx][yy] = 1;
						dfs(s - 1);
						G[i][j] = 1; G[x][y] = 1; G[xx][yy] = 0;
					}
				}
			}
		}
	};
	dfs(k);
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	i64 t; std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}