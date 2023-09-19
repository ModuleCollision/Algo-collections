class Solution {
    const int MOD = 1e9 + 7;
    const int dirs[4][2] = {{ -1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int countPaths(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int dp[m + 1][n + 1]; memset(dp, -1, sizeof(dp));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != -1) return dp[i][j];
            int res = 1;
            for (auto &d : dirs) {
                int x = i + d[0], y = j + d[1];
                if (0 <= x && x < m && 0 <= y && y < n && grid[x][y] > grid[i][j])
                    res = (res + (dfs(x, y))) % MOD;
            }
            // 计算当前节点的贡献 ： res = 1
            //类似树形dp
            return dp[i][j] = res;
        };
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                ans = (ans + dfs(i, j)) % MOD;
        return ans;
    }
};
