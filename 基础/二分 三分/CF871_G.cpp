#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
void solve() {
	ll n; std::cin >> n;
	ll l = 0, r = 1e7;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (mid * (mid + 1) / 2 >= n) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	//cout << r << endl;
	ll tot = (1 + r) * r / 2;
	auto sum = [&](ll x) {
		return x * (x + 1) * (2 * x + 1) / 6;
	};
	ll ss = sum(tot);
	ll l1 = n - 1 - (r - 1) * r / 2;
	ll l2 = tot - n;
	ll ans1 = 0, ans2 = 0;
	ll cur = n - 1; ll tmp = r;
	//cout << "#" << l1 << " " << l2 << endl;
	for (ll i = l1; i >= 1; i--) {
		ll len = i;
		ans1 += sum(cur) - sum(cur - len);
		cur -= tmp; tmp--;
	}
	tmp = r; cur = tot;
	for (ll i = l2; i >= 1; i--) {
		ll len = i;
		ans2 += sum(cur) - sum(cur - len);
		cur -= tmp;
		tmp--;
	}
	cout << ss - ans1 - ans2 << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}