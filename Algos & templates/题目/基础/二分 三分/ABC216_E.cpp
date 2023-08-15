#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, k; std::cin >> n >> k;
	vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	auto check = [&](ll x) {
		ll cnt = 0;
		for (ll i = 1; i <= n; i++) {
			cnt += max(A[i] - x, 0ll);
		}
		return cnt <= k;
	};
	ll l = 0, r = *max_element(A.begin() + 1, A.begin() + 1 + n);
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (check(mid))r = mid;
		else l = mid + 1;
	}
	ll ans = 0;
	ll cnt = 0;
	for (ll i = 1; i <= n; i++) {
		if (A[i] < r)continue;
		ans += ((r + 1 + A[i]) * (A[i] - r)) / 2;
		cnt += max(0ll, A[i] - r);
	}
	ans += (k - cnt) * (r);
	cout << ans << endl;
}
signed main() {
	solve();
}