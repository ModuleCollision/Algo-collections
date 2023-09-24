#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>dp(n + 5, 0), a(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> a[i];
	vector<vector<ll>>p(n + 1);
	for (ll i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1]);//不选择该区间
		for (auto c : p[a[i]]) {//从前置状态转移
			dp[i] = max(dp[i], dp[c - 1] + i - c + 1);
		}
		p[a[i]].push_back(i);
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++)ans = max(ans, dp[i]);
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}