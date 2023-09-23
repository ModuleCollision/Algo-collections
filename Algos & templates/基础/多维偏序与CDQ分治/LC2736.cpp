/*经典二维偏序问题,用排序 + 数据结构解决*/
class Solution {
public:
	vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
		int n = nums1.size();
		int q = queries.size();
		vector<array<int, 3>>pr;
		for (int i = 0; i < n; i++) {
			pr.push_back({nums1[i], nums2[i], -(nums1[i] + nums2[i])});
		}
		for (int i = 0; i < q; i++) {
			pr.push_back({queries[i][0], queries[i][1], i});
		}
		std::sort(pr.begin(), pr.end(), [&](auto a, auto b)->bool{
			if (a[0] != b[0])return a[0] >= b[0];
			if (a[1] != b[1])return a[1] >= b[1];
			return a[2] <= b[2];
		});
		std::vector<int>sq; std::unordered_map<int, int>ks;
		for (auto s : pr) {
			sq.push_back(s[1]);
		}
		std::sort(sq.begin(), sq.end());
		sq.erase(unique(sq.begin(), sq.end()), sq.end());
		for (int i = 0; i < sq.size(); i++) {
			ks[sq[i]] = sq.size() - i;
		}
		vector<int>ans(q); vector<int>tr(n + q + 1, 0);
		auto add = [&](int idx, int v) {
			for (; idx <= n + q; idx += (idx & -idx))tr[idx] = max(tr[idx], v);
		};
		auto query = [&](int idx) {
			int ret = 0;
			for (; idx >= 1; idx -= (idx & -idx))ret = max(ret, tr[idx]);
			return ret;
		};
		for (int i = 0; i < n + q; i++) {
			if (pr[i][2] < 0) {
				add(ks[pr[i][1]], -pr[i][2]);
			} else ans[pr[i][2]] = query(ks[pr[i][1]]);
		}
		for (auto &f : ans) {
			if (not f)f = -1;
		}
		return ans;
	}
};