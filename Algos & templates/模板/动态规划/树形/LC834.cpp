
/*利用了换根dp的思想,避免了重复做dp*/
class Solution {
public:

	vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
		vector<int>tr[n + 5];
		for (int i = 0; i < n; i++)tr[i].clear();
		for (auto c : edges) {
			int a = c[0], b = c[1];
			tr[a].push_back(b);
			tr[b].push_back(a);
		}
		vector<int>dp(n + 5, 0), siz(n + 5);
		function<void(int, int)>dfs = [&](int u, int f) {
			siz[u] = 1;
			for (auto v : tr[u]) {
				if (v == f)continue;
				dfs(v, u);
				dp[u] += dp[v] + siz[v];
				siz[u] += siz[v];
			}
		};
		dfs(0, -1);
		vector<int>ans(n);
		function<void(int, int)>tarjan = [&](int u, int f) {
			ans[u] = dp[u];
			for (auto v : tr[u]) {
				if (v == f)continue;
				int pu = dp[u], pv = dp[v];
				int su = siz[u], sv = siz[v];
				dp[u] -= dp[v] + siz[v];
				siz[u] -= siz[v];
				dp[v] += dp[u] + siz[u];//转移之前处理出以v为根的u的dp值以及v的dp值
				siz[v] += siz[u];
				tarjan(v, u);
				dp[u] = pu; dp[v] = pv;
				siz[u] = su, siz[v] = sv;//结束之后还原
			}
		};
		//dfs(0, 0);
		tarjan(0, -1);
		return ans;
	}
};