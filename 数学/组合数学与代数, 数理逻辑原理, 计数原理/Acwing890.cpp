#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m; std::cin >> n >> m; ll ans = 0;
	vector<ll>w(m + 5, 0); for (ll i = 0; i < m; i++)cin >> w[i];
	for (ll i = 1; i < (1 << m); i++) {
		ll k = 1; ll cnt = 0; bool f = 1;
		for (ll j = 0; j < m; j++) {
			if ((i >> j) & 1) {
				if (k * w[j] > n) {
					f = 0; break;
				}
				cnt++; k *= w[j];
			}
		}
		if (f) {
			ll res = n / k;
			if (cnt & 1)ans += res;
			else ans -= res;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}