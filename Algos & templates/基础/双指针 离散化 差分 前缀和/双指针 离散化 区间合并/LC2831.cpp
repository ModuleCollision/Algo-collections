class Solution {
public:
	int longestEqualSubarray(vector<int>& nums, int k) {
		int n = nums.size();
		vector<vector<int>>f(n + 1);
		for (int i = 0; i < n; i++) {
			f[nums[i]].push_back(i - f[nums[i]].size());
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int sz = f[i].size();
			if (sz <= ans)continue;
			for (int r = 0, l = 0; r < sz; r++) {
				while (f[i][r] - f[i][l] > k)l++;
				ans = max(ans, r - l + 1);
			}
		}
		return ans;
	}
};