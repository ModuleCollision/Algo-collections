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

struct Node {
	i64 l; i64 r; i64 sum; i64 add;
} tr[2050000];
void pushup(i64 p) {
	tr[p].sum = (tr[p << 1].sum + tr[p << 1 | 1].sum);
}
void build(i64 p, i64 l, i64 r) {
	tr[p].l = l; tr[p].r = r;
	if (l == r) {
		tr[p].sum = tr[p].add = 0;
		return;
	}
	i64 mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
void pushdown(i64 p) {
	i64 l = tr[p].l, r = tr[p].r;
	i64 mid = (l + r) >> 1;
	i64 add = tr[p].add;
	tr[p << 1].sum += add * (mid - l + 1);
	tr[p << 1 | 1].sum += add * (r - mid);
	tr[p << 1].add += add;
	tr[p << 1 | 1].add += add;
	tr[p].add = 0;
}

void modify(i64 p, i64 l, i64 r, i64 val) {
	if (tr[p].l >= l and tr[p].r <= r) {
		tr[p].sum += (tr[p].r - tr[p].l + 1) * val;
		tr[p].add = (tr[p].add + val);
		return;
	}
	pushdown(p);
	i64 mid = (tr[p].l + tr[p].r) >> 1;
	if (r > mid) {
		modify(p << 1 | 1, l, r, val);
	}
	if (l <= mid) {
		modify(p << 1, l, r, val);
	}
	pushup(p);
}
i64 query(i64 p, i64 l, i64 r) {
	if (tr[p].l >= l and tr[p].r <= r) {
		return tr[p].sum;
	}
	pushdown(p);
	i64 ret = 0, mid = (tr[p].l + tr[p].r) >> 1;
	if (r > mid) {
		ret = (ret + query(p << 1 | 1, l, r));
	}
	if (l <= mid) {
		ret = (ret + query(p << 1, l, r));
	}
	return ret;
}
pair<i64, i64> s[maxn]; i64 n, m;
void solve() {
	std::cin >> n >> m;
	build(1, 1, maxn); i64 ans = 0;
	for (i64 i = 1; i <= m; i++) {
		cin >> s[i].first >> s[i].second;
	}
	std::sort(s + 1, s + 1 + m, [&](pair<i64, i64>x, pair<i64, i64>y)->bool{
		if (x.second != y.second)return x.second < y.second;
		else return x.first < y.first;
	});
	modify(1, s[1].first, s[1].second, 1);
	for (i64 i = 2; i <= m; i++) {
		i64 tmp = 0;
		i64 mn = n - s[i].second, mx = n - s[i].first;
		mn = max(mn, 1i64);
		if (mx <= 0) {
			modify(1, s[i].first, s[i].second, 1); continue;
		}
		tmp = query(1, mn, mx) % mod;
		ans = (ans  + tmp) % mod;
		modify(1, s[i].first, s[i].second, 1);
	}
	cout << ans * 2 % mod << endl;
}
signed main() {
	solve();
}