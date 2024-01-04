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
	i64 n, m; std::cin >> n >> m;
	std::map<i64, f64>dp;
	vector<vector<pair<i64, i64>>>tr(n + 5);
	for (i64 i = 1; i <= m; i++) {
		i64 u, v, w; std::cin >> u >> v >> w;
		tr[u].push_back({v, w});
	}
	function<f64(i64)>dfs = [&](i64 u) {
		if (dp.count(u))return dp[u];
		dp[u] = 0.0;
		f64 ret = 0.0;
		f64 k = 1.0 / (tr[u].size());
		for (auto [v, w] : tr[u]) {
			ret += ((f64)dfs(v) + w) * k;
		}
		dp[u] = ret;
		return ret;
	};
	printf("%.2lf", dfs(1));
}
signed main() {
	solve();
}