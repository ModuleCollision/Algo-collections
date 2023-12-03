#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	string s; std::cin >> s;
	s = " " + s;
	std::set<ll>st; ll k1 = 0, k2 = 0;
	for (ll i = 1; i <= n; i++) {
		if (s[i] == '(')k1++; else k2++;
	}
	if (k1 != k2) {
		puts("-1"); return;
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (s[i] == '(')st.insert(i);
	}
	for (ll i = 1; i <= n; i++) {
		if (s[i] == ')') {
			ll cur = *st.begin();
			if (cur < i) {
				st.erase(st.begin());
			} else {
				ans += cur - i;
				swap(s[cur], s[i]);
				st.erase(st.begin());
				st.insert(i);
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}