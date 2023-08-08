#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; string s; std::cin >> n >> s;
	s = " " + s;
	std::set<ll>st;
	vector<ll>pre(n + 5, 0); ll tot = 0;
	for (ll i = 1, cur = 0; i <= n; i++) {
		pre[i] += pre[i - 1];
		if (s[i] == '0') {
			cur = 1; st.insert(i);
		} else if (s[i] == '1') {
			cur ^= 1;
		}
		pre[i] += cur;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		ll cur = s[i] - '0';
		auto idx = st.upper_bound(i);
		if (idx == st.end()) {
			ans += cur;
			ll d = n - i;
			if (cur == 1)ans += d / 2;
			else ans += (d + 1) / 2;
		} else {
			ans += cur;
			ll d = (*idx) - i - 1;
			if (cur == 1)ans += d / 2;
			else ans += (d + 1) / 2;
			ans += pre[n] - pre[(*idx) - 1];
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}