class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		vector dp(n + 5, vector (k + 5, vector<int>(3, -inf)));
		//0 空仓, 1持仓
		dp[0][0][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				if (dp[i - 1][j][0] != -inf)
					dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
				if (j >= 1)
					if (dp[i - 1][j - 1][1] != -inf)
						dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j - 1][1] + prices[i - 1]);
				if (dp[i - 1][j][1] != -inf)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]);
				if (dp[i - 1][j][0] != -inf)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] - prices[i - 1]);
			}
		}
		int res = 0;
		for (int i = 0; i <= k; i++)res = max({res, dp[n][i][0], dp[n][i][1]});
		return res;
	}
};