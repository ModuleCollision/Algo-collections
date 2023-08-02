/*利用位运算 or gcd的性质解决通用问题*/
class Solution {
public:
	vector<int> smallestSubarrays(vector<int>& nums) {
		int n = nums.size();
		vector<int>ans(n + 5, 0);
		for (int i = 0; i < n; i++) {
			ans[i] = 1; ll v = 0;
			for (int j = i - 1; j >= 0 and nums[j] | nums[i] != nums[j]; j--) {
				nums[j]  |= nums[i];
				ans[j] = max(ans[j], i - j + 1);
			}
		}
		return ans;
	}
};

/*模板*/
class Solution {
public:
	vector<int> smallestSubarrays(vector<int> &nums) {
		int n = nums.size();
		vector<int>ans(n);
		vector<pair<int, int>>suf;
		for (int i = n - 1; i >= 0; i--) {
			suf.push_back({0, i});
			suf[0].first |= nums[i];
			int k = 0;
			for (int j = 1; j < suf.size(); j++) {
				suf[j].first |= nums[i];
				if (suf[k].first == suf[j].first) {
					suf[k].second = suf[j].second;//找寻前缀不变后的最小下标
				} else {
					suf[++k] = suf[j];
				}
			}
			suf.resize(k + 1);
			ans[i] = suf[0].second - i + 1;
		}
		return ans;
	}
};