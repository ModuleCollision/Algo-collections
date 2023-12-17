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
	i64 mx; i64 laz; i64 l, r;
} tr[maxn * 4];
i64 m, p;
void pushup(i64 u) {
	tr[u].mx = max(tr[u << 1].mx, tr[u << 1 | 1].mx);
	return;
}
void build(i64 u, i64 l, i64 r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].mx = 0;
		return;
	}
	i64 mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void pushdown(i64 u) {
	if (tr[u].laz) {
		i64 la = tr[u].laz;
		tr[u].laz = 0;
		tr[u << 1].laz = la;
		tr[u << 1 | 1].laz = la;
		tr[u << 1].mx = la;
		tr[u << 1 | 1].mx = la;
	}
	return;
}
void modify1(i64 u, i64 l, i64 r, i64 v) {
	if (tr[u].l >= l and tr[u].r <= r) {
		tr[u].mx = v; tr[u].laz = v;
		return;
	}
	pushdown(u);
	i64 mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)modify1(u << 1, l, r, v);
	if (r > mid)modify1(u << 1 | 1, l, r, v);
	pushup(u);
}
i64 query(i64 u, i64 l, i64 r) {
	if (tr[u].l >= l and tr[u].r <= r) {
		return tr[u].mx;
	}
	pushdown(u);
	i64 ret = 0;
	i64 mid = (tr[u].l + tr[u].r) >> 1;
	if (l <= mid)ret = max(ret, query(u << 1, l, r));
	if (r > mid)ret = max(ret, query(u << 1 | 1, l, r));
	return ret;
}
void solve() {
	i64 m, p; std::cin >> m >> p;
	i64 cur = 0;
	build(1, 1, m);
	i64 pre = 0;
	char opt; i64 k;
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
