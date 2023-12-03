#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll dp[60005];
bool check(ll x) {
	ll t = (ll)sqrt(x);
	return (t * t) == x;
}
void pre() {
	dp[1] = 1;
	for (ll i = 2; i <= 60000; i++) {
		dp[i] += dp[i - 1];
		if (check(i)) dp[i] += dp[(ll)sqrt(i)];
	}
}

signed main() {
	ll T; std::cin >> T; pre();
	while (T--) {
		ll n; cin >> n; ll m = (ll)sqrt(n);
		ll ans = 0; if (m * m > n)m--;
		for (ll i = 1; i * i <= m; i++) {
			ans += dp[i] * (m - i * i + 1);
		}
		cout << ans << endl;
	}

}