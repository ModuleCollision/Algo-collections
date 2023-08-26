class Solution {
public:
	typedef long long ll;
	const ll mod = 1e9 + 7;
	int colorTheGrid(int m, int n) {
		int tot = 0;
		vector<vector<int>>f(66);
		vector<int>t(m + 5);
		function<void(int)>dfs = [&](int idx) {
			if (idx == m + 1) {
				f[++tot] = t;
				return;
			}
			for (int i = 1; i <= 3; i++) {
				if (i != t[idx - 1]) {
					t[idx] = i;
					dfs(idx + 1);
				}
			}
		};
		dfs(1);
		vector dp(n + 5, vector<ll>(tot + 5, 0));
		for (int i = 1; i <= tot; i++)dp[1][i] = 1;
		auto check = [&](int i, int j) {
			for (int k = 1; k <= m; k++) {
				if (f[i][k] == f[j][k])return false;
			}
			return true;
		};
		for (int i = 2; i <= n; i++) {
			for (int k = 1; k <= tot; k++) {
				for (int s = 1; s <= tot; s++) {
					if (check(s, k))dp[i][k] = (dp[i][k] % mod + dp[i - 1][s]) % mod;
				}
			}
		}
		ll ans = 0;
		for (ll i = 1; i <= tot; i++)ans = (ans % mod + dp[n][i]) % mod;
		return ans;
	}
};