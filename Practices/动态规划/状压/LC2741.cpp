class Solution {
public:
  typedef long long ll;
  const ll mod = 1e9 + 7;
  int specialPerm(vector<int>& nums) {
    int n = nums.size();
    vector dp((1 << n) + 5, vector<ll>(n + 1, 0));
    for (int  i = 0; i < n; i++)dp[(1 << i)][i] = 1;
    for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          int w = i - (1 << j);
          for (int k = 0; k < n; k++) {
            if (nums[k] % nums[j] == 0 or nums[j] % nums[k] == 0) {
              dp[i][j] = (dp[i][j] + dp[w][k]) % mod;
            }
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = (res % mod + dp[(1 << n) - 1][i]) % mod;
    }
    return res;
  }
};