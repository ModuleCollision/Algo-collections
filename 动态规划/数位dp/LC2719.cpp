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

	int count(string num1, string num2, int min_sum, int max_sum) {
		auto cal = [&](string s) {
			int m = s.size(); i64 dp[m + 5][10000];
			memset(dp, -1, sizeof(dp));
			function<i64(int, int, bool, bool)>dfs = [&](int idx, int sum, bool isnum, bool islimit) {
				if (idx == m) {
					return (i64)(isnum and sum >= min_sum and sum <= max_sum) ;
				}
				if (not islimit and isnum and dp[idx][sum] != -1)return dp[idx][sum];
				i64 res = 0;
				if (not isnum)res = (res % mod + dfs(idx + 1, sum, false, false)) % mod;
				i64 low = isnum ? 0 : 1;
				i64 up = islimit ? s[idx] - '0' : 9;
				for (i64 d = low; d <= up; d++) {
					if (sum + d <= max_sum)res = (res % mod + dfs(idx + 1, sum + d, true, islimit and d == up)) % mod;
				}
				if (not islimit and isnum)dp[idx][sum] = res;
				return res % mod;
			};
			return dfs(0, 0, false, true);
		};
		auto check = [&](string s) {
			i64 ret = 0; for (i64 i = 0; i < s.size(); i++)ret += s[i] - '0';
			return ret >= min_sum and ret <= max_sum;
		};
		return (cal(num2) - cal(num1) + mod + check(num1)) % mod;
	}
};