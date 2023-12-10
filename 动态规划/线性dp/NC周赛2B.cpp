#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; cin >> n; vector<ll>A(n + 5, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
	vector dp(n + 5, vector<ll>(2, 0));
	std::string s; cin >> s; s = " " + s;
	for (ll i = 2; i <= n; i++) {
		if (s[i] != s[i - 1]) {
			dp[i][1] = max(dp[i][1], dp[i - 2][1] + A[i - 1] + A[i]);
			dp[i][1] = max(dp[i][1], dp[i - 2][0] + A[i - 1] + A[i]);
		}
		dp[i][0] = max(dp[i][0], dp[i - 1][1]);
		dp[i][0] = max(dp[i][0], dp[i - 1][0]);
	}
	cout << max(dp[n][0], dp[n][1]) << endl;
}
signed main() {
	solve();
}