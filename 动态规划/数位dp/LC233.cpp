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
	int countDigitOne(int n) {
		string s = to_string(n);
		i64 m = s.size();
		i64 dp[m + 5][10]; memset(dp, -1, sizeof(dp));
		function<i64(int, int, bool, bool)>dfs = [&](int idx, int cnt, bool islimit, bool isnum) {
			if (idx == m)return isnum ? (i64)cnt : 0;
			if (not islimit and (int)dp[idx][cnt] != -1 and isnum)return dp[idx][cnt];
			i64 res = 0;
			if (not isnum)res += dfs(idx + 1, cnt, false, false);
			i64 low = isnum ? 0 : 1;
			i64 up = islimit ? s[idx] - '0' : 9;
			for (i64 d = low; d <= up; d++) {
				res += dfs(idx + 1, cnt + (d == 1), islimit and d == up, true);
			}
			if (not islimit and isnum)dp[idx][cnt] = res;
			return res;
		};
		return (int)dfs(0, 0, true, false);
	}
};


class Solution {
public:

	int countDigitOne(int n) {
		vector<i64>dp(10 + 5, 0), p(15, 0);
		p[0] = 1;
		for (i64 i = 1; i <= 10; i++) {
			p[i] = p[i - 1] * 10;
		}
		string s = to_string(n);
		i64 len = s.size();
		dp[1] = 1;
		for (i64 i = 2; i <= 10; i++) {
			dp[i] = dp[i - 1] * 10 + p[i - 1];
		}
		reverse(s.begin(), s.end());
		s = " " + s; i64 ans = 0;
		for (i64 i = len; i >= 1; i--) {
			i64 c = s[i] - '0';
			n -= p[i - 1] * c;
			ans += c * dp[i - 1];
			if (c > 1) {
				ans += p[i - 1];//最高位对1产生的贡献
			} else if (c == 1) {//最高位为1时产生的贡献
				ans += (n + 1);
			}
		}
		return ans;
	}
};