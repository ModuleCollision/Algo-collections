const int maxn = 5e4 + 5;

class TreeAncestor {
public:

	vector<int>tr[maxn];
	int fa[maxn][20]; int dep[maxn];
	void add_edge(int u, int v) {
		tr[u].push_back(v);
		tr[v].push_back(u);
	}
	void dfs(int u, int f) {
		fa[u][0] = f;
		dep[u] = dep[f] + 1;
		for (int i = 1; (1 << i) <= dep[u]; i++) {
			fa[u][i] = fa[fa[u][i - 1]][i - 1];
		}
		for (auto x : tr[u]) {
			if (x == f) {
				continue;
			}
			dfs(x, u);
		}
	}
	TreeAncestor(int n, vector<int>& parent) {
		for (int i = 0; i < n; i++) {
			add_edge(i + 1, parent[i] + 1);
		}
		dfs(1, 0);
	}
	int getKthAncestor(int node, int k) {
		node ++ ;
		if (k > dep[node] - 1)return -1;
		for (int i = log2(k); i >= 0; i--) {
			if ((k >> i) & 1)node = fa[node][i];
		}
		return node - 1;
	}
};

