class Solution {
public:
    typedef long long ll;
    const int mod = 1e9 + 7;
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(); int m = grid[0].size();
        int dp[n + 5][m + 5][k + 5];
        memset(dp, 0, sizeof(dp));
        dp[1][1][grid[0][0] % k] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 and j == 1)continue;
                for (int s = 0; s < k; s++) {
                    dp[i][j][(s + grid[i - 1][j - 1]) % k] = (dp[i][j][(s + grid[i - 1][j - 1]) % k] % mod + dp[i - 1][j][s]) % mod;
                    dp[i][j][(s + grid[i - 1][j - 1]) % k] = (dp[i][j][(s + grid[i - 1][j - 1]) % k] % mod + dp[i][j - 1][s]) % mod;
                }
            }
        }
        int ans = 0;
        ans = dp[n][m][0] % mod;
        return (int)ans;
    }
};