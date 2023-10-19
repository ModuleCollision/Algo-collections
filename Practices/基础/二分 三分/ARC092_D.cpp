#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>A(n + 5, 0), B(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	for (ll j = 1; j <= n; j++)cin >> B[j];
	ll ans = 0;
	vector<ll>a(n + 5), b(n + 5);
	for (ll i = 0; i <= 28; i++) {
		ll msk = (1 << (i + 1));
		for (ll j = 1; j <= n; j++)a[j] = A[j] % msk;
		for (ll j = 1; j <= n; j++)b[j] = B[j] % msk;
		sort(a.begin() + 1, a.begin() + 1 + n);
		sort(b.begin() + 1, b.begin() + 1 + n);
		ll cnt = 0;
		ll l1 = (1 << i), r1 = (1 << (i + 1)) - 1, l2 = (3 << i), r2 = (1 << (i + 2)) - 1;
		for (ll j = 1; j <= n; j++) {
			ll idx1 = lower_bound(b.begin() + 1, b.begin() + 1 + n, l1 - a[j]) - b.begin();
			ll idx2 = upper_bound(b.begin() + 1, b.begin() + 1 + n, r1 - a[j]) - b.begin();
			ll idx3 = lower_bound(b.begin() + 1, b.begin() + 1 + n, l2 - a[j]) - b.begin();
			ll idx4 = upper_bound(b.begin() + 1, b.begin() + 1 + n, r2 - a[j]) - b.begin();
			cnt += idx2 - idx1 + idx4 - idx3;
		}
		if (cnt & 1)ans |= (1 << i);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}