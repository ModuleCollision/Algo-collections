#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, k; std::cin >> n >> m >> k;
	vector dp(n + 5, vector<ll>(m + 5, 0));
	for (ll i = 1; i <= m; i++)dp[1][i] = 1;
	vector pre(n + 5, vector<ll>(m + 5, 0));
	for (ll i = 1; i <= m; i++)pre[1][i] = (pre[1][i - 1] % mod + dp[1][i]) % mod;
	for (ll i = 2; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			if (j + k <= m) {
				ll v = ((pre[i - 1][m] - pre[i - 1][j + k - 1]) % mod + mod) % mod;
				dp[i][j] = (dp[i][j] % mod + v) % mod;
			}
			if (j - k >= 1) {
				ll v = ((pre[i - 1][j - k] - pre[i - 1][0]) % mod + mod) % mod;
				dp[i][j] = (dp[i][j] % mod + v) % mod;
			}
			pre[i][j] = (pre[i][j - 1] % mod + dp[i][j]) % mod;
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= m; i++)ans = (ans % mod + dp[n][i]) % mod;
	cout << ans % mod << endl;
}
signed main() {
	solve();
}