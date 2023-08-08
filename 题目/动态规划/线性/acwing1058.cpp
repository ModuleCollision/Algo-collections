#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n; vector dp(n + 5, vector<ll>(3, -inf));
	vector<ll>A(n + 5, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
	dp[0][0] = 0;//1卖出, 0 空仓, 2 持仓
	for (ll i = 1; i <= n; i++) {
		if (dp[i - 1][1] != -inf)
			dp[i][0] = max(dp[i][0], dp[i - 1][1]);
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		if (dp[i - 1][2] != -inf)
			dp[i][1] = max(dp[i][1], dp[i - 1][2] + A[i]);
		if (dp[i - 1][2] != -inf)
			dp[i][2] = max(dp[i][2], dp[i - 1][2]);
		if (dp[i - 1][0] != -inf)
			dp[i][2] = max(dp[i][2], dp[i - 1][0] - A[i]);
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}
signed main() {
	solve();
}