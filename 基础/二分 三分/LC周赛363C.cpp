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
	
	int maxNumberOfAi64oys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
		i64 ans = 0;
		for (auto c : composition) {
			auto check = [&](i64 mid) {
				i64 ret = 0;
				for (i64 i = 0; i < n; i++) {
					ret += cost[i] * max(0i64, mid * c[i] - stock[i]);
					if (ret > budget)return false;
				}
				return true;
			};
			i64 l = 0, r = 1e10;
			while (l < r) {
				i64 mid = (l + r + 1) >> 1;
				if (check(mid))l = mid;
				else r = mid - 1;
			}
			ans = max(ans, l);
		}
		return (int)ans;
	}
};