
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

char s[maxn]; i64 n;
i64 dp[maxn][8];
void solve() {
	std::cin >> (s + 1);
	i64 n = strlen(s + 1);
	for (i64 i = 1; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 2; j <= 7; j++) {
			if (j == 2 or j == 4) {
				for (i64 k = 1; k <= i - 1; k++) {
					if (s[k] < s[i]) {
						dp[i][j] = (dp[i][j] % mod + dp[k][j - 1]) % mod;
					}
				}
			} else if (j == 3 or j == 5 or j == 6 or j == 7) {
				for (i64 k = 1; k <= i - 1; k++) {
					if (s[k] > s[i]) {
						dp[i][j] = (dp[i][j] % mod + dp[k][j - 1]) % mod;
					}
				}
			}
		}
	}
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++)ans = (ans % mod + dp[i][7]) % mod;
	cout << ans % mod << endl;
}
signed main() {
	solve();
}