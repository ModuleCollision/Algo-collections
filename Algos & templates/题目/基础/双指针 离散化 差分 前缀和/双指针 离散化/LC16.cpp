class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int n = nums.size();
		int ans = inf;//枚举 + 二分 枚举 + 双指针
		for (int i = 0; i < n; i++) {
			if (i > 0 and nums[i] == nums[i - 1])continue;
			int j = i + 1, k = n - 1;
			while (j < k) {
				int sum = nums[i] + nums[j] + nums[k];
				if (abs(sum - target) < abs(ans - target)) {
					ans = sum;
				}
				if (sum > target) {
					int k0 = k - 1;
					while (j < k0 and nums[k0] == nums[k])--k0;
					k = k0;
				} else {
					int j0 = j + 1;
					while (j0 < k and nums[j0] == nums[j]) {
						++j0;
					}
					j = j0;
				}
			}
		}
		return ans;
	}
};