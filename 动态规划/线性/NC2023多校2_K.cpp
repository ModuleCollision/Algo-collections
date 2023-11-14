#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0), B(n + 5, 0);
	vector<ll>pos;
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll i = 1; i <= n; i++) {
		std::cin >> B[i]; if (B[i] == 1)pos.push_back(i);
	}
	vector dp(n + 5, vector<ll>(10, 0));
	if (pos[0] != 1) {
		dp[0][0] = A[pos[0] - 1];
	}
	dp[0][1] = A[pos[0]]; dp[0][2] = A[pos[0] + 1];
	for (ll i = 1; i < pos.size(); i++) {
		ll j = pos[i]; ll k = pos[i - 1];
		if (j - k >= 3) {
			dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j - 1];
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j];
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j + 1];
		} else if (j - k == 1) {
			dp[i][0] = dp[i - 1][0] + A[j - 1];
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][1]}) + A[j];
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j + 1];
		} else if (j - k == 2) {
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + A[j - 1];
			dp[i][1] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j];
			dp[i][2] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + A[j + 1];
		}
	}
	ll ans = 0;
	for (ll i = 0; i < pos.size(); i++) {
		ans = max({dp[i][0], dp[i][1], dp[i][2]});
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
