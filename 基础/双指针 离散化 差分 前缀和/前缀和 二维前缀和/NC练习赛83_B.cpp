#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
/*bool cal(ll x) {
	ll cnt = 0;
	for (ll i = 0; i <= 33; i++) {
		if ((x >> i) & 1)cnt++;
	}
	return cnt & 1;
}
void solve(ll x) {
	ll ans = 0;
	for (ll i = 1; i <= x; i++) {
		if (cal(i))ans++;
	}
	cout << x << ":" << ans << endl;
}*/
//打表
void solve() {
	auto get = [&](ll x) {
		if (x & 1) {
			return x / 2 + 1;
		} else {
			ll cnt = 0;
			for (ll i = 0; i <= 33; i++) {
				if ((x >> i) & 1)cnt++;
			}
			if (cnt & 1) {
				return x / 2 + 1;
			} else {
				return x / 2;
			}
		}
	};
	ll l, r; std::cin >> l >> r;
	cout << get(r) - get(l - 1) << endl;
}
signed main() {
	ll T;std::cin>>T;
	while(T--)
	solve();
}