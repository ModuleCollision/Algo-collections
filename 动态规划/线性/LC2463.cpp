typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
  long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
    std::sort(robot.begin(), robot.end());
    std::sort(factory.begin(), factory.end());
    int n = factory.size(); int m = robot.size();
    vector dp(n + 5, vector<ll>(m + 5, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        ll cost = 0;
        for (int k = 0; k <= min(j, factory[i - 1][1]); k++) {
          
          dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + cost);
          if(j > k)
          cost += abs(robot[j - k - 1] - factory[i - 1][0]);
        }
      }
    }
    return dp[n][m];
  }
};