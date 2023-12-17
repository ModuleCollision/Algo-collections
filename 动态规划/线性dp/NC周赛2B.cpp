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
	i64 n; cin >> n; vector<i64>A(n + 5, 0); for (i64 i = 1; i <= n; i++)cin >> A[i];
	vector dp(n + 5, vector<i64>(2, 0));
	std::string s; cin >> s; s = " " + s;
	for (i64 i = 2; i <= n; i++) {
		if (s[i] != s[i - 1]) {
			dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i - 1] + A[i]);
			dp[i][1] = max(dp[i][1], dp[i - 2][0] + A[i - 1] + A[i]);
		}
		dp[i][0] = max(dp[i][0], dp[i - 1][1]);
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}
signed main() {
	solve();
}