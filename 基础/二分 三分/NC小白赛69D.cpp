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
i64 n, m, c;
struct edge {
	i64 u; i64 v; i64 w;
};
void solve() {
	std::cin >> n >> m >> c;
	vector<edge>e(m + 5);
	for (i64 i = 1; i <= m; i++) {
		std::cin >> e[i].u >> e[i].v >> e[i].w;
	}
	std::sort(e.begin() + 1, e.begin() + 1 + m, [&](edge a, edge b)->bool{
		return a.w < b.w;
	});
	vector<i64>fa(n + 5, 0), sz(n + 5, 1);
	auto init = [&](i64 n) {
		for (i64 i = 1; i <= n; i++) {
			fa[i] = i;
		}
	};
	auto find = [&](i64 x) {
		while (x != fa[x]) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	};
	auto merge = [&](i64 u, i64 v) {
		i64 x = find(u), y = find(v);
		if (x == y)return;
		fa[x] = y;
	};
	auto check = [&](i64 mid) {
		i64 cnt = 0; for (i64 i = 1; i <= n; i++)fa[i] = i;
		i64 ret = 0;
		vector<i64>vv;
		for (i64 i = 1; i <= m; i++) {
			i64 u = e[i].u, v = e[i].v, w = e[i].w;
			i64 a = find(u), b = find(v);
			if (a == b)continue;
			fa[a] = b;
			vv.push_back(w);
		}
		std::sort(vv.begin(), vv.end(), [&](i64 x, i64 y)->bool{
			return x > y;
		});
		for (auto q : vv) {
			if (q <= mid)q = 0;

			ret += q * (++cnt);
		}
		return ret <= c;//满足题意的条件
	};
	i64 l = 0, r = inf;//注意二分边界: 0 ---> inf
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid ;
		} else {
			l = mid + 1;
		}
	}
	cout << r << endl;
}
signed main() {
	solve();
}