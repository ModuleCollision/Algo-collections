import java.util.*;
/*一题两解 : 二分*/
/*最小化数组最大值 && 最大化数组的最小值,统一二分套路*/
class Solution {
	public int minimizeMax(int[] nums, int p) {
		Arrays.sort(nums);
		int n = nums.length, l = 0, r = nums[n - 1] - nums[0];
		while (l < r) {
			int mid = (l + r) / 2; int cnt = 0;
			for (int i = 0; i < n - 1; i++) {
				if (nums[i + 1] - nums[i] <= mid) {
					++cnt; ++i;
				}
			}
			if (cnt >= p) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return r;
	}
}