#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	string s; ll pos;
	cin >> s >> pos;
	ll n = s.size();
	s = " " + s; vector<ll>l(n + 5), r(n + 5);
	for (ll i = 0; i <= n; i++)r[i] = i + 1;
	for (ll i = 1; i <= n + 1; i++)l[i] = i - 1;
	std::set<ll>st;
	auto del = [&](ll x) {
		st.erase(x);
		r[l[x]] = r[x];
		l[r[x]] = l[x];
		if (l[x] >= 1 and r[x] <= n and s[l[x]] > s[r[x]])st.insert(l[x]);
	};
	for (ll i = 1; i <= n - 1; i++) {
		if (s[i] > s[i + 1]) {
			st.insert(i);
		}
	}
	for (ll i = n; i >= 1; i--) {
		if (pos <= i) {
			ll t = 0;
			for (ll j = 0; j < pos; j++)t = r[t];
			cout << s[t];
			break;
		}
		pos -= i;
		if (st.size()) {
			del(*st.begin());
		} else {
			del(l[n + 1]);
		}
	}
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}