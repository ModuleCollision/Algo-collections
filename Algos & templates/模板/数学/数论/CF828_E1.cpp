#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll a, b, c, d; std::cin >> a >> b >> c >> d;
	function<ll(ll, ll)>gcd = [&](ll a, ll b) {
		return b == 0 ? a : gcd(b, a % b);
	};
	for (ll i = a + 1; i <= c; i++) {
		ll x = i;
		ll k = a * b / gcd(a * b, x);
		ll s; if (d % k == 0)s = d;
		else s = d / k * k;
		if (s > b) {
			cout << x << " " << s << endl; return;
		}
	}
	puts("-1 -1"); return;
}
signed main() {
	ll T; std::cin >> T;
	while (T--) {
		solve();
	}
}