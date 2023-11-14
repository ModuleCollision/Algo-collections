class Solution {
public:
	int maxNumOfMarkedIndices(vector<int> &nums) {
		int n = nums.size();
		//int ans = 0;
		std::sort(nums.begin(), nums.end());
		int l = 0, r = n / 2;
		auto check = [&](int mid) {
			for (int i = 0; i < mid; i++) {
				if (2 * nums[i] > nums[n - mid + i])return false;
			}
			return true;
		};//第二种二分形式(需记住)
		int ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				l = mid + 1; ans = mid;
			} else {
				r = mid - 1;
			}
		}
		return ans << 1;
	}
};