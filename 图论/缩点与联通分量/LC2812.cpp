class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int maximumSafenessFactor(vector<vector<int>>& grid) {
		int n = grid.size();
		vector<pair<int, int>>dir = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};
		vector<int>dis(n * n + 5, inf);
		queue<int>q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)if (grid[i][j])q.push(i * n + j), dis[i * n + j] = 0;
		}
		std::map<int, vector<int>>pr;
		auto check = [&](int x, int y) {
			return x >= 0 and x<n and y >= 0 and y < n;
		};
		while (q.size()) {
			auto cur = q.front(); q.pop();
			int x = cur / n, y = cur % n;
			for (auto [dx, dy] : dir) {
				int xx = x + dx, yy = y + dy;
				if (check(xx, yy) and dis[xx * n + yy] == inf) {
					dis[xx * n + yy] = dis[cur] + 1;
					q.push(xx * n + yy);
				}
			}
		}
		int maxd = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int cur = i * n + j;
				pr[dis[cur]].push_back(cur);
				maxd = max(maxd, dis[cur]);
			}
		}
		vector<int>fa(n * n, 0);
		for (int i = 0; i <= n * n - 1; i++) {
			fa[i] = i;
		}
		auto find = [&](int x) {
			while (x != fa[x])x = fa[x] = fa[fa[x]];
			return x;
		};
		for (int d = maxd; d >= 1; d--) {
			auto p = pr[d];
			for (auto s : p) {
				int x = s / n, y = s % n;
				for (auto [dx, dy] : dir) {
					int xx = x + dx, yy = y + dy;
					if (check(xx, yy) and dis[xx * n + yy] >= dis[s]) {
						fa[find(xx * n + yy)] = find(s);
					}
				}
			}
			if (find(0) == find(n * n - 1))return d;
		}
		return 0;
	}
};