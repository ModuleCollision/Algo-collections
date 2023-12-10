#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll w, f; std::cin >> w >> f;
	ll n; std::cin >> n; vector<ll>s(n + 5, 0);
	ll sum = 0;
	for (ll i = 1; i <= n; i++)cin >> s[i], sum += s[i];
	auto check = [&](ll se) {
		ll x = max(se * w, se * f);
		ll y = min(se * w, se * f);
		vector<ll>dp(y + 5, 0);
		if (x >= sum or y >= sum)return true;
		ll mx1 = 0;
		/*0 1 背包一维*/
		for (ll i = 1; i <= n; i++) {
			for (ll j = y; j >= s[i]; j--) {
				dp[j] = max(dp[j], dp[j - s[i]] + s[i]);
				mx1 = max(mx1, dp[j]);
			}
		}
		return mx1 + x >= sum;
	};
	ll l = 1, r = (ll)(1e6 + 5); ll ans = 0;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		}
		else l = mid + 1;
	}
	cout << r << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}