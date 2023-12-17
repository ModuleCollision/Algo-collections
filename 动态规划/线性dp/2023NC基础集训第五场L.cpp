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
	vector<i64>b(m + 5), x(m + 5);
	for (i64 i = 1; i <= m; i++)cin >> b[i] >> x[i];
	vector dp(m + 5, vector<i64>(n + 5, inf));
	dp[0][n] = 0;
	for (i64 i = 1; i <= m; i++) {
		for (i64 j = n; j >= 1; j--) {
			dp[i][j - j % x[i]] = min(dp[i][j - j % x[i]], dp[i - 1][j] + b[i]);
		}
	}
	for (i64 i = 1; i < n; i++) {
		if (dp[m][i] != inf) {
			cout << dp[m][i] << endl; return;
		}
	}
}
signed main() {
	solve();
}