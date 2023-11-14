#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const int maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
struct sq {
	int l; int r;
	ll OR[55];
} tr[maxn << 2];
ll bit[maxn], a[maxn];
inline void pushup(int u) {
	for (int i = 0; i <= 32; i++) {
		tr[u].OR[i] = (tr[u << 1].OR[i] + tr[u << 1 | 1].OR[i]) % mod;
	}
}
void build(int p, int l, int r) {
	tr[p].l = l; tr[p].r = r;
	if (l == r) {
		for (int i = 0; i <= 32; i++) {
			tr[p].OR[i] = ((a[l] >> i) & 1);
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void modify(int p, int idx, ll v) {
	if (tr[p].l == tr[p].r) {
		for (ll i = 0; i <= 32; i++) {
			tr[p].OR[i] = ((v >> i) & 1);
		}
		return;
	}
	int mid = (tr[p].l + tr[p].r) >> 1;
	if (idx <= mid) {
		modify(p << 1, idx, v);
	} else {
		modify(p << 1 | 1, idx, v);
	}
	pushup(p);
}
vector<ll> query(ll p, ll l, ll r) {
	if (tr[p].l >= l and tr[p].r <= r) {
		vector<ll>ans(33, 0);
		for (ll i = 0; i <= 32; i++) {
			ans[i] = tr[p].OR[i];
		}
		return ans;
	}
	int mid = (tr[p].l + tr[p].r) >> 1;
	vector<ll>ans(33, 0), tmp1(33, 0), tmp2(33, 0);
	if (l <= mid) {
		tmp1 = query(p << 1, l, r);
	}
	if (r > mid) {
		tmp2 = query(p << 1 | 1, l, r);
	}
	for (int i = 0; i <= 32; i++) {
		ans[i] = tmp1[i] + tmp2[i];
	}
	return ans;
}
void solve() {
	bit[0] = 1;
	for (int i = 1; i < maxn; i++)bit[i] = (bit[i - 1] % mod * 2) % mod;
	int n; std::cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	build(1, 1, n);
	int m; std::cin >> m;
	while (m--) {
		int opt; std::cin >> opt;
		if (opt == 1) {
			int x; ll y; std::cin >> x >> y;
			modify(1, x, y);
		} else {
			int l, r; std::cin >> l >> r;
			vector<ll>ans = query(1, l, r);
			ll res = 0;
			for (int i = 0; i <= 32; i++) {
				res = (res + bit[i] % mod * (bit[ans[i]] - 1 + mod) % mod) % mod;
			}
			cout << res << endl;
		}
	}
}
signed main() {
	solve();
}
