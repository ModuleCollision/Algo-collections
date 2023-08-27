class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		vector dp(n + 5, vector(k + 5, vector<int>(3, -inf)));
		//前 i 天 j 次交易 当天为某状态的最大值(空仓, 持仓, 售出)
		for (int j = 0 ; j <= k; j ++)
			dp[0][j][0] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				if (dp[i - 1][j][0] != -inf)
					dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][0]);
				if (dp[i - 1][j][2] != -inf)
					dp[i][j][0] = max(dp[i][j][0], dp[i - 1][j][2]);
				if (dp[i - 1][j][0] != -inf)
					//由空仓, 持仓, 售出转移而来
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][0] - prices[i - 1]);
				if (dp[i - 1][j][2] != -inf)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][2] - prices[i - 1]);
				if (dp[i - 1][j][1] != -inf)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1]);
				if (j >= 1 and dp[i - 1][j - 1][1] != -inf)
					//售出只能由持仓转移而来
					dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][1] + prices[i - 1]);
			}
		}
		return max({dp[n][k][0], dp[n][k][1], dp[n][k][2]});
	}
};


class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		vector dp(n + 5, vector (k + 5, vector<int>(3, -inf)));
		//0 空仓, 1持仓
		dp[0][0][0] = 0;
		for (int j = 0; j <= k; j++)dp[0][j][0] = 0;
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
		return max(dp[n][k][0], dp[n][k][1]);
	}
};