/*定义i, j为到达格子i , j所需的最少步数*/
/*定义i, j为到达格子i , j所需的最少步数*/
class Solution {
public:
	int minimumVisitedCells(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		int dp[n + 5][m + 5];
		memset(dp, 0x3f, sizeof(dp));
		dp[0][0] = 0;
		auto check = [&](int x, int y) {
			return x >= 0 and x <= n and y >= 0 and y <= m;
		};
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int v = grid[i][j];
				for (int k = 1; k <= v; k++) {
					if (check(i , j + k))
						dp[i][j + k] = min(dp[i][j + k], dp[i][j] + 1);
				}
				for (int k = 1; k <= v; k++) {
					if (check(i + k, j))
						dp[i + k][j] = min(dp[i + k][j], dp[i][j] + 1);
				}
			}
		}
		return dp[n - 1][m - 1] == 0x3f3f3f3f ? -1 : dp[n - 1][m - 1] + 1;
	}
};