/*子数组，异或，布尔值dp*/
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
	vector dp(n + 1, vector<bool>(n + 1, false));
	dp[0][0] = 1;
	for (i64 i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		vector<bool>v(n + 1, false); i64 mex = 0;
		vector vis(i + 1, vector<bool>(n + 1, false));
		for (i64 j = i; j >= 1; j--) {
			v[A[j]] = 1; while (v[mex])mex++;
			if (vis[j][mex])continue; vis[j][mex] = 1;
			for (i64 k = 0; k <= j; k++) {
				if (dp[j - 1][k])dp[i][k ^ mex] = 1;
			}
		}
	}
	i64 ans = 0; for (i64 k = 0; k <= n; k++)if (dp[n][k])ans = max(ans, k);
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}