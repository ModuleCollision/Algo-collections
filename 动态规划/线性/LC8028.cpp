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
          if ((s1[i] == s2[i]) == !k) {
            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][0]); continue;
          }
          dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j + 1][0] + x);
          dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][1] + 1);
          if (j) {
            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][0]);
          }
        }
      }
    }
    return dp[n][0][0];
  }
};


class Solution {
public:
  const int inf = 0x3f3f3f3f;
  int minOperations(string s1, string s2, int x) {
    if (count(s1.begin(), s1.end(), '1') % 2 != count(s2.begin(), s2.end(), '1') % 2) {
      return -1;
    }
    int n = s1.size();
    int dp[n + 5][n + 5][2];
    memset(dp, 0x3f, sizeof(dp));
    s1 = " " + s1; s2 = " " + s2;
    function<int(int, int, int)>dfs = [&](int i, int j, int k) {
      if (i <= 0) {
        return dp[i][j][k] = (j or k) ? inf : 0;
      }
      if (dp[i][j][k] != inf)return dp[i][j][k];
      if ((s1[i] == s2[i]) == !k) {
        return dp[i][j][k] = dfs(i - 1, j, 0);
      }
      dp[i][j][k] = min(dp[i][j][k], dfs(i - 1, j + 1, 0) + x);
      dp[i][j][k] = min(dp[i][j][k], dfs(i - 1, j, 1) + 1);
      if (j) {
        dp[i][j][k] = min(dp[i][j][k], dfs(i - 1, j - 1, 0));
      }
      return dp[i][j][k];
    };
    return dfs(n, 0, 0);
  }
};