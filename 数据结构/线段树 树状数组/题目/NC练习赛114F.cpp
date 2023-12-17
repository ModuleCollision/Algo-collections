/*线段树上二分模板*/
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
	i64 l, r, mx;
} tr[maxn * 4 + 5]; i64 h[maxn], w[maxn];
void pushup(i64 p) {
	tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
}
void build(i64 p, i64 l, i64 r) {
	tr[p].l = l; tr[p].r = r;
	if (l == r) {
		tr[p].mx = h[l];
		return;
	}
	i64 mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
/*查找某范围内 >= v 元素的最靠右的位置*/
i64 ind1(i64 p, i64 l, i64 r, i64 v) {
	if (tr[p].l == tr[p].r) {
		if (tr[p].mx >= v)return tr[p].l;
		return 0;
	}
	i64 mid = (tr[p].l + tr[p].r) >> 1;
	i64 k1 = 0, k2 = 0;
	if (r > mid and tr[p << 1 | 1].mx >= v)k1 = ind1(p << 1 | 1, l, r, v);
	if (k1)return k1;
	if (l <= mid and tr[p << 1].mx >= v)k2 = ind1(p << 1, l, r, v);
	if (k2)return k2;
	return 0;
}
/*查找某范围内 >= v 的元素的最靠左的位置*/
i64 ind2(i64 p, i64 l, i64 r, i64 v) {
	if (tr[p].l == tr[p].r) {
		if (tr[p].mx >= v)return tr[p].l;
		return 0;
	}
	i64 mid = (tr[p].l + tr[p].r) >> 1;
	i64 k1 = 0, k2 = 0;
	if (l <= mid and tr[p << 1].mx >= v)k1 = ind2(p << 1, l, r, v);
	if (k1)return k1;
	if (r > mid and tr[p << 1 | 1].mx >= v)k2 = ind2(p << 1 | 1, l, r, v);
	if (k2)return k2;
	return 0;
}
void solve() {
	i64 n; std::cin >> n;
	for (i64 i = 1; i <= n; i++)cin >> h[i];
	build(1, 1, n); i64 ans = 0;
	for (i64 i = 1; i <= n; i++)cin >> w[i], w[i] += w[i - 1];
	for (i64 i = 1; i <= n; i++) {
		i64 pre = 0;
		i64 l = ind1(1, 1, i - 1, h[i]);
		i64 r = ind2(1, i + 1, n, h[i]);
		if (not r or i == n)r = n + 1;
		ans = max(ans, w[r - 1] - w[l]);
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)solve();
}
