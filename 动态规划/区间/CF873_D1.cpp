#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n; ll ans = 0;
	ll dp[n + 5][n + 5];
	vector<ll>a(n + 5, 0);
	for (ll i = 1; i <= n; i++)std::cin >> a[i];
	memset(dp, 0, sizeof(dp));
	for (ll len = 1; len <= n; len++) {
		for (ll i = 1; i + len - 1 <= n; i++) {
			ll j = i + len - 1;
			if (len == 1) {
				dp[i][j] = 0;
			}
			else if (a[i] < a[j]) {
				dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
			} else {
				dp[i][j] = j - i;
			}
			ans += dp[i][j];
		}
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}