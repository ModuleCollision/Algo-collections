#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>A(n + 1, 0);
	for (ll i = 1; i <= n; i++) cin >> A[i];
	auto check = [&](ll x) {
		for (ll i = 1; i <= n; i++) {
			ll cur = k, h = x;
			for (ll j = i; j <= n; j++, h--) {
				if (h <= A[j])return true;
				cur -= h - A[j];
				if (cur < 0)break;
			}
		}
		return false;
	};
	ll l = *max_element(A.begin() + 1, A.begin() + 1 + n);
	ll r = 1e10; ll ans = l;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1; ans = mid;
		} else r = mid - 1;
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}