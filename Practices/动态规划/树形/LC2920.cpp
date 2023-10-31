class Solution {
public:
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int K) {
        int n = coins.size();
        const int MAXP = 20;

        // 建图
        vector<int> e[n];
        for (auto &edge : edges) {
            e[edge[0]].push_back(edge[1]);
            e[edge[1]].push_back(edge[0]);
        }

        const long long INF = 1e18;
        long long dp[n][MAXP][2];
        for (int i = 0; i < n; i++) for (int j = 0; j < MAXP; j++) dp[i][j][0] = dp[i][j][1] = -INF;
        // 树 dp
        function<void(int, int)> dfs = [&](int sn, int fa) {
            long long now = coins[sn];
            for (int j = 0; j < MAXP; j++) {
                dp[sn][j][0] = now - K;
                if (j > 0) dp[sn][j][1] = now;
                now >>= 1;
            }
            // 枚举子节点的操作
            for (int fn : e[sn]) if (fn != fa) {
                    dfs(fn, sn);
                    for (int j = 0; j < MAXP; j++) {
                        // 这里的 min 是因为我们只考虑 log 次操作
                        long long best = max(dp[fn][j][0], dp[fn][min(MAXP - 1, j + 1)][1]);
                        dp[sn][j][0] += best;
                        dp[sn][j][1] += best;
                    }
                }
        };
        dfs(0, -1);

        long long ans = 0;
        for (int j = 0; j < MAXP; j++) ans = max({ans, dp[0][j][0], dp[0][j][1]});
        return ans;
    }
};

