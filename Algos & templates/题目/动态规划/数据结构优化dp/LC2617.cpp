/*单调栈 + 二分优化dp*/
/*滑窗范围不确定, 故用单调栈维护dp值的单调性, 二分出合法的下标来更新答案*/
class Solution {
public:
	int minimumVisitedCells(vector<vector<int>>& grid) {
		int n = grid.size(); int m = grid[0].size();
		vector<vector<pair<int, int>>>col(m + 5);//列单调栈
		vector g(n + 5, vector<int>(m + 5, 0));
		for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)g[i][j] = grid[i - 1][j - 1];
		vector dp(n + 5, vector<int>(m + 5, 0x3f3f3f3f));
		dp[n][m] = 1;
		for (int i = n; i >= 1; i--) {
			std::vector<pair<int, int>>q;//本行的单调栈
			for (int j = m; j >= 1; j--) {
				auto &st = col[j];
				if (i == n and j == m)continue;
				int v = g[i][j];
				while (q.size() and q.back().second >= dp[i][j + 1])q.pop_back();
				q.push_back({j + 1, dp[i][j + 1]});
				while (st.size() and st.back().second >= dp[i + 1][j])st.pop_back();
				st.push_back({i + 1, dp[i + 1][j]});
				/*下标单调递减, 值单调递增, 选择第一个, 即满足条件的值最小的*/
				auto idx = lower_bound(q.begin(), q.end(), j + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - q.begin();
				if (idx < q.size())
					dp[i][j] = min(dp[i][j], q[idx].second + 1);
				idx = lower_bound(st.begin(), st.end(), i + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - st.begin();
				if (idx < st.size())dp[i][j] = min(dp[i][j], st[idx].second + 1);
			}
		}
		/*
		for (int i = n; i >= 1; i--) {
			std::vector<pair<int, int>>q;//本行的单调栈
			for (int j = m; j >= 1; j--) {
				auto &st = col[j];
				int v = g[i][j];
				auto idx = lower_bound(q.begin(), q.end(), j + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - q.begin();
				if (idx < q.size())
					dp[i][j] = min(dp[i][j], q[idx].second + 1);
				idx = lower_bound(st.begin(), st.end(), i + v, [&](pair<int, int>s, int t)->bool{
					return s.first > t;
				}) - st.begin();
				if (idx < st.size())dp[i][j] = min(dp[i][j], st[idx].second + 1);
				while (q.size() and q.back().second >= dp[i][j])q.pop_back();
				q.push_back({j, dp[i][j]});
				while (st.size() and st.back().second >= dp[i][j])st.pop_back();
				st.push_back({i, dp[i][j]});
			}
		}
		*/
		//也可以先维护值, 再加入栈, 避免越界
		if (dp[1][1] == 0x3f3f3f3f)return -1;
		return dp[1][1];
	}
};



