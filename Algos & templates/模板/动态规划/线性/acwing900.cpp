#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector dp(n + 5, vector<ll>(n + 5, 0));
	dp[0][0] = 1;
	for (ll i = 1; i <= n; i++) {
		for (ll j = n; j >= 0; j--) {
			for (ll k = 0; k * i <= j; k++) {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - k * i]) % mod;
			}
		}
	}
	ll ans = 0;
	cout << dp[n][n] << endl;
}
signed main() {
	solve();
}
