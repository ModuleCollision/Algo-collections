class Solution {
public:
  long long appealSum(string s) {
    int n = s.size(); s = " " + s;
    vector<int>pre(n + 1, 0), pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre[i] = pos[s[i] - 'a'];
      pos[s[i] - 'a'] = i;
    }
    vector<ll>dp(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
      dp[i] += dp[i - 1] + i - pre[i];
    }
    return accumulate(dp.begin(), dp.end(), 0ll);
  }
};