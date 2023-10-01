/*出度为 1 的序列形成内向基环树*/
class Solution {
public:
	vector<int> countVisitedNodes(vector<int>& edges) {
		int n = edges.size();
		vector<vector<int>>g(n + 1); vector<int>d(n + 1);
		for (int i = 0; i < n; i++) {
			int u = i + 1, v = edges[i] + 1;
			g[v].push_back(u), d[v]++;
		}
		queue<int>q; vector<bool>vis(n + 1);
		for (int i = 1; i <= n; i++) {
			if (not d[i])q.push(i), vis[i] = 1;
		}
		while (q.size()) {
			auto u = q.front(); q.pop();
			int nxt = edges[u - 1] + 1;
			d[nxt]--;
			if (not d[nxt]) {
				q.push(nxt); vis[nxt] = 1;
			}
		}
		int sz = 0; for (int i = 1; i <= n; i++)if (not vis[i])sz++;
		vector<int>ans(n, 0);
		auto bfs = [&](int u, int le) {
			queue<int>q;
			q.push(u); ans[u - 1] = le;
			while (q.size()) {
				auto cur = q.front(); q.pop();
				for (auto v : g[cur]) {
					if (not vis[v])continue;
					ans[v - 1] = ans[cur - 1] + 1;
					q.push(v);
				}
			}
		};
		for (int i = 1; i <= n; i++) {
			if (not vis[i]) {
				vector<int>r;
				int cur = i; r.push_back(i);
				while (1) {
					cur = edges[cur - 1] + 1;
					if (cur == i)break; r.push_back(cur);
				}
				for (auto x : r)bfs(x, r.size());
			}
		}
		return ans;
	}
};