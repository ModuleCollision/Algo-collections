#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<ll>b(m + 5), x(m + 5);
	for (ll i = 1; i <= m; i++)cin >> b[i] >> x[i];
	vector dp(m + 5, vector<ll>(n + 5, inf));
	dp[0][n] = 0;
	for (ll i = 1; i <= m; i++) {
		for (ll j = n; j >= 1; j--) {
			dp[i][j - j % x[i]] = min(dp[i][j - j % x[i]], dp[i - 1][j] + b[i]);
		}
	}
	for (ll i = 1; i < n; i++) {
		if (dp[m][i] != inf) {
			cout << dp[m][i] << endl; return;
		}
	}
}
signed main() {
	solve();
}