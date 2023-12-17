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
	vector dp(n + 5, vector<i64>(m + 5, 0));
	for (i64 i = 1; i <= m; i++)dp[1][i] = 1;
	vector pre(n + 5, vector<i64>(m + 5, 0));
	for (i64 i = 1; i <= m; i++)pre[1][i] = (pre[1][i - 1] % mod + dp[1][i]) % mod;
	for (i64 i = 2; i <= n; i++) {
		for (i64 j = 1; j <= m; j++) {
			if (j + k <= m) {
				i64 v = ((pre[i - 1][m] - pre[i - 1][j + k - 1]) % mod + mod) % mod;
				dp[i][j] = (dp[i][j] % mod + v) % mod;
			}
			if (j - k >= 1) {
				i64 v = ((pre[i - 1][j - k] - pre[i - 1][0]) % mod + mod) % mod;
				dp[i][j] = (dp[i][j] % mod + v) % mod;
			}
			pre[i][j] = (pre[i][j - 1] % mod + dp[i][j]) % mod;
		}
	}
	i64 ans = 0;
	for (i64 i = 1; i <= m; i++)ans = (ans % mod + dp[n][i]) % mod;
	cout << ans % mod << endl;
}
signed main() {
	solve();
}