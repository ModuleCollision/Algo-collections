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


i64 n, k;
f64 p[maxn], dp[maxn][105];
void solve() {
	std::cin >> n >> k; f64 e = 0;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> p[i]; e += p[i];
	}
	dp[0][0] = 1.0;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= k; j++) {
			dp[i][j] += dp[i - 1][j] * (1 - p[i]);
			if (j)
				dp[i][j] += dp[i - 1][j - 1] * (p[i]);
		}
	}
	printf("%5lf\n", e);
	printf("%5lf\n", dp[n][k]);
}
signed main() {
	solve();
}