#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
	ll n, m, q; std::cin >> n >> m >> q;
	vector<ll>fa(n + 5), a(n + 5), tr(n + 5), id(n + 5);
	ll cnt = 0;
	auto find = [&](ll x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	auto add = [&](ll id, ll v) {
		for (; id <= n; id += (id & -id)) {
			tr[id] += v;
		}
	};
	auto query = [&](ll idx) {
		ll ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret += tr[idx];
		}
		return ret;
	};
	ll sum = 0;
	string s; std::cin >> s;
	for (ll i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
		if (a[i])sum++;
		fa[i] = i;
	}
	fa[n + 1] = n + 1;
	//查询1 --- sum前缀中0的个数
	for (ll i = 1; i <= m; i++) {
		ll l, r; std::cin >> l >> r;
		for (ll x = find(l); x <= r; x = find(x)) {
			id[x] = ++cnt; fa[x] = x + 1;//避免重复计算
		}
	}
	for (ll i = 1; i <= n; i++) {
		if (id[i] and not a[i]) {
			add(id[i], 1);
		}
	}
	while (q--) {
		ll x; std::cin >> x;
		if (a[x] == 1) {
			sum--; if (id[x])add(id[x], 1);
			a[x] = 0;
		} else {
			sum++;
			if (id[x])add(id[x], -1);
			a[x] = 1;
		}
		cout << query(sum) << endl;
	}
}
signed main() {
	solve();
}