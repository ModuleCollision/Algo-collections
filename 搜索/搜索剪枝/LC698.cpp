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
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int all = accumulate(nums.begin(), nums.end(), 0);
		if (all % k > 0) {
			return false;
		}
		int per = all / k;
		sort(nums.begin(), nums.end());
		if (nums.back() > per) {
			return false;
		}
		int n = nums.size();
		vector<bool> dp(1 << n, false);
		vector<int> curSum(1 << n, 0);
		dp[0] = true;
		for (int i = 0; i < 1 << n; i++) {
			if (!dp[i]) {
				continue;
			}
			for (int j = 0; j < n; j++) {
				if (curSum[i] + nums[j] > per) {
					break;
				}
				if (((i >> j) & 1) == 0) {
					int next = i | (1 << j);
					if (!dp[next]) {
						curSum[next] = (curSum[i] + nums[j]) % per;
						dp[next] = true;
					}
				}
			}
		}
		return dp[(1 << n) - 1];
	}
};