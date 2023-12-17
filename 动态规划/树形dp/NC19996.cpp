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

i64 N, K;
i64 dp[maxn][maxn];
vector<pair<i64, i64>>tr[maxn];
i64 sz[maxn];
void solve() {
	std::cin >> N >> K;
	for (i64 i = 1; i <= N - 1; i++) {
		i64 u, v, w; std::cin >> u >> v >> w;
		tr[u].push_back({v, w});
		tr[v].push_back({u, w});
	}
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		dp[u][0] = dp[u][1] = 1; sz[u] = 1;
		for (auto s : tr[u]) {
			i64 w = s.second, v = s.first;
			if (v == f)continue;
			dfs(v, u);
			vector<i64>tmp(sz[u] + sz[v] + 5, 0);
			for (i64 i = 0; i <= min(K, sz[u]); i++) {
				for (i64 j = 0; j <= min(K - i, sz[v]); j++) {
					i64 k = i * j * w + (sz[u] - i) * (sz[v] - j) * w;
					tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j] + k);
				}
			}
			for (i64 i = 0; i <= sz[u] + sz[v]; i++) {
				dp[u][i] = tmp[i];
			}
			sz[u] += sz[v];
		}
	};
	dfs(1, 1);
	cout << dp[1][K] << endl;
}
signed main() {
	solve();
}