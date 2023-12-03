#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	vector<ll>a(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	vector<vector<ll>>dp(n + 5, vector<ll>(4, -inf));
	dp[0][1] = dp[0][0] = 0;
	for (ll i = 1; i <= n; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + a[i]);
		dp[i][0] = max(dp[i][0], dp[i - 1][1] - a[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][0] - a[i]);
		dp[i][1] = max(dp[i][1], dp[i - 1][1] + a[i]);
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}
ll T;
signed main() {
	std::cin >> T;
	while (T--)solve();
}