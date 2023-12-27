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

void solve() {
	i64 n, m, q; std::cin >> n >> m >> q;
	vector<i64>fa(n + 5), a(n + 5), tr(n + 5), id(n + 5);
	i64 cnt = 0;
	auto find = [&](i64 x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	};
	auto add = [&](i64 id, i64 v) {
		for (; id <= n; id += (id & -id)) {
			tr[id] += v;
		}
	};
	auto query = [&](i64 idx) {
		i64 ret = 0;
		for (; idx >= 1; idx -= (idx & -idx)) {
			ret += tr[idx];
		}
		return ret;
	};
	i64 sum = 0;
	string s; std::cin >> s;
	for (i64 i = 1; i <= n; i++) {
		a[i] = s[i - 1] - '0';
		if (a[i])sum++;
		fa[i] = i;
	}
	fa[n + 1] = n + 1;
	//查询1 --- sum前缀中0的个数
	for (i64 i = 1; i <= m; i++) {
		i64 l, r; std::cin >> l >> r;
		for (i64 x = find(l); x <= r; x = find(x)) {
			id[x] = ++cnt; fa[x] = x + 1;//避免重复计算
		}
	}
	for (i64 i = 1; i <= n; i++) {
		if (id[i] and not a[i]) {
			add(id[i], 1);
		}
	}
	while (q--) {
		i64 x; std::cin >> x;
		if (a[x] == 1) {
			sum--; if (id[x])add(id[x], 1);
			a[x] = 0;
		} else {
			sum++;
			if (id[x])add(id[x], -1);
			a[x] = 1;
		}
		cout << query(sum) << endl;
	}
}
signed main() {
	solve();
}