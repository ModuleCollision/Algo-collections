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
	i64 l; i64 r; i64 v; i64 p;
} tr[maxn * 4 + 5];
void pushup(i64 u) {
	tr[u].v = (tr[u << 1].v % mod + tr[u << 1 | 1].v) % mod;
}
void pushdown(i64 u) {
	i64 len = tr[u].r - tr[u].l + 1;
	i64 mid = (tr[u].l + tr[u].r) >> 1;
	i64 len1 = (mid - tr[u].l + 1);
	i64 len2 = (tr[u].r - mid);
	i64 p = tr[u].p;
	tr[u].p = 0;
	tr[u << 1].v = (tr[u << 1].v % mod + len1 % mod * p) % mod;
	tr[u << 1 | 1].v = (tr[u << 1 | 1].v % mod + len2 % mod * p) % mod;
	tr[u << 1].p += p % mod;
	tr[u << 1 | 1].p += p % mod;
}
void build(i64 u, i64 l, i64 r) {
	tr[u].l = l; tr[u].r = r;
	if (l == r) {
		tr[u].v = 0;
		return;
	}
	i64 mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
void modify(i64 u, i64 s, i64 t, i64 v) {
	if (tr[u].l >= s and tr[u].r <= t) {
		tr[u].v += (tr[u].r - tr[u].l + 1) % mod * v % mod;
		tr[u].p += v;
		tr[u].p %= mod;
		return;
	}
	pushdown(u);
	i64 mid = (tr[u].l + tr[u].r) >> 1;
	if (s <= mid) {
		modify(u << 1, s, t, v);
	}
	if (t > mid) {
		modify(u << 1 | 1, s, t, v);
	}
	pushup(u);
}
i64 query(i64 u, i64 s, i64 t) {
	if (tr[u].l >= s and tr[u].r <= t) {
		return tr[u].v;
	}
	pushdown(u);
	i64 mid = (tr[u].l + tr[u].r) >> 1;
	i64 ret = 0;
	if (s <= mid) {
		ret = (ret % mod + query(u << 1, s, t) % mod) % mod;
	}
	if (t > mid) {
		ret = (ret % mod + query(u << 1 | 1, s, t) % mod) % mod;
	}
	return ret % mod;
}
i64 n, m;
struct op {
	i64 opt, l, r;
};
void solve() {
	std::cin >> n >> m;
	vector<op>s(m + 5);
	for (i64 i = 1; i <= m; i++) {
		std::cin >> s[i].opt >> s[i].l >> s[i].r;
	}
	build(1, 1, n);
	vector<i64>t(m + 5, 0);
	auto add = [&](i64 id, i64 v) {
		for (; id <= m; id += (id & -id)) {
			t[id] += v % mod;
		}
	};
	auto sum = [&](i64 id) {
		i64 ret = 0;
		for (; id >= 1; id -= (id & -id)) {
			ret = (ret % mod + t[id]) % mod;
		}
		return ret;
	};
	for (i64 i = m; i >= 1; i--) {
		i64 tmp = sum(i);
		if (s[i].opt == 1) {
			modify(1, s[i].l, s[i].r, tmp + 1);
		} else {
			add(s[i].l, tmp + 1);
			add(s[i].r + 1, -tmp - 1);
		}
	}
	for (i64 i = 1; i <= n; i++) {
		cout << query(1, i, i) % mod << " ";
	}
	cout << endl;//树状数组+差分维护总共经过几次操作
}
signed main() {
	solve();
}


