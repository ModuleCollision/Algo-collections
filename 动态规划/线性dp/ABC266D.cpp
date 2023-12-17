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

i64 w[maxn][10], T, X, A, N;
i64 dp[maxn][10];
void solve() {
	std::cin >> N;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> T >> X >> A;
		w[T][X] = A;
	}
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (i64 i = 1; i <= 1e5; i++) {//枚举时间
		for (i64 j = 0; j <= min(i, 4i64); j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j >= 1)
				//上一个时刻的后一个坐标
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + w[i][j]);
			if (j <= 3)
				//上一个时刻的前一个坐标
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + w[i][j]);
		}
	}
	i64 ans = 0;
	for (i64 i = 0; i <= 4; i++) {
		ans = max(ans, dp[100000][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}