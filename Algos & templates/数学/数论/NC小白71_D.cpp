/*结论,gcd(a, b) = gcd(a, b - a), a < b*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll a, b;
	function<ll(ll, ll)> gcd = [&](ll x, ll y) {
		return y == 0 ? x : gcd(y, x % y);
	};
	std::cin >> a >> b;
	if (a == b and a != 1) {
		puts("0"); return;
	} else if (gcd(a, b) > 1) {
		puts("0"); return;
	} else if (a == 1 and b == 1) {
		puts("1"); return;
	}
	if (a > b) {
		swap(a, b);
	}
	ll d = b - a;
	vector<ll>p;
	for (ll i = 1; i * i <= d; i++) {
		if (d % i == 0) {
			p.push_back(i);
			if (d / i != i) {
				p.push_back(d / i);
			}
		}
	}
	ll ans = inf;
	for (auto c : p) {
		if (c != 1)
			ans = min(ans, (a + c - 1) / c * c - a);
	}
	if (ans == inf) {
		puts("-1"); return;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}