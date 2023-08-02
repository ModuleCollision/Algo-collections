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
	vector<ll>A(n + 5, 0);
	ll c, d; std::cin >> c >> d;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i];
	}
	std::sort(A.begin() + 1, A.begin() + 1 + n, [&](ll x, ll y)->bool{
		return x > y;
	});
	for (ll i = 1; i <= n; i++) {
		A[i] += A[i - 1];
	}
	if (A[min(d, n)] >= c) {
		puts("Infinity"); return;
	}
	ll l = 1, r = 1e12;
	auto check = [&](ll mid) {
		ll ret = 0;
		ll rc = min(n, mid);
		ret += d / mid * A[rc];
		ll re = d % mid;
		rc = min(re, n);
		ret += A[rc];
		return ret >= c;
	};
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (check(mid)) {
			l = mid + 1; ans = mid;
		} else {
			r = mid - 1;
		}
	}
	/*while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}*/
	//两种二分都要写
	if (not ans) {
		puts("Impossible"); return;
	}
	cout << ans - 1 << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)solve();
}
