/*此题我们运用枚举+预处理数组解决*/
/*动态规划+预处理*/
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

class Solution {
public:

	int countPalindromes(string s) {
		i64 n = s.size();
		i64 suf[n + 2][10], dp1[n + 2][10][10];
		i64 pre[n + 2][10], dp2[n + 2][10][10];//c统计某一位上某一字符前缀和
		//f统计某两字符的组合数
		memset(pre, 0, sizeof(pre));
		memset(suf, 0, sizeof(suf));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		for (i64 i = 1; i <= n; i++) {
			i64 x = s[i - 1] - '0';
			for (i64 j = 0; j <= 9; j++) {
				pre[i][j] += pre[i - 1][j] % mod;
			}
			pre[i][x]++;
			for (i64 j = 0; j <= 9; j++) {
				for (i64 k = 0; k <= 9; k++) {
					dp1[i][j][k] = dp1[i - 1][j][k];
				}
			}
			for (i64 k = 0; k <= 9; k++) {
				dp1[i][k][x] = (dp1[i][k][x] % mod + pre[i - 1][k]) % mod;
			}
		}


		for (i64 i = n; i >= 1; i--) {
			i64 x = s[i - 1] - '0';
			for (i64 j = 0; j <= 9; j++) {
				suf[i][j] += suf[i + 1][j];
			}
			suf[i][x]++;
			for (i64 j = 0; j <= 9; j++) {
				for (i64 k = 0; k <= 9; k++) {
					dp2[i][j][k] += dp2[i + 1][j][k];
				}
			}
			for (i64 k = 0; k <= 9; k++) {
				dp2[i][x][k] = (dp2[i][x][k] % mod + suf[i + 1][k]) % mod;
			}
		}
		i64 ans = 0;
		for (i64 i = 1; i <= n; i++) {
			i64 x = (s[i - 1] - '0');
			for (i64 j = 0; j <= 9; j++) {
				for (i64 k = 0; k <= 9; k++) {
					ans = (ans % mod + dp1[i - 1][j][k] % mod * dp2[i + 1][k][j]) % mod;
				}
			}
		}
		return ans;
	}
};

