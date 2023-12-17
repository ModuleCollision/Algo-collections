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

vector<i64>tr[maxn]; i64 n;
i64 dp[maxn]; i64 w[maxn];
void solve() {
	std::cin >> n;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	for (i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	i64 ans = -inf;
	function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
		dp[u] = w[u]; ans = max(ans, dp[u]);
		for (auto v : tr[u]) {
			if (v == f) {
				continue;
			}
			dfs(v, u);
			ans = max(ans, dp[u] + dp[v]);
			dp[u] = max(dp[u], w[u] + dp[v]);
		}
	};
	dfs(1, 0);
	cout << ans << endl;
}
signed main() {
	solve();
}