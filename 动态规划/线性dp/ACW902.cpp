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
	i64 n, m; std::string A, B;
	std::cin >> n >> A >> m >> B;
	A = " " + A; B = " " + B;
	vector dp(n + 1, vector<i64>(m + 1, inf));
	for (i64 i = 0; i <= n; i++) {
		dp[i][0] = i;
	}
	for (i64 i = 0; i <= m; i++) {
		dp[0][i] = i;
	}
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= m; j++) {
			dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
			if (A[i] == B[j]) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
			} else {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << dp[n][m] << endl;
}
signed main() {
	solve();
}