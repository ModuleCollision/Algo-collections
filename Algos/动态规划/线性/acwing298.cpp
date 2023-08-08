#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const int maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
struct sq {
	ll l, p, s;
};
void solve() {
	ll n, m; std::cin >> n >> m;
	vector<sq>w(m + 5);
	for (ll i = 1; i <= m; i++)cin >> w[i].l >> w[i].p >> w[i].s;
	std::sort(w.begin() + 1, w.begin() + 1 + m, [&](sq a, sq b)->bool{
		return a.s < b.s;
	});
	ll ans = 0;
	vector dp(m + 5, vector<ll>(n + 5, 0));
	for (ll i = 1; i <= m; i++) {
		for (ll j = 0; j <= n; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j >= 1)
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (j - w[i].l < w[i].s and j >= w[i].s) {
				for (ll len = j - w[i].s + 1; j - len + 1 >= 1 and len <= w[i].l; len++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - len] + len * (w[i].p));
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << dp[m][n] << endl;
}
signed main() {
	solve();
}