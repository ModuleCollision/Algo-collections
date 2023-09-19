/*子数组，异或，布尔值dp*/
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n; vector<ll>A(n + 1, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector dp(n + 1, vector<bool>(n + 1, false));
	dp[0][0] = 1;
	for (ll i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		vector<bool>v(n + 1, false); ll mex = 0;
		vector vis(i + 1, vector<bool>(n + 1, false));
		for (ll j = i; j >= 1; j--) {
			v[A[j]] = 1; while (v[mex])mex++;
			if (vis[j][mex])continue; vis[j][mex] = 1;
			for (ll k = 0; k <= j; k++) {
				if (dp[j - 1][k])dp[i][k ^ mex] = 1;
			}
		}
	}
	ll ans = 0; for (ll k = 0; k <= n; k++)if (dp[n][k])ans = max(ans, k);
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}