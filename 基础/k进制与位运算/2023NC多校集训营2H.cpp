#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
	ll n, q; std::cin >> n >> q;
	ll ps = 0;
	string s; std::cin >> s;
	s = " " + s;
	vector<ll>pre(n + 5, 0);
	vector<ll>pre2(n + 5, 0);
	vector<ll>f(n + 5); ll cnt = 0;
	ll ws = 1;
	std::set<ll>st; st.insert(0);
	for (ll i = 1; i <= n; i++) {
		pre[i] += pre[i - 1];
		pre2[i] += pre2[i - 1];
		if (s[i] == 'A') {
			f[i] = ++cnt;
			ws = -ws;
			st.insert(i);
			pre[i]++;
		} else if (s[i] == 'B') {
			pre2[i] = pre2[i - 1] + (ws * 1);
		}
	}
	//cout << pre2[n] - pre2[0] << endl;
    string x; 
	while (q--) {
		ll l, r; std::cin >> l >> r;
		std::cin >> x;
		ll ms = (1 << (x.size()));
		l = ((ps ^ l) % n) + 1;
		r = ((ps ^ r) % n) + 1;
		if (l > r)swap(l, r);
		ll cur = 0;
		for (ll i = x.size() - 1; i >= 0; i--) {
			if (x[i] == '1')
				cur = (cur % ms + (1 << (x.size() - 1 - i))) % ms;
		}
		ll v = pre2[r] - pre2[l - 1];
		auto pp = st.lower_bound(l);
		ll pos = f[*pp];
		if (pos % 2 == 0) {
			v = ((0 - v) % ms + ms) % ms;
		}
		string res = "";
		cur = (cur % ms + v) % ms;
		if ((pre[r] - pre[l - 1]) & 1) {
			ll ans = ((((1 << x.size()) - 1) - cur) % ms + ms) % ms;
			for (ll i = 0; ans >> i; i++) {
				res += (char)('0' + ((ans >> i) & 1));
			}
			ps = ans;
		} else {
			ll ans = (cur) % ms;
			for (ll i = 0; i < x.size(); i++) {
				res += (char)('0' + ((ans >> i) & 1));
			}
			ps = ans;
		}
		reverse(res.begin(), res.end());
		cout << res << endl;
	}
}
signed main() {
	solve();
}