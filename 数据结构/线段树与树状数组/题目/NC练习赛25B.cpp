#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
	ll l, r, lmx, rmx, mx;
} tr[maxn << 1];
ll A[maxn];
void pushup(ll u) {
	tr[u].lmx = tr[u << 1].lmx;
	tr[u].rmx = tr[u << 1 | 1].rmx;
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
	if (A[tr[u << 1].r] < A[tr[u << 1 | 1].l]) {
		if (tr[u << 1].r - tr[u << 1].l + 1 == tr[u << 1].lmx) {
			tr[u].lmx += tr[u << 1 | 1].lmx;
		}
		if (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1 == tr[u << 1 | 1].rmx) {
			tr[u].rmx += tr[u << 1].rmx;
		}
		tr[u].mx = max(tr[u].mx, tr[u << 1].rmx + tr[u << 1 | 1].lmx);
	}
}
void build(ll u, ll l, ll r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].lmx = tr[u].rmx = tr[u].mx = 1;
		return;
	}
	ll mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(ll u, ll idx, ll v) {
	if (tr[u].l == tr[u].r) {
		A[tr[u].l] = v;
		return;
	}
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (idx <= mid) {
		modify(u << 1, idx, v);
	} else {
		modify(u << 1 | 1, idx, v);
	}
	pushup(u);
}
sq query(ll u, ll s, ll t) {
	if (tr[u].l >= s and tr[u].r <= t) {
		return tr[u];
	}
	sq ans, lans, rans;
	ll mid = (tr[u].l + tr[u].r) >> 1;
	if (s <= mid) {
		lans = query(u << 1, s, t);
	}
	if (t > mid) {
		rans = query(u << 1 | 1, s, t);
	}
	ans.lmx = lans.lmx;
	ans.rmx = rans.rmx;
	ans.mx = max(lans.mx, rans.mx);
	if (A[lans.r] < A[rans.l]) {
		if (lans.r - lans.l + 1 == lans.lmx) {
			ans.lmx += rans.lmx;
		}
		if (rans.r - rans.l + 1 == rans.rmx) {
			ans.rmx += lans.rmx;
		}
		ans.mx = max(ans.mx, lans.rmx + rans.lmx);
	}
	return ans;
}
void solve() {
	ll n, m;
	std::cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		std::cin >> A[i];
	}
	build(1, 1, n);
	auto k = query(1, 1, n);
	cout << k.mx << endl;
	while (m--) {
		ll x, y; std::cin >> x >> y;
		modify(1, x, y);
		k = query(1, 1, n);
		cout << k.mx << endl;
	}
}
signed main() {
	solve();
}
