#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll l; ll r; ll v; ll p;
} tr[maxn * 4 + 5];
void pushup(ll u) {
	tr[u].v = (tr[u << 1].v % mod + tr[u << 1 | 1].v) % mod;
}
void pushdown(ll u) {
	ll len = tr[u].r - tr[u].l + 1;
	ll mid = (tr[u].l + tr[u].r) >> 1;
	ll len1 = (mid - tr[u].l + 1);
	ll len2 = (tr[u].r - mid);
	ll p = tr[u].p;
	tr[u].p = 0;
	tr[u << 1].v = (tr[u << 1].v % mod + len1 % mod * p) % mod;
	tr[u << 1 | 1].v = (tr[u << 1 | 1].v % mod + len2 % mod * p) % mod;
	tr[u << 1].p += p % mod;
	tr[u << 1 | 1].p += p % mod;
}
void build(ll u, ll l, ll r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].v = 0;
		return;
	}
	ll mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(ll u, ll s, ll t, ll v) {
	if (tr[u].l >= s and tr[u].r <= t) {
		tr[u].v += (tr[u].r - tr[u].l + 1) % mod * v % mod;
		tr[u].p += v;
		tr[u].p %= mod;
		return;
	}
	pushdown(u);
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (s <= mid) {
		modify(u << 1, s, t, v);
	}
	if (t > mid) {
		modify(u << 1 | 1, s, t, v);
	}
	pushup(u);
}
ll query(ll u, ll s, ll t) {
	if (tr[u].l >= s and tr[u].r <= t) {
		return tr[u].v;
	}
	pushdown(u);
	ll mid = (tr[u].l + tr[u].r) >> 1;
	ll ret = 0;
	if (s <= mid) {
		ret = (ret % mod + query(u << 1, s, t) % mod) % mod;
	}
	if (t > mid) {
		ret = (ret % mod + query(u << 1 | 1, s, t) % mod) % mod;
	}
	return ret % mod;
}
ll n, m;
struct op {
	ll opt, l, r;
};
void solve() {
	std::cin >> n >> m;
	vector<op>s(m + 5);
	for (ll i = 1; i <= m; i++) {
		std::cin >> s[i].opt >> s[i].l >> s[i].r;
	}
	build(1, 1, n);
	vector<ll>t(m + 5, 0);
	auto add = [&](ll id, ll v) {
		for (; id <= m; id += (id & -id)) {
			t[id] += v % mod;
		}
	};
	auto sum = [&](ll id) {
		ll ret = 0;
		for (; id >= 1; id -= (id & -id)) {
			ret = (ret % mod + t[id]) % mod;
		}
		return ret;
	};
	for (ll i = m; i >= 1; i--) {
		ll tmp = sum(i);
		if (s[i].opt == 1) {
			modify(1, s[i].l, s[i].r, tmp + 1);
		} else {
			add(s[i].l, tmp + 1);
			add(s[i].r + 1, -tmp - 1);
		}
	}
	for (ll i = 1; i <= n; i++) {
		cout << query(1, i, i) % mod << " ";
	}
	cout << endl;//树状数组+差分维护总共经过几次操作
}
signed main() {
	solve();
}


