class Solution {
public:
	const int inf = 0x3f3f3f3f;
	int maxIncreasingCells(vector<vector<int>>& mat) {
		int n = mat.size(); int m = mat[0].size();
		vector<int>r(n + 5, -inf), c(m + 5, -inf);
		std::map<int, vector<pair<int, int>>>mp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)mp[mat[i][j]].push_back({i, j});
		}
		int ans = -inf;
		for (auto [x, y] : mp) {
			vector<pair<int, int>>vec, ver;
			for (auto p : y) {
				int t = max({1, r[p.first] + 1, c[p.second] + 1});
				ans = max(ans, t);
				ver.push_back({p.first, t});
				vec.push_back({p.second, t});
			}
			for (auto p : vec) {
				c[p.first] = max(c[p.first], p.second);
			}
			for (auto p : ver) {
				r[p.first] = max(r[p.first], p.second);
			}
		}
		return ans;
	}
};