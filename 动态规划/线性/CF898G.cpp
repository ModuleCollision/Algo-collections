#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	string s; std::cin >> s; ll n = s.size();
	s = " " + s;
	vector dp(n + 1, vector<ll>(2, -inf));
	vector<ll>pos(n + 1); ll cnt = 0; ll l1 = 0, l2 = 0;
	for (ll i = 1; i <= n; i++) {
		if (s[i] == 'B')pos[++cnt] = i, l1++;
		else l2++;
	}
	if (not l1 or not l2) {
		puts("0"); return;
	}
	ll ans = 0;
	pos[++cnt] = n + 1; dp[0][0] = dp[0][1] = 0;
	for (ll i = 1; i <= cnt - 1; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + pos[i] - pos[i - 1] - 1);
		dp[i][0] = max(dp[i][0], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + pos[i + 1] - pos[i] - 1;
		ans = max({ans, dp[i][0], dp[i][1]});
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}