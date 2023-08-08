#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, k, m, a, b;
	std::cin >> n >> k >> m >> a >> b;
	ll ans = 1e15; bool f = 0;
	ll v = 0;
	if (k == 1) {
		if (n % m) {
			cout << -1 << endl;
		} else {
			cout << 0 << endl;
		}
		return;
	}
	for (ll s = n;; s /= k) {
		ll tmp = 0; ll ct = 0;
		for (ll ts = s; ts <= 1e18; ts *= k, ct += 1) {
			ll d = tmp;
			ll l = ts, r = ts + d;
			ll p = (l + m - 1) / m * m;
			if (p <= r) {
				f = 1;
				ans = min(ans, ct * a + v);
				break;
			}
			p = (r / m) * m;
			if (p >= l) {
				f = 1; ans = min(ans, ct * a + v);
				break;
			}
			tmp = (tmp) * k + k - 1;
		}
		if (not s)break;
		v += b;
	}
	if (not f) {
		puts("-1"); return;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}