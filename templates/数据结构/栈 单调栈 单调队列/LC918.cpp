class Solution {
public:
  int maxSubarraySumCircular(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      nums.push_back(nums[i]);
    }
    int stk[100005]; memset(stk, 0, sizeof(stk));
    int hed = 1, tal = 0;
    nums.insert(nums.begin(), 0); int ans = -0x3f3f3f3f;
    for (int i = 1; i <= 2 * n; i++)nums[i] += nums[i - 1];
    for (int i = 1; i <= 2 * n; i++) {
      while (hed <= tal and nums[stk[tal]] >= nums[i - 1])tal--;
      stk[++tal] = i - 1;
      while (i - stk[hed] > n)hed++;
      ans = max(ans, nums[i] - nums[stk[hed]]);
    }
    return ans;
  }
};