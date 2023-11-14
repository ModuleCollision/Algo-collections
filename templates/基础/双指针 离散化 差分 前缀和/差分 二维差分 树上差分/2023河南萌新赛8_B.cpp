#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll d1[maxn], d2[maxn];
void solve() {
	ll n; std::cin >> n;
	for (ll i = 1; i <= n; i++) {
		ll l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		++d1[l1]; --d1[r1 + 1];
		++d1[l2]; --d1[r2 + 1];
		ll l = max(l1, l2); ll r = min(r1, r2);
		if (l <= r) {
			++d2[min(l1, l2)];
			--d2[max(r1, r2) + 1];
		} else {
			++d2[l1]; --d2[r1 + 1];
			++d2[l2]; --d2[r2 + 1];
		}
	}
	auto ksm = [&](ll a, ll b) {
		ll ret = 1;
		while (b) {
			if (b & 1)ret = ret * a % mod;
			a = a * a % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	ll ans = 0;
	for (ll i = 1; i <= 5e5; i++) {
		d1[i] += d1[i - 1];
		d2[i] += d2[i - 1];
	}
	for (ll i = 1; i <= 5e5; i++) {
		if (d2[i] == n) {
			ans = (ans % mod + ksm(2, d1[i] - n)) % mod;
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}