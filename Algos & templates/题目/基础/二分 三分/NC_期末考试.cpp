#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll A, B, C; std::cin >> A >> B >> C;
	ll n, m; std::cin >> n >> m;
	vector<ll>t(n + 5, 0); vector<ll>b(m + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> t[i];
	for (ll i = 1; i <= m; i++)cin >> b[i];
	std::sort(b.begin() + 1, b.begin() + 1 + m);
	vector<ll>pre(m + 5, 0);
	for (ll i = 1; i <= m; i++) {
		pre[i] = pre[i - 1] + b[i];
	}
	auto check = [&](ll mid)->ll {
		ll s = 0, p = 0; ll ret = 0;
		ll idx = upper_bound(b.begin() + 1, b.begin() + 1 + m, mid) - b.begin();
		idx--; s += idx * mid - pre[idx];
		if (idx <= m)
			p += pre[m] - pre[idx] - (m - idx) * mid;
		if (B <= A) {
			ret += p * B;
		} else{
			if (s >= p) {
				ret += p * A;
			} else{
				ret += s * A + (p - s) * B;
			}
		}
		for (ll i = 1; i <= n; i++)ret += max(0ll, mid - t[i]) * C;
		return ret;
	};
	ll l = 1, r = *max_element(b.begin() + 1, b.begin() + 1 + m);
	while (l <= r) {
		ll midl = (l + (r - l) / 3);
		ll midr = (r - (r - l) / 3);
		if (check(midl) <= check(midr))r = midr - 1;
		else l = midl + 1;
	}
	cout << check(l) << endl;
}
signed main() {
	solve();
}