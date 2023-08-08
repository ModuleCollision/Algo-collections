class Solution {
public:
	int punishmentNumber(int n) {
		int cur; string s;
		function<bool(int, int, int )>dfs = [&](int udx, int sum, int n) {
			if (udx == n) {
				return sum == cur;
			}
			int c = 0;
			for (int j = udx; j < n; j++) {
				c = (c * 10 + s[j] - '0');
				if (sum + c > cur)break;
				bool f = dfs(j + 1, sum + c, n);
				if (f)return true;
			}
			return false;
		};
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cur = i; s = to_string(cur * cur);
			if (dfs(0, 0, (int)s.size()))ans = ans + i * i;
		}
		return ans;
	}
};