/*此题我们运用枚举+预处理数组解决*/
/*动态规划+预处理*/
class Solution {
public:
	typedef long long ll;
	const ll mod = 1e9 + 7;
	int countPalindromes(string s) {
		ll n = s.size();
		ll suf[n + 2][10], dp1[n + 2][10][10];
		ll pre[n + 2][10], dp2[n + 2][10][10];//c统计某一位上某一字符前缀和
		//f统计某两字符的组合数
		memset(pre, 0, sizeof(pre));
		memset(suf, 0, sizeof(suf));
		memset(dp1, 0, sizeof(dp1));
		memset(dp2, 0, sizeof(dp2));
		for (ll i = 1; i <= n; i++) {
			ll x = s[i - 1] - '0';
			for (ll j = 0; j <= 9; j++) {
				pre[i][j] += pre[i - 1][j] % mod;
			}
			pre[i][x]++;
			for (ll j = 0; j <= 9; j++) {
				for (ll k = 0; k <= 9; k++) {
					dp1[i][j][k] = dp1[i - 1][j][k];
				}
			}
			for (ll k = 0; k <= 9; k++) {
				dp1[i][k][x] = (dp1[i][k][x] % mod + pre[i - 1][k]) % mod;
			}
		}


		for (ll i = n; i >= 1; i--) {
			ll x = s[i - 1] - '0';
			for (ll j = 0; j <= 9; j++) {
				suf[i][j] += suf[i + 1][j];
			}
			suf[i][x]++;
			for (ll j = 0; j <= 9; j++) {
				for (ll k = 0; k <= 9; k++) {
					dp2[i][j][k] += dp2[i + 1][j][k];
				}
			}
			for (ll k = 0; k <= 9; k++) {
				dp2[i][x][k] = (dp2[i][x][k] % mod + suf[i + 1][k]) % mod;
			}
		}
		ll ans = 0;
		for (ll i = 1; i <= n; i++) {
			ll x = (s[i - 1] - '0');
			for (ll j = 0; j <= 9; j++) {
				for (ll k = 0; k <= 9; k++) {
					ans = (ans % mod + dp1[i - 1][j][k] % mod * dp2[i + 1][k][j]) % mod;
				}
			}
		}
		return ans;
	}
};

