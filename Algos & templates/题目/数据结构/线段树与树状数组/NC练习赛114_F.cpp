#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll l, r, mx;
} tr[maxn * 4 + 5]; ll h[maxn], w[maxn];
void pushup(ll p) {
	tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
}
void build(ll p, ll l, ll r) {
	tr[p].l = l; tr[p].r = r;
	if (l == r) {
		tr[p].mx = h[l];
		return;
	}
	ll mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
ll ind1(ll p, ll l, ll r, ll v) {
	if (l > r)return 0ll;
	if (tr[p].l == tr[p].r) {
		if (tr[p].mx >= v)return tr[p].l;
		return 0;
	}
	ll mid = (tr[p].l + tr[p].r) >> 1;
	ll k1 = 0, k2 = 0;
	if (r > mid and tr[p << 1 | 1].mx >= v)k1 = ind1(p << 1 | 1, l, r, v);
	if (k1)return k1;
	if (l <= mid and tr[p << 1].mx >= v)k2 = ind1(p << 1, l, r, v);
	if (k2)return k2;
	return 0;
}
ll ind2(ll p, ll l, ll r, ll v) {
	if (l > r)return 0ll;
	if (tr[p].l == tr[p].r) {
		if (tr[p].mx >= v)return tr[p].l;
		return 0;
	}
	ll mid = (tr[p].l + tr[p].r) >> 1;
	ll k1 = 0, k2 = 0;
	if (l <= mid and tr[p << 1].mx >= v)k1 = ind2(p << 1, l, r, v);
	if (k1)return k1;
	if (r > mid and tr[p << 1 | 1].mx >= v)k2 = ind2(p << 1 | 1, l, r, v);
	if (k2)return k2;
	return 0;
}
/*线段树上二分模板*/
void solve() {

}
signed main() {
	ll T; std::cin >> T;
	while (T--)
		solve();
}