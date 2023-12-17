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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
	int numberOfWays(int startPos, int endPos, int k) {
		std::map<pair<i64, i64>, i64>dp;
		function<i64(i64, i64)>dfs = [&](i64 idx, i64 p) {
			if (idx == endPos) {
				if (p == k)return dp[ {idx, p}] = 1;
			}
			if (abs(idx - endPos) > k - p)return dp[ {idx, p }] = 0;
			if (p == k) {
				return dp[ {idx, p}] = 0;
			}
			if (dp.count({idx, p}))return dp[ {idx, p}] % mod;
			i64 res = 0;
			res = (res % mod + dfs(idx + 1, p + 1)) % mod;
			res = (res % mod + dfs(idx - 1, p + 1)) % mod;
			dp[ {idx, p}] = res; return res % mod;
		};
		return dfs(startPos, 0) % mod;
	}
};