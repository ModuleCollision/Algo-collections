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
	
	long long continuousSubarrays(vector<int>& nums) {
		ll ans = 0;
		int n = nums.size(); std::map<int, int>cnt;
		auto add = [&](int v) {
			cnt[v]++;
		};
		auto del = [&](int v) {
			cnt[v]--;
			if (cnt[v] == 0)cnt.erase(v);
		};
		auto query = [&]()->bool{
			int x1 = cnt.begin()->first;
			auto s2 = --cnt.end();
			int x2 = s2->first;
			return x2 - x1 > 2;
		};
		for (int l = 0, r = 0; r < n; r++) {
			add(nums[r]);
			while (query()) {
				del(nums[l++]);
			}
			ans += (ll)(r - l + 1);
		}
		return ans;
	}
};