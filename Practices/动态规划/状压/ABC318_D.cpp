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
	ll n; std::cin >> n;
	vector w(n + 5, vector<ll>(n + 5, 0));
	for (ll i = 1; i <= n - 1; i++) {
		for (ll j = i + 1; j <= n; j++)cin >> w[i][j];
	}
	vector dp(n + 5, vector<ll>((1 << (n + 1)) + 5, 0));
	for (ll i = 2; i <= n; i++) {
		dp[1][(1 << (i - 1)) + 1] = w[1][i];
	}
	for (ll i = 2; i <= n - 1; i++) {
		for (ll j = 0; j < (1 << n); j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (((j >> (i - 1)) & 1) == 1)continue;
			for (ll k = i + 1; k <= n; k++) {
				if (((j >> (k - 1)) & 1) == 0) {
					dp[i][j + (1 << (k - 1)) + (1 << (i - 1))] = max(dp[i][j + (1 << (k - 1)) + (1 << (i - 1))], dp[i][j] + w[i][k]);
				}
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i < (1 << n); i++) {
		ans = max(ans, dp[n - 1][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


