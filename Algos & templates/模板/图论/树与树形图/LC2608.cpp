/*dfs生成树做法求无向图环*/
class Solution {
public:
	int findShortestCycle(int n, vector<vector<int>>& edges) {
		vector<int>tr[n + 5];
		for (auto k : edges) {
			tr[k[0] + 1].push_back(k[1] + 1);
			tr[k[1] + 1].push_back(k[0] + 1);
		}
		vector<bool>vis(n + 5, false);
		vector<int>dep(n + 5, 0), fa(n + 5, 0);
		int ans = 0x3f3f3f3f;
		function<void(int, int)>dfs = [&](int u, int f) {
			vis[u] = 1;
			for (auto v : tr[u]) {
				if (not vis[v]) {
					fa[v] = u;
					dep[v] = dep[u] + 1;
					dfs(v, u);
				} else if (v != f) {
					if (dep[v] < dep[u]) {
						int tot = 1;
						for (int j = u; j != v; j = fa[j]) {
							tot++;
						}
						ans = min(ans, tot);
					}
				}
			}
		};
		for (int i = 1; i <= n; i++) {
			if (not vis[i])dfs(i, 0);
		}
		if (ans == 0x3f3f3f3f) return -1;
		return ans;
	}
};