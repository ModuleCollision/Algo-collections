class Solution {
public:
	typedef long long ll;
	const ll mod = 1e9 + 7;
	int numberOfWays(int n, int x) {
		vector<ll>p(n + 5, 0);
		ll tot = 0;
		for (ll i = 1; i <= n; i++) {
			ll cur = 1; bool f = 1;
			for (ll j = 1; j <= x; j++) {
				cur *= i; if (cur > n) {
					f = 0; break;
				}
			}
			if (not f)break;
			else p[++tot] = cur;
		}
		vector dp(tot + 5, vector<ll>(n + 5, 0)); dp[0][0] = 1;
		for (ll i = 1; i <= tot; i++) {
			for (ll j = 0; j <= n; j++) {
				dp[i][j] += dp[i - 1][j] % mod;
				if (j >= p[i])dp[i][j] += dp[i - 1][j - p[i]] % mod;
				dp[i][j] %= mod;
			}
		}
		return dp[tot][n] % mod;
	}
};