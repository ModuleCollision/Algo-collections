class Solution {
public:
	typedef long long ll;
	const ll mod = 1e9 + 7;
	int checkRecord(int n) {
		ll dp[n + 5][5][3]; memset(dp, 0, sizeof(dp));
		dp[0][0][0] = 1;//前i 天, j次缺勤, 末尾迟到次数为k
		for (ll i = 1; i <= n; i++) {
			for (ll j = 0; j <= 1; j++) {
				for (ll k = 0; k <= 2; k++) {
					if (j >= 1) {
						dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j - 1][k]) % mod;
					}
				}//最后一天是缺勤
			}
			//最后一天是到场
			for (ll j = 0; j <= 1; j++) {
				for (ll k = 0; k <= 2; k++)dp[i][j][0] = (dp[i][j][0] % mod + dp[i - 1][j][k]) % mod;
			}
			//最后一天是迟到
			for (ll k = 0; k <= 2; k++) {
				for (ll j = 0; j <= 1; j++) {
					if (k >= 1)
						dp[i][j][k] = (dp[i][j][k] % mod + dp[i - 1][j][k - 1]) % mod;
				}
			}
		}
		ll ans = 0;
		for (ll j = 0; j <= 1; j++) {
			for (ll k = 0; k <= 2; k++) {
				ans = (ans % mod + dp[n][j][k]) % mod;
			}
		}
		return (int)ans;
	}
};