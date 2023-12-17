class Solution {
public:
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

	int checkRecord(int n) {
		i64 dp[n + 5][5][3]; memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;//前i 天, j次缺勤, 末尾迟到次数为k
		for (i64 i = 1; i <= n; i++) {
			for (i64 j = 0; j <= 1; j++) {
				for (i64 k = 0; k <= 2; k++) {
					if (j >= 1) {
						dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j - 1][k]) % mod;
					}
				}//最后一天是缺勤
			}
			//最后一天是到场
			for (i64 j = 0; j <= 1; j++) {
				for (i64 k = 0; k <= 2; k++)dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j][k]) % mod;
			}
			//最后一天是迟到
			for (i64 k = 0; k <= 2; k++) {
				for (i64 j = 0; j <= 1; j++) {
					if (k >= 1)
						dp[i][j][k] = (dp[i][j][k] % mod + dp[i - 1][j][k - 1]) % mod;
				}
			}
		}
		i64 ans = 0;
		for (i64 j = 0; j <= 1; j++) {
			for (i64 k = 0; k <= 2; k++) {
				ans = (ans % mod + dp[n][j][k]) % mod;
			}
		}
		return (int)ans;
	}
};