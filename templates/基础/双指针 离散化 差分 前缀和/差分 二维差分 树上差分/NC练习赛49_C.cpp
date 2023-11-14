#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll opt; ll l; ll r;
};
void solve() {
	ll n, m; cin >> n >> m;
	vector<sq>q(m + 5);
	vector<ll>d1(m + 5, 0), d2(n + 5, 0);
	vector<ll>l(m + 5, 0), r(m + 5, 0);
	for (ll i = 1; i <= m; i++) {
		cin >> q[i].opt >> q[i].l >> q[i].r;
		l[i] = q[i].l;
		r[i] = q[i].r;
	}
	for (ll i = m; i >= 1; i--) {
		d1[i] = (d1[i] % mod + d1[i + 1]) % mod;
		if (q[i].opt == 1) {
			d2[l[i]] = (d2[l[i]] % mod + d1[i] + 1) % mod;
			d2[r[i] + 1] = ((d2[r[i] + 1] % mod - (d1[i] + 1)) % mod + mod) % mod;
		} else {
			d1[r[i]] = (d1[r[i]] % mod + d1[i] + 1) % mod;
			d1[l[i] - 1] = ((d1[l[i] - 1] - d1[i] - 1) % mod + mod) % mod;
		}
	}
	for (ll i = 1; i <= n; i++) {
		d2[i] += d2[i - 1];
		d2[i] %= mod;
		cout << d2[i] % mod << " ";
	}
	cout << endl;
}
signed  main() {
	solve();
}




