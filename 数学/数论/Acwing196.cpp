#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e7 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll prime[maxn]; ll cnt = 0;
bool vis[maxn];
void solve() {
	for (ll i = 2; i <= 1e7; i++) {
		if (not vis[i]) {
			prime[++cnt] = i;
		}
		for (ll j = 1; j <= cnt and prime[j]*i <= 1e7; j++) {
			vis[prime[j]*i] = 1;
			if (i % prime[j] == 0)break;
		}
	}
	ll l, r;
	vector<ll>k(1e6 + 5, 0); vector<bool>v(1e6 + 5, false);
	while (cin >> l >> r) {
		std::fill(k.begin(), k.end(), 0);
		std::fill(v.begin(), v.end(), false);
		for (ll i = 1; i <= cnt; i++) {
			ll p = prime[i];
			for (ll j = max(p * 2, (l + p - 1) / p * p); j <= r; j += p) {
				v[j - l] = true;
			}
		}
		ll c = 0;
		for (ll i = 0; i <= r - l; i++) {
			if (not v[i] and i + l >= 2) {
				k[++c] = i + l;
			}
		}
		if (c < 2) {
			puts("There are no adjacent primes."); continue;
		}
		ll midx = 0, madx = 0; ll mind = inf, maxd = -inf;
		for (ll i = 2; i <= c; i++) {
			ll d = k[i] - k[i - 1];
			if (d < mind) {
				mind = d;
				midx = i;
			}
			if (d > maxd) {
				maxd = d;
				madx = i;
			}
		}
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n", k[midx - 1], k[midx], k[madx - 1], k[madx]);
	}
}
signed main() {
	solve();
}