/*单调队列优化dp*/


/*很显然, 本题格子之间的可达性不单调, 故单调队列优化是错解*/
class Solution {
public:
	int minimumVisitedCells(vector<vector<int>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector g(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)g[i][j] = grid[i - 1][j - 1];
		}
		vector qq(m + 1, vector<int>(4 * n + 1, 0));
		vector<int>h(m + 1, 1), t(m + 1, 0);
		vector<int>q(4 * m + 1); int head, tail;
		vector dp(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			head = 1, tail = 0;
			for (int j = 1; j <= m; j++) {
				if (i == 1 and j == 1)continue;
				while (head <= tail and dp[i][q[tail]] > dp[i][j - 1])tail--;
				q[++tail] = j - 1;
				while (g[i][q[head]] + q[head] < j and head <= tail)head++;
				if (head <= tail)
					dp[i][j] = min(dp[i][j], dp[i][q[head]] + 1);
				while (h[j] <= t[j] and dp[qq[j][t[j]]][j] > dp[i - 1][j])t[j]--;
				qq[j][++t[j]] = i - 1;
				while (g[qq[j][h[j]]][j] + qq[j][h[j]] < i and h[j] <= t[j])h[j]++;
				if (h[j] <= t[j])
					dp[i][j] = min(dp[i][j], dp[qq[j][h[j]]][j] + 1);
			}
		}
		if (dp[n][m] == 0x3f3f3f3f)return -1;
		return dp[n][m];
	}
};