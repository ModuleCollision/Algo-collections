class Solution {
public:
	int maxCount(vector<int>& banned, int n, int maxSum) {
		int f = banned.size();
		std::unordered_set<int>st;
		for (auto c : banned) {
			st.insert(c);
		}
		auto check = [&](int mid) {
			if (mid > n)return false;
			int cnt = 0, sum = 0;
			for (int i = 1; i <= n; i++) {
				if (not st.count(i)) {
					cnt++; sum += i;
				}
				if (cnt == mid)break;
			}
			if (cnt < mid)return false;
			if (sum > maxSum)return false;
			return true;
		};
		int l = 0, r = 1e9;
		while (l < r) {
			int mid = (l + r + 1) >> 1;
			if (check(mid))l = mid;
			else r = mid - 1;
		}
		return l;
	}
};