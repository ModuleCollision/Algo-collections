#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll mx; ll laz; ll l, r;
} tr[maxn * 4];
ll m, p;
void pushup(ll u) {
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
	return;
}
void build(ll u, ll l, ll r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].mx = 0;
		return;
	}
	ll mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(ll u) {
	if (tr[u].laz) {
		ll la = tr[u].laz;
		tr[u].laz = 0;
		tr[u << 1].laz = la;
		tr[u << 1 | 1].laz = la;
		tr[u << 1].mx = la;
		tr[u << 1 | 1].mx = la;
	}
	return;
}
void modify1(ll u, ll l, ll r, ll v) {
	if (tr[u].l >= l and tr[u].r <= r) {
		tr[u].mx = v; tr[u].laz = v;
		return;
	}
	pushdown(u);
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)modify1(u << 1, l, r, v);
	if (r > mid)modify1(u << 1 | 1, l, r, v);
	pushup(u);
}
ll query(ll u, ll l, ll r) {
	if (tr[u].l >= l and tr[u].r <= r) {
		return tr[u].mx;
	}
	pushdown(u);
	ll ret = 0;
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)ret = max(ret, query(u << 1, l, r));
	if (r > mid)ret = max(ret, query(u << 1 | 1, l, r));
	return ret;
}
void solve() {
	ll m, p; std::cin >> m >> p;
	ll cur = 0;
	build(1, 1, m);
	ll pre = 0;
	char opt; ll k;
	while (m--) {
		cin >> opt >> k;
		if (opt == 'Q') {
			pre = query(1, cur - k + 1, cur);
			cout << pre << endl;
		} else {
			cur++; k = (k % p + pre) % p;
			modify1(1, cur, cur, k);
		}
	}
}
signed main() {
	solve();
}
