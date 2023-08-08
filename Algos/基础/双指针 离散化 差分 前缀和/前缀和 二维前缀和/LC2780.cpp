class Solution {
public:
	int minimumIndex(vector<int>& nums) {
		int n = nums.size();
		std::map<int, int>cnt;
		for (auto c : nums)cnt[c]++;
		int f = 0; int mx = 0;
		for (auto [x, y] : cnt) {
			if (y > f) {
				f = y; mx = x;
			}
		}
		vector<int>pre(n + 5, 0);
		pre[0] = (nums[0] == mx);
		for (int i = 1; i < n; i++) {
			pre[i] += pre[i - 1];
			pre[i] += (nums[i] == mx);
		}
		for (int i = 0; i < n - 1; i++) {
			if (pre[i] * 2 > (i + 1) and ((pre[n - 1] - pre[i]) * 2 > (n - 1 - i))) {
				return i;
			}
		}
		return -1;
	}
};