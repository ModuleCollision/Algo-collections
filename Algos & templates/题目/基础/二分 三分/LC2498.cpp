class Solution {
public:
	int maxJump(vector<int>& stones) {
		int n = stones.size();
		auto check = [&](int mid) {
			vector<bool>vis(n + 1, false);
			for (int i = 1; i < n; i++) {
				if (stones[i] - stones[i - 1] > mid)return false;
			}
			for (int st = 0; st < n - 1;) {
				int ed = st + 1;
				while (ed < n and stones[ed] - stones[st] <= mid)++ed;
				--ed;
				vis[ed] = true;
				st = ed;
			}
			vis[0] = false; vis[n - 1] = false;
			for (int i = 0; i < n - 1;) {
				int j = i + 1;
				while (j < n and vis[j] == true)j++;
				if (stones[j] - stones[i] > mid)return false;
				i = j;
			}
			return true;
		};
		int l = 0, r = 1e9;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (check(mid))r = mid;
			else l = mid + 1;
		}
		return l;
	}
};