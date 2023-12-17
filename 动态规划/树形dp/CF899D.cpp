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
	i64 n; std::cin >> n; vector<i64>A(n + 1, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector<vector<i64>>tr(n + 1);
	for (i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v; tr[u].push_back(v);
		tr[v].push_back(u);
	}
	vector<i64>dp(n + 1, 0); auto sz = dp;
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		sz[u] = 1;
		for (auto v : tr[u]) {
			if (v == f)continue;
			dfs(v, u);
			sz[u] += sz[v];
			dp[u] += sz[v] * (A[u] ^ A[v]) + dp[v];
		}
	};
	vector<i64>ans(n + 1, 0);
	function<void(i64, i64)>dfs2 = [&](i64 u, i64 f) {
		ans[u] = dp[u];
		for (auto v : tr[u]) {
			if (v == f)continue;
			i64 szv = sz[v], szu = sz[u], dpu = dp[u], dpv = dp[v];
			dp[u] -= dp[v] + sz[v] * (A[u] ^ A[v]); sz[u] -= sz[v];
			dp[v] += sz[u] * (A[u] ^ A[v]) + dp[u];
			sz[v] += sz[u];
			dfs2(v, u);
			dp[u] = dpu; dp[v] = dpv; sz[u] = szu; sz[v] = szv;
		}
	};
	dfs(1, 0); dfs2(1, 0);
	for (i64 i = 1; i <= n; i++)cout << ans[i] << " ";
	cout << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T --) solve();
}