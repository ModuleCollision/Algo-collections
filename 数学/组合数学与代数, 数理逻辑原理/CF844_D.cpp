#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n; std::cin >> n;
	ll ans = -inf;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	auto check = [&](ll x) {
		ll cnt = 0;
		for (ll i = 1; i <= n; i++) {
			ll s = (ll)sqrt(A[i] + x);
			if (s * s == A[i] + x) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	};
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	for (ll i = 1; i <= n; i++) {
		for (ll j = i + 1; j <= n; j++) {
			ll k = A[j] - A[i];
			for (ll s = 1; s * s <= k; s++) {
				if (k % s == 0) {
					ll t = k / s;
					ll q = (t + s);
					if (not(q & 1)) {
						q /= 2; ll p = max(s, t) - q;
						if (q * q >= A[j]) {
							check(q * q - A[j]);
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}