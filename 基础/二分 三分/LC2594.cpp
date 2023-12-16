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
	long long repairCars(vector<int>& ranks, int cars) {
		std::sort(ranks.begin(), ranks.end(), [&]( i64 a,  i64 b)->bool{
			return a < b;
		});
		auto check = [&]( i64 mid) {
             i64 tmp = cars;
			for (auto r : ranks) {
				 i64 n = 0;
				while (r * n * n <= mid)n++;
				if (r * n * n > mid)n--;
				tmp -= n;
			}
			if (tmp > 0)return false;
			return true;
		};
		 i64 l = 0, r = 0x3f3f3f3f;
		while (l < r) {
			 i64 mid = (l + r) >> 1;
			if (check(mid))r = mid;
			else l = mid + 1;
		}
		return r;
	}
};