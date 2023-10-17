class Solution {
public:
  const int inf = 0x3f3f3f3f;
  int minOperations(string s1, string s2, int x) {
    if (count(s1.begin(), s1.end(), '1') % 2 != count(s2.begin(), s2.end(), '1') % 2) {
      return -1;
    }
    int n = s1.size();
    s1 = " " + s1; s2 = " " + s2;
    vector dp(n + 5, vector(n + 5, vector<int>(2, inf)));
    dp[0][0][0] = 0;//剩几次操作机会,上一位是否翻转
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= n; j++) {
        for (int k = 0; k <= 1; k++) {
          if ((s1[i] == s2[i]) == !k) {//k代表上一位是否采取相邻操作
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][k]); continue;
          }
          dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j][k] + 1);
          if (j >= 1) {
            dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j - 1][k] + x);
          }
          dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j + 1][k]);
        }
      }
    }
    return dp[n][0][0];
  }
};