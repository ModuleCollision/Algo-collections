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
	i64 n; std::cin >> n; i64 ans = 0;
	i64 dp[n + 5][n + 5];
	vector<i64>a(n + 5, 0);
	for (i64 i = 1; i <= n; i++)std::cin >> a[i];
	memset(dp, 0, sizeof(dp));
	for (i64 len = 1; len <= n; len++) {
		for (i64 i = 1; i + len - 1 <= n; i++) {
			i64 j = i + len - 1;
			if (len == 1) {
				dp[i][j] = 0;
			}
			else if (a[i] < a[j]) {
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
			} else {
				dp[i][j] = j - i;
			}
			ans += dp[i][j];
		}
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}