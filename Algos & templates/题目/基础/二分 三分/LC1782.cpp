class Solution {
public:
	vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
		std::map<pair<int, int>, int>cnt;
		vector<int>d(n + 5, 0);
		for (auto k : edges) {
			int x = k[0], y = k[1];
			if (x > y)swap(x, y);
			cnt[ {x, y}]++;
			d[x]++; d[y]++;
		}
		auto deg = d;
		std::sort(deg.begin() + 1, deg.begin() + 1 + n, [&](int x, int y)->bool{
			return x < y;
		});
		int m = queries.size();
		vector<int>ans(m);
		for (int i = 0; i < m; i++) {
			int q = queries[i];
			for (int j = 1; j <= n; j++) {
				int idx = upper_bound(deg.begin() + j + 1, deg.begin() + 1 + n, q - deg[j]) - deg.begin();
				ans[i] += n - idx + 1;
			}
			for (auto [s, c] : cnt) {
				auto [x, y] = s;
				if (d[x] + d[y] > q and d[x] + d[y] - c <= q) {
					ans[i]--;
				}
			}
		}
		return ans;
	}
};