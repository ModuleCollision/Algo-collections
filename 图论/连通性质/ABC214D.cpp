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

struct DSU {
	vector<i64>fa;
	vector<i64>sz;
	void init(i64 n) {
		fa.resize(n + 5);
		for (i64 i = 1; i <= n; i++) {
			fa[i] = i;
		}
		sz.resize(n + 5, 1);
	}
	i64 find(i64 x) {
		while (x != fa[x])x = fa[x] = fa[fa[x]];
		return x;
	}
	void merge(i64 x, i64 y) {
		i64 a = find(x), b = find(y);
		if (a == b)return;
		fa[a] = b;
		sz[b] += sz[a];
	}
} dsu; i64 N;
struct edge {
	i64 u, v, w;
};
vector<edge>e;
void solve() {
	std::cin >> N;
	dsu.init(N);
	for (i64 i = 1; i <= N - 1; i++) {
		i64 u, v, w; std::cin >> u >> v >> w;
		e.push_back({u, v, w});
	}
	std::sort(e.begin(), e.end(), [&](edge a, edge b)->bool{
		return a.w < b.w;
	});
	i64 ans = 0;
	for (auto ed : e) {
		i64 u = ed.u, v = ed.v, w = ed.w;
		ans += dsu.sz[dsu.find(u)] * dsu.sz[dsu.find(v)] * w;
		dsu.merge(u, v);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}