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



bool vis[maxn]; i64 p[maxn];
class Solution {
public:
	long long maximumSum(vector<int>& nums) {
		int n = nums.size(); p[1] = 1;
		for (i64 i = 1; i <= 1e4; i++)p[i] = 1;
		for (i64 i = 2; i <= 1e4; i++) {
			if (not vis[i]) {
				for (i64 j = i + i; j <= 1e4; j += i)vis[j] = true;
				for (i64 j = i; j <= 1e4; j += i) {
					i64 tmp = j, cnt = 0;
					while (tmp % i == 0)tmp /= i, cnt++;
					if (cnt & 1)p[j] *= i;
				}
			}
		}
		std::unordered_map<i64, i64>mp;
		for (i64 i = 0; i < n; i++)mp[p[i + 1]] += nums[i];
		i64 ans = 0;
		for (auto [x, y] : mp)ans = max(ans, y);
		return ans;
	}
};