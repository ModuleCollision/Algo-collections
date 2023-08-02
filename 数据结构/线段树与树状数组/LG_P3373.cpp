#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll mul = 1; ll add; ll sum;
	ll l; ll r;
} tr[maxn * 4];
ll n, q, m;
ll a[maxn];
void pushup(ll u) {
	tr[u].sum = (tr[u << 1].sum % m + tr[u << 1 | 1].sum) % m;
	return;
}
void build(ll u, ll l, ll r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].mul = 1; tr[u].add = 0;
		tr[u].sum = a[l]; return;
	}
	ll mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(ll u) {
	if (tr[u].mul != 1) {
		ll mu = tr[u].mul;
		tr[u].mul = 1;
		tr[u << 1].mul = tr[u << 1].mul % m * mu % m; tr[u << 1 | 1].mul = tr[u << 1 | 1].mul % m * mu % m;
		tr[u << 1].sum = (tr[u << 1].sum % m * mu) % m;
		tr[u << 1 | 1].sum = (tr[u << 1 | 1].sum % m * mu) % m;
		tr[u << 1].add = (tr[u << 1].add % m * mu) % m;
		tr[u << 1 | 1].add = (tr[u << 1 | 1].add % m * mu) % m;
	}
	if (tr[u].add) {
		ll ad = tr[u].add;
		tr[u].add = 0;
		tr[u << 1].add = (tr[u << 1].add + ad) % m;
		tr[u << 1 | 1].add = (tr[u << 1 | 1].add % m + ad) % m;
		ll len1 = (tr[u << 1].r - tr[u << 1].l + 1);
		ll len2 = (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
		tr[u << 1].sum = (tr[u << 1].sum % m + len1 % m * ad) % m;
		tr[u << 1 | 1].sum = (tr[u << 1 | 1].sum % m + len2 % m * ad) % m;
	}
}
void multiply(ll u, ll l, ll r, ll v) {
	if (tr[u].l >= l and tr[u].r <= r) {
		tr[u].mul = (tr[u].mul % m * v) % m;
		tr[u].add = (tr[u].add % m * v) % m;
		tr[u].sum = (tr[u].sum % m * v) % m;
		return;
	}
	pushdown(u);
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)multiply(u << 1, l, r, v);
	if (r > mid)multiply(u << 1 | 1, l, r, v);
	pushup(u);
}
void plu(ll u, ll l, ll r, ll v) {
	if (tr[u].l >= l and tr[u].r <= r) {
		tr[u].add = (tr[u].add % m + v) % m;
		tr[u].sum = (tr[u].sum + (tr[u].r - tr[u].l + 1) % m * v) % m;
		return;
	}
	pushdown(u);
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)plu(u << 1, l, r, v);
	if (r > mid)plu(u << 1 | 1, l, r, v);
	pushup(u);
}
ll query_sum(ll u, ll l, ll r) {
	if (tr[u].l >= l and tr[u].r <= r) {
		return tr[u].sum % m;
	}
	pushdown(u);
	ll ret = 0;
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)ret = (ret % m + query_sum(u << 1, l, r)) % m;
	if (r > mid)ret = (ret % m + query_sum(u << 1 | 1, l, r)) % m;
	return ret % m;
}
void solve() {
	std::cin >> n >> q >> m;
	for (ll i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
	while (q--) {
		ll opt; std::cin >> opt;
		if (opt == 1) {
			ll x, y, k; std::cin >> x >> y >> k;
			multiply(1, x, y, k);
		} else if (opt == 2) {
			ll x, y, k; std::cin >> x >> y >> k;
			plu(1, x, y, k);
		} else {
			ll x, y; cin >> x >> y;
			cout << query_sum(1, x, y) % m << endl;
		}
	}
}
signed main() {
	solve();
}