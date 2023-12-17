#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct sq {
	i64 l, r, lmx, rmx, mx;
} tr[maxn << 1];
i64 A[maxn];
void pushup(i64 u) {
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
void build(i64 u, i64 l, i64 r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].lmx = tr[u].rmx = tr[u].mx = 1;
		return;
	}
	i64 mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}

void modify(i64 u, i64 idx, i64 v) {
	if (tr[u].l == tr[u].r) {
		A[tr[u].l] = v;
		return;
	}
	i64 mid = (tr[u].l + tr[u].r) >> 1;
	if (idx <= mid) {
		modify(u << 1, idx, v);
	} else {
		modify(u << 1 | 1, idx, v);
	}
	pushup(u);
}
sq query(i64 u, i64 s, i64 t) {
	if (tr[u].l >= s and tr[u].r <= t) {
		return tr[u];
	}
	sq ans, lans, rans;
	i64 mid = (tr[u].l + tr[u].r) >> 1;
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
	i64 n, m;
	std::cin >> n >> m;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i];
	}
	build(1, 1, n);
	auto k = query(1, 1, n);
	cout << k.mx << endl;
	while (m--) {
		i64 x, y; std::cin >> x >> y;
		modify(1, x, y);
		k = query(1, 1, n);
		cout << k.mx << endl;
	}
}
signed main() {
	solve();
}
