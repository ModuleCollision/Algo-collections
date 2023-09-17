class Solution {
public:
	typedef long long ll;
	bool isMatch(string s, string p) {
		int n = s.size(), m = p.size();
		bool dp[n + 5][m + 5];
		memset(dp, false, sizeof(dp));
		s = " " + s; p = " " + p;
		dp[0][0] = true;
		for (int i = 1; i <= m; i++) {
			if (p[i] == '*' and i >= 2)dp[0][i] |= dp[0][i - 2];
		}
		for (ll i = 1; i <= n; i++) {
			for (ll j = 1; j <= m; j++) {
				if ((isalpha(p[j]) and p[j] == s[i]) or p[j] == '.')dp[i][j] |= dp[i - 1][j - 1];
				else {
					if (p[j - 1] == '.') {
						for (ll k = i; k >= 0; k--)dp[i][j] |= dp[k][j - 2];
					} else {
						ll k = i; while (s[k] == p[j - 1] and k >= 1)k--;
						if (j > 1)
							for (ll w = i; w >= k; w--)dp[i][j] |= dp[w][j - 2];
					}
				}
			}
		}
		return dp[n][m];
	}
};