class Solution {
public:
	int maximumTastiness(vector<int>& price, int K) {
		int n = price.size();
		std::sort(price.begin(), price.end());
		auto check = [&](int mid) {
			int pre = price[0]; int cnt = 1;
			for (int i = 1; i < n; i++) {
				if (price[i] - pre >= mid) {
					cnt++;
					pre = price[i];
				}
			}
			return cnt >= K;
		};
		int l = 0, r = 1e9; int ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				l = mid + 1; ans = mid;
			} else {
				r = mid - 1;
			}
		}
		return ans;
	}

};