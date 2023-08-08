/*二维树状数组: 第二种满足区间操作的轻量级数据结构*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m;
	std::cin >> n >> m; vector<ll>A(n + 5, 0);
	for (ll i = 1; i <= n; i++)cin >> A[i];
	vector<ll>tr1(n + 5, 0);
	vector<ll>tr2(n + 5, 0);
	auto add1 = [&](ll idx, ll v) {
		for (; idx <= n; idx += (idx & -idx)) {
			tr1[idx] += v;
		}
	};
	auto add2 = [&](ll idx, ll v) {
		ll s = idx * v;
		for (; idx <= n; idx += (idx & -idx)) {
			tr2[idx] += s;
		}
	};
	auto query1 = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret += tr1[idx];
		}
		return ret;
	};
	auto query2 = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret += tr2[idx];
		}
		return ret;
	};
	auto modify = [&](ll l, ll r, ll v) {
		add1(l, v); add1(r + 1, -v);
		add2(l, v); add2(r + 1, -v);
	};
	auto query = [&](ll l, ll r) {
		l--;
		return (r + 1) * query1(r) - query2(r) - (l + 1) * query1(l) + query2(l);
	};
	for (ll i = 1; i <= n; i++) {
		add1(i, A[i] - A[i - 1]);
		add2(i, A[i] - A[i - 1]);
	}
	while (m--) {
		string opt; std::cin >> opt;
		if (opt == "C") {
			ll l, r, d; cin >> l >> r >> d;
			modify(l, r, d);
		} else {
			ll l; cin >> l;
			cout << query(l, l) << endl;
		}
	}
}
signed main() {
	solve();
}