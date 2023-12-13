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
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e7 + 500;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 n;
i64 sz[maxn], son[maxn]; i64 top[maxn];
i64 rk[maxn], w[maxn], dfn[maxn];
i64 cnt = 0; i64 dep[maxn], fa[maxn];
std::vector<i64>tr[maxn];
//树链剖分中一条重链的dfn序是连续的
struct sq {
	i64 l; i64 r; i64 mx; i64 sum;
} st[maxn * 4 + 5];
void dfs1(i64 u, i64 f) {
	dep[u] = dep[f] + 1;
	fa[u] = f;
	son[u] = -1; sz[u] = 1;
	for (auto v : tr[u]) {
		if (v == f)continue;
		dfs1(v, u);
		sz[u] += sz[v];
		if (son[u] == -1 or sz[v] > sz[son[u]]) {
			son[u] = v;
		}
	}
}
void dfs2(i64 u, i64 t) {
	top[u] = t;
	cnt++;
	dfn[u] = cnt;
	rk[cnt] = u;
	if (son[u] == -1)return;
	dfs2(son[u], t);//同一条树链上的dfs序连续
	for (auto v : tr[u]) {
		if (v == fa[u])continue;
		if (v == son[u])continue;
		dfs2(v, v);
	}
}
void pushup(i64 u) {
	st[u].sum = st[u << 1].sum + st[u << 1 | 1].sum;
	st[u].mx = std::max(st[u << 1].mx, st[u << 1 | 1].mx);
}
void build(i64 u, i64 l, i64 r) {
	st[u].l = l; st[u].r = r;
	if (l == r) {
		st[u].mx = st[u].sum = w[rk[l]];
		return;
	}
	i64 mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
i64 query2(i64 p, i64 l, i64 r) {
	if (st[p].l >= l and st[p].r <= r) {
		return st[p].sum;
	}
	i64 ret = 0;
	i64 mid = (st[p].l + st[p].r) >> 1;
	if (r > mid)ret += query2(p << 1 | 1, l, r);
	if (l <= mid)ret += query2(p << 1, l, r);
	return ret;
}
i64 query1(i64 p, i64 l, i64 r) {
	if (st[p].l >= l and st[p].r <= r) {
		return st[p].mx;
	}
	i64 ret = -inf;
	i64 mid = (st[p].l + st[p].r) >> 1;
	if (r > mid)ret = std::max(ret, query1(p << 1 | 1, l, r));
	if (l <= mid)ret = std::max(ret, query1(p << 1, l, r));
	return ret;
}
void modify(i64 u, i64 idx, i64 v) {
	if (st[u].l == st[u].r) {
		st[u].sum = v; st[u].mx = v; return;
	}
	i64 mid = (st[u].l + st[u].r) >> 1;
	if (idx <= mid)modify(u << 1, idx, v);
	if (idx > mid)modify(u << 1 | 1, idx, v);
	pushup(u);
}
i64 querymax(i64 x, i64 y) {
	i64 ret = -inf, fx = top[x], fy = top[y];
	while (fx != fy) {//最终的目的是跳到同一条重链上
		if (dep[fx] >= dep[fy])
			ret = std::max(ret, query1(1, dfn[fx], dfn[x])), x = fa[fx];
		else
			ret = std::max(ret, query1(1, dfn[fy], dfn[y])), y = fa[fy];
		fx = top[x]; fy = top[y];
	}
	if (dfn[x] < dfn[y]) {
		ret = std::max(ret, query1(1, dfn[x], dfn[y]));
	} else {
		ret = std::max(ret, query1(1, dfn[y], dfn[x]));
	}
	return ret;
}
i64 querysum(i64 x, i64 y) {
	i64 ret = 0, fx = top[x], fy = top[y];
	while (fx != fy) {
		if (dep[fx] >= dep[fy])
			ret += query2(1, dfn[fx], dfn[x]), x = fa[fx];
		else
			ret += query2(1, dfn[fy], dfn[y]), y = fa[fy];
		fx = top[x]; fy = top[y];
	}
	if (dfn[x] < dfn[y]) {
		ret += query2(1, dfn[x], dfn[y]);
	} else {
		ret += query2(1, dfn[y], dfn[x]);
	}
	return ret;
}
void solve() {
	std::string opt;
	i64 n, u, v;
	std::cin >> n;
	for (i64 i = 1; i < n; i++) {
		std::cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	for (i64 i = 1; i <= n; i++)std::cin >> w[i];
	dfs1(1, 1); dfs2(1, 1);
	build(1, 1, n);
	i64 q; std::cin >> q;
	while (q--) {
		std::cin >> opt >> u >> v;
		if (opt == "CHANGE") {
			modify(1, dfn[u], v);
		} else if (opt == "QMAX") {
			std::cout << querymax(u, v) << "\n";
		} else {
			std::cout << querysum(u, v) << "\n";
		}
	}
}
signed main() {
	solve();
}
/*树链剖分模板*/