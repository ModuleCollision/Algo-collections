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
	i64 n; string s; std::cin >> n >> s;
	s = " " + s;
	vector dp(n + 5, vector((1 << 11), vector<i64>(11, 0)));
	i64 pre = s[1] - 'A';
	dp[1][(1 << pre)][pre] = 1;
	for (i64 i = 2; i <= n; i++) {
		for (i64 j = 0; j <= (1 << 10) - 1; j++) {
			for (i64 k = 0; k <= 9; k++)dp[i][j][k] = (dp[i][j][k] % mod + dp[i - 1][j][k]) % mod;
		}
		i64 pre = s[i] - 'A';
		for (i64 j = 0; j <= (1 << 10) - 1; j++) {
			if ((j >> pre) & 1) {
				dp[i][j][pre] = (dp[i][j][pre] % mod + dp[i - 1][j][pre]) % mod;
				for (i64 w = 0; w <= 9; w++) {
					if ((j >> w) & 1) {
						dp[i][j][pre] = (dp[i][j][pre] % mod + dp[i - 1][j - (1 << pre)][w]) % mod;
					}
				}
			}
		}
		dp[i][(1 << pre)][pre] += 1; dp[i][1 << pre][pre] %= mod;
	}
	i64 ans = 0; for (i64 j = 0; j <= (1 << 10) - 1; j++)for (i64 k = 0; k <= 9; k++)ans = (ans % mod + dp[n][j][k]) % mod;
	cout << ans << endl;
}
signed main() {
	solve();
}