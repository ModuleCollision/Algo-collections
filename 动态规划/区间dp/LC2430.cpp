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
	int deleteString(string s) {
		i64 n = s.size();
		if (*max_element(s.begin(), s.end()) == *min_element(s.begin(), s.end())) {
			return n;
		}
		vector<i64>dp(n + 5, 0);
		dp[0] = 0;
		const i64 mod = 1e9 + 7, b = 23;
		auto ksm = [&](i64 a, i64 b) {
			int ret = 1;
			while (b) {
				if (b & 1)ret = ret * a % mod;
				a = a * a % mod;
				b >>= 1;
			}
			return ret;
		};
		vector<i64>Hash(n + 5, 0);
		for (i64 i = 1; i <= n; i++) {
			Hash[i] = (Hash[i - 1] % mod * b % mod + s[i - 1] - 'a') % mod;
		}
		auto get = [&](i64 l, i64 r)  {
			return ((Hash[r] - Hash[l - 1] % mod * ksm(b, r - l + 1) % mod) % mod + mod) % mod;
		};
		for (int i = n; i >= 1; i--) {
			for (int len = 2; i + len - 1 <= n; len += 2) {
				int j = i + len - 1;
				if (get(i, i + len / 2 - 1) == get(i + len / 2, j)) {
					dp[i] = max(dp[i], dp[i + len / 2]);
				}

			}
			dp[i]++;
		}
		return dp[1];
	}
};