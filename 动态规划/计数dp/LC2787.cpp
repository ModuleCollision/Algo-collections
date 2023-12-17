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
	int numberOfWays(int n, int x) {
		vector<i64>p(n + 5, 0);
		i64 tot = 0;
		for (i64 i = 1; i <= n; i++) {
			i64 cur = 1; bool f = 1;
			for (i64 j = 1; j <= x; j++) {
				cur *= i; if (cur > n) {
					f = 0; break;
				}
			}
			if (not f)break;
			else p[++tot] = cur;
		}
		vector dp(tot + 5, vector<i64>(n + 5, 0)); dp[0][0] = 1;
		for (i64 i = 1; i <= tot; i++) {
			for (i64 j = 0; j <= n; j++) {
				dp[i][j] += dp[i - 1][j] % mod;
				if (j >= p[i])dp[i][j] += dp[i - 1][j - p[i]] % mod;
				dp[i][j] %= mod;
			}
		}
		return dp[tot][n] % mod;
	}
};