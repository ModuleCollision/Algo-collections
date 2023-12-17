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
	i64 n, m, k; std::cin >> n >> m >> k;
	vector dp(k + 2, vector<i64>(n + 1, 0));
	std::vector<vector<i64>>tr(n + 1);
	std::set<pair<i64, i64>>st;
	while (m--) {
		i64 u, v; std::cin >> u >> v; if (u > v)swap(u, v);
		tr[u].push_back(v); tr[v].push_back(u);
	}
	dp[0][1] = 1; i64 pre = 1;
	/*枚举点和出边进行dp*/
	for (i64 i = 1; i <= k; i++) {
		i64 cur = pre; pre = 0;
		for (i64 j = 1; j <= n; j++) {
			dp[i][j] = (dp[i][j] % mod + (cur - dp[i - 1][j]) % mod + mod) % mod;
			for (auto v : tr[j]) {
				dp[i][j] = ((dp[i][j] - dp[i - 1][v]) % mod + mod) % mod;
			}
			pre = (pre % mod + dp[i][j]) % mod;
		}
	}
	cout << dp[k][1] % mod << endl;
}
signed main() {
	solve();
}