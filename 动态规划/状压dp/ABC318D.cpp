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
	vector w(n + 5, vector<i64>(n + 5, 0));
	for (i64 i = 1; i <= n - 1; i++) {
		for (i64 j = i + 1; j <= n; j++)cin >> w[i][j];
	}
	vector dp(n + 5, vector<i64>((1 << (n + 1)) + 5, 0));
	for (i64 i = 2; i <= n; i++) {
		dp[1][(1 << (i - 1)) + 1] = w[1][i];
	}
	for (i64 i = 2; i <= n - 1; i++) {
		for (i64 j = 0; j < (1 << n); j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (((j >> (i - 1)) & 1) == 1)continue;
			for (i64 k = i + 1; k <= n; k++) {
				if (((j >> (k - 1)) & 1) == 0) {
					dp[i][j + (1 << (k - 1)) + (1 << (i - 1))] = max(dp[i][j + (1 << (k - 1)) + (1 << (i - 1))], dp[i][j] + w[i][k]);
				}
			}
		}
	}
	i64 ans = 0;
	for (i64 i = 0; i < (1 << n); i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


