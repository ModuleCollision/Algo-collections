#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll x; std::cin >> x; ll s = x;
	string xx = "";
	while (s) {
		xx += ('0' + (s % 10));
		s /= 10;
	}
	reverse(xx.begin(), xx.end());
	auto ksm = [&](ll a, ll b) {
		ll ret = 1;
		while (b) {
			if (b & 1)ret = ret * a;
			a = a * a;
			b >>= 1;
		}
		return ret;
	};
	for (ll k = x, cnt = 0; k <= 1e18; k *= 10, cnt++) {
		ll f = (k + (10, cnt));
		ll k1 = sqrt(k); ll k2 = sqrt(f);
		for (ll j = k1; j <= (k2 + 1); j++) {
			ll w = j * j;
			string tmp = "";
			while (w) {
				tmp += ('0' + (w % 10));
				w /= 10;
			}
			reverse(tmp.begin(), tmp.end());
			if (tmp.substr(0, xx.length()) == xx) {
				cout << j << endl; return;
			}
		}
	}
	puts("-1"); return;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}