#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; string s; std::cin >> n >> s;
	s = " " + s;
	vector dp(n + 5, vector((1 << 11), vector<ll>(11, 0)));
	ll pre = s[1] - 'A';
	dp[1][(1 << pre)][pre] = 1;
	for (ll i = 2; i <= n; i++) {
		for (ll j = 0; j <= (1 << 10) - 1; j++) {
			for (ll k = 0; k <= 9; k++)dp[i][j][k] = (dp[i][j][k] % mod + dp[i - 1][j][k]) % mod;
		}
		ll pre = s[i] - 'A';
		for (ll j = 0; j <= (1 << 10) - 1; j++) {
			if ((j >> pre) & 1) {
				dp[i][j][pre] = (dp[i][j][pre] % mod + dp[i - 1][j][pre]) % mod;
				for (ll w = 0; w <= 9; w++) {
					if ((j >> w) & 1) {
						dp[i][j][pre] = (dp[i][j][pre] % mod + dp[i - 1][j - (1 << pre)][w]) % mod;
					}
				}
			}
		}
		dp[i][(1 << pre)][pre] += 1; dp[i][1 << pre][pre] %= mod;
	}
	ll ans = 0; for (ll j = 0; j <= (1 << 10) - 1; j++)for (ll k = 0; k <= 9; k++)ans = (ans % mod + dp[n][j][k]) % mod;
	cout << ans << endl;
}
signed main() {
	solve();
}