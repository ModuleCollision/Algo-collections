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
	i64 n; std::cin >> n;
	vector<i64>A(n + 5, 0), B(n + 5, 0);
	vector<i64>pos;
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 i = 1; i <= n; i++) {
		std::cin >> B[i]; if (B[i] == 1)pos.push_back(i);
	}
	vector dp(n + 5, vector<i64>(10, 0));
	if (pos[0] != 1) {
		dp[0][0] = A[pos[0] - 1];
	}
	dp[0][1] = A[pos[0]]; dp[0][2] = A[pos[0] + 1];
	for (i64 i = 1; i < pos.size(); i++) {
		i64 j = pos[i]; i64 k = pos[i - 1];
		if (j - k >= 3) {
			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j - 1];
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j];
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j + 1];
		} else if (j - k == 1) {
			dp[i][0] = dp[i - 1][0] + A[j - 1];
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][1]}) + A[j];
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j + 1];
		} else if (j - k == 2) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + A[j - 1];
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j];
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j + 1];
		}
	}
	i64 ans = 0;
	for (i64 i = 0; i < pos.size(); i++) {
		ans = max({dp[i][0], dp[i][1], dp[i][2]});
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
