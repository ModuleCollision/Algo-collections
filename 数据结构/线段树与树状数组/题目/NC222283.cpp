#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
set<int>t[maxn];
int n, q;
int sum[maxn];
struct node {
	int l; int r; int val;
} tr[maxn];
struct se {
	int id; int val; int sk;
} a[maxn];
void build(int p, int l, int r) {
	tr[p].l = l; tr[p].r = r;
	if (l == r) {
		tr[p].val = a[l].sk;
		return;
	}
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	tr[p].val = max(tr[p << 1].val, tr[p << 1 | 1].val);
}
int query(int p, int l, int r) {
	if (tr[p].l >= l and tr[p].r <= r) {
		return tr[p].val;
	}
	int mid = (tr[p].l + tr[p].r) >> 1;
	int res = -inf;
	if (l <= mid) {
		res = max(res, query(p << 1, l, r));
	}
	if (r >= mid + 1) {
		res = max(res, query(p << 1 | 1, l, r));
	}
	return res;
}
int rt[maxn];
int lowbit(int x) {
	return x & -x;
}
void update(int x, int i, int SZ) {
	for (; i >= 1; i -= lowbit(i)) {
		rt[i] = min(rt[i], x);
	}
}
int ask(int i, int SZ) {
	int res = inf;
	for (; i <= SZ; i += lowbit(i)) {
		res = min(res, rt[i]);
	}
	return res;
}

void solve() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].val;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, [](se & x, se & y)->bool{
		return x.val < y.val;
	});
	a[1].sk = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i].val > a[i - 1].val) {
			a[i].sk = a[i - 1].sk + 1;
		} else {
			a[i].sk = a[i - 1].sk;
		}
	}
	sort(a + 1, a + n + 1, [](se & x, se & y)->bool{
		return x.id < y.id;
	});
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		t[a[i].sk].insert(i);
	}
	int SZ = a[n].sk;
	for (int i = n; i >= 1; i--) {
		int idx = ask(a[i].sk + 1, SZ);
		if (idx == inf) {
			sum[i] = 1;
		} else {
			sum[i] = sum[idx] + 1;
		}
		update(i, a[i].sk, SZ);
	}
	for (int i = 1; i <= q; i++) {
		int L, R;
		std::cin >> L >> R;
		int Max = query(1, L, R);
		int idx = (*t[Max].lower_bound(L));
		cout << sum[L] - sum[idx] + 1 << endl;
	}
}
signed main() {
	solve();
}