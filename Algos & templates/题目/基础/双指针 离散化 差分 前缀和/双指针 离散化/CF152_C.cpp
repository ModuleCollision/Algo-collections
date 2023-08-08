#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	std::set<pair<ll, ll>>st;
	ll n, m; std::cin >> n >> m;
	std::string s; cin >> s;
	s = " " + s;
	vector<ll>l(n + 5), r(n + 5); r[n + 1] = n + 1;
	for (ll i = 1; i <= n; i++) {
		if (s[i] == '0')s[i] = i;
		else s[i] = s[i - 1];
	}
	for (ll i = n; i >= 1; i--) {
		if (s[i] == '1')r[i] = i;
		else r[i] = r[i + 1];
	}
	for (ll i = 1; i <= m; i++) {
		ll x, y; cin >> x >> y;
		x = l[x], y = r[y];
		if (x >= y)st.insert({0, 0});
		else st.insert({x, y});
	}
	cout << st.size() << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}