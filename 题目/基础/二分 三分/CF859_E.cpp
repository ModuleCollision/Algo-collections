#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n;
void solve() {
	std::cin >> n;
	vector<ll>pre(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		std::cin >> pre[i];
		pre[i] += pre[i - 1];
	}
	ll l = 1, r = n, ans;
	while (l < r) {
		ll mid = (l + r) >> 1;
		cout << "? " << (mid - l + 1) << endl;
		for (ll i = l; i <= mid; i++) {
			cout << i << " ";
		}
		cout << endl << flush;
		ll x; std::cin >> x;
		if (x == pre[mid] - pre[l - 1]) {
			l = mid + 1;
		} else {
			r = mid - 1; ans = mid;
		}
	}
	cout << "! " << ans << endl << flush;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}