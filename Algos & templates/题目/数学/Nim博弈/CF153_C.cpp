#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n; std::cin >> n;
	vector<ll>p(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> p[i];
	ll idx = 1;
	while (idx + 1 <= n and p[idx + 1] < p[idx])idx++;
	vector<ll>tr1(n + 5, 0), tr2(n + 5, 0);
	auto add1 = [&](ll idx, ll v) {
		for (; idx <= n; idx += (idx & -idx))tr1[idx] += v;
	};
	auto query1 = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr1[idx];
		return ret;
	};
	auto add2 = [&](ll idx, ll v) {
		for (; idx <= n; idx += (idx & -idx))tr2[idx] += v;
	};
	auto query2 = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx))ret += tr2[idx];
		return ret;
	};
	std::set<ll>st; st.insert(0);
	vector<bool>w(n + 5, 0);
	for (ll i = 1; i <= n; i++) {
		auto c = st.lower_bound(p[i]); c--;
		if (c == st.begin()) {
			w[i] = 1;
		}
		st.insert(p[i]);
	}
	ll cnt = 0;
	/*for (ll i = 1; i <= n; i++) {
		cout << w[i] << " ";
	}*/
	//cout << endl;
	for (ll i = 1; i <= n; i++) {
		if (w[i]) {
			add1(p[i], 1); continue;
		}
		auto q1 = query1(p[i] - 1);
		auto q2 = query2(p[i] - 1);
		if (q1 and not q2) {
			add2(p[i], 1); cnt++;
			continue;
		}
	}
	cout << cnt << endl;
}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}