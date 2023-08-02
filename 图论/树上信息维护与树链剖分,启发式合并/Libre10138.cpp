#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 60010;
const ll inf = 2e9;
const ll mod = 998244353;
ll n;
ll sz[maxn], son[maxn]; ll top[maxn];
ll rk[maxn], w[maxn], dfn[maxn];
ll cnt = 0; ll dep[maxn], fa[maxn];
vector<ll>tr[maxn];
//树链剖分中一条重链的dfn序是连续的
struct sq {
	ll l; ll r; ll mx; ll sum;
} st[maxn * 4 + 5];
void dfs1(ll u, ll f) {
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
void dfs2(ll u, ll t) {
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
void pushup(ll u) {
	st[u].sum = st[u << 1].sum + st[u << 1 | 1].sum;
	st[u].mx = max(st[u << 1].mx, st[u << 1 | 1].mx);
}
void build(ll u, ll l, ll r) {
	st[u].l = l; st[u].r = r;
	if (l == r) {
		st[u].mx = st[u].sum = w[rk[l]];
		return;
	}
	ll mid = (l + r) >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
	pushup(u);
}
ll query2(ll p, ll l, ll r) {
	if (st[p].l >= l and st[p].r <= r) {
		return st[p].sum;
	}
	ll ret = 0;
	ll mid = (st[p].l + st[p].r) >> 1;
	if (r > mid)ret += query2(p << 1 | 1, l, r);
	if (l <= mid)ret += query2(p << 1, l, r);
	return ret;
}
ll query1(ll p, ll l, ll r) {
	if (st[p].l >= l and st[p].r <= r) {
		return st[p].mx;
	}
	ll ret = -inf;
	ll mid = (st[p].l + st[p].r) >> 1;
	if (r > mid)ret = max(ret, query1(p << 1 | 1, l, r));
	if (l <= mid)ret = max(ret, query1(p << 1, l, r));
	return ret;
}
void modify(ll u, ll idx, ll v) {
	if (st[u].l == st[u].r) {
		st[u].sum = v; st[u].mx = v; return;
	}
	ll mid = (st[u].l + st[u].r) >> 1;
	if (idx <= mid)modify(u << 1, idx, v);
	if (idx > mid)modify(u << 1 | 1, idx, v);
	pushup(u);
}
ll querymax(ll x, ll y) {
	ll ret = -inf, fx = top[x], fy = top[y];
	while (fx != fy) {//最终的目的是跳到同一条重链上
		if (dep[fx] >= dep[fy])
			ret = max(ret, query1(1, dfn[fx], dfn[x])), x = fa[fx];
		else
			ret = max(ret, query1(1, dfn[fy], dfn[y])), y = fa[fy];
		fx = top[x]; fy = top[y];
	}
	if (dfn[x] < dfn[y]) {
		ret = max(ret, query1(1, dfn[x], dfn[y]));
	} else {
		ret = max(ret, query1(1, dfn[y], dfn[x]));
	}
	return ret;
}
ll querysum(ll x, ll y) {
	ll ret = 0, fx = top[x], fy = top[y];
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
	string opt;
	ll n, u, v;
	std::cin >> n;
	for (ll i = 1; i < n; i++) {
		cin >> u >> v;
		tr[u].push_back(v); tr[v].push_back(u);
	}
	for (ll i = 1; i <= n; i++)cin >> w[i];
	dfs1(1, 1); dfs2(1, 1);
	build(1, 1, n);
	ll q; std::cin >> q;
	while (q--) {
		std::cin >> opt >> u >> v;
		if (opt == "CHANGE") {
			modify(1, dfn[u], v);
		} else if (opt == "QMAX") {
			cout << querymax(u, v) << endl;
		} else {
			cout << querysum(u, v) << endl;
		}
	}
}
signed main() {
	solve();
}
//树链剖分板子题