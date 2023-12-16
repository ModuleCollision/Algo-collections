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
	bool isMatch(string s, string p) {
		int n = s.size(), m = p.size();
		bool dp[n + 5][m + 5];
		memset(dp, false, sizeof(dp));
		s = " " + s; p = " " + p;
		dp[0][0] = true;
		for (int i = 1; i <= m; i++) {
			if (p[i] == '*' and i >= 2)dp[0][i] |= dp[0][i - 2];
		}
		for (i64 i = 1; i <= n; i++) {
			for (i64 j = 1; j <= m; j++) {
				if ((isalpha(p[j]) and p[j] == s[i]) or p[j] == '.')dp[i][j] |= dp[i - 1][j - 1];
				else {
					if (p[j - 1] == '.') {
						for (i64 k = i; k >= 0; k--)dp[i][j] |= dp[k][j - 2];
					} else {
						i64 k = i; while (s[k] == p[j - 1] and k >= 1)k--;
						if (j > 1)
							for (i64 w = i; w >= k; w--)dp[i][j] |= dp[w][j - 2];
					}
				}
			}
		}
		return dp[n][m];
	}
};