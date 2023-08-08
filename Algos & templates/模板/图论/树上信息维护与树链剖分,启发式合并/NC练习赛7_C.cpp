#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll son[maxn];
ll fa[maxn], rk[maxn], dfn[maxn], top[maxn], sz[maxn];
ll cnt = 0;
struct edge {
	ll v; ll nx;
} e[maxn];
ll head[maxn]; ll tot_edge = 0;
void add_edge(ll u, ll v) {
	e[tot_edge].v = v;
	e[tot_edge].nx = head[u];
	head[u] = tot_edge++;
}
struct sq {
	ll l; ll r; ll v;
} tr[7][maxn << 2];
ll prime[] = {0, 2, 3, 5, 7, 11, 13};
void pushup(ll q, ll p) {
	tr[q][p].v = tr[q][p << 1].v + tr[q][p << 1 | 1].v;
}
void build(ll q, ll p, ll l, ll r) {
	tr[q][p].l = l; tr[q][p].r = r;
	if (l == r) {
		tr[q][p].v = 0; return;
	}
	ll mid = (l + r) >> 1;
	build(q, p << 1, l, mid);
	build(q, p << 1 | 1, mid + 1, r);
	pushup(q, p);
}
void modify(ll q, ll p, ll idx, ll w) {
	if (tr[q][p].l == tr[q][p].r) {
		tr[q][p].v += w;
		return;
	}
	ll mid = (tr[q][p].l + tr[q][p].r) >> 1;
	if (idx <= mid)modify(q, p << 1, idx, w);
	else if (idx > mid)modify(q, p << 1 | 1, idx, w);
	pushup(q, p);
}
ll query(ll q, ll p, ll l, ll r) {
	if (tr[q][p].l >= l and tr[q][p].r <= r) {
		return tr[q][p].v;
	}
	ll ret = 0;
	ll mid = (tr[q][p].l + tr[q][p].r) >> 1;
	if (l <= mid)ret += query(q, p << 1, l, r);
	if (r > mid)ret += query(q, p << 1 | 1, l, r);
	return ret;
}
void dfs1(ll u, ll f) {
	sz[u] = 1; fa[u] = f;
	for (ll ec = head[u]; ec != -1; ec = e[ec].nx) {
		ll v = e[ec].v;
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
	cnt++; rk[u] = cnt;
	dfn[cnt] = u; if (son[u] == -1)return;
	dfs2(son[u], t);
	for (ll ec = head[u]; ec != -1; ec = e[ec].nx) {
		ll v = e[ec].v;
		if (v == fa[u])continue;
		if (v == son[u])continue;
		dfs2(v, v);
	}
}
void solve() {
	ll n; std::cin >> n;
	std::fill(son + 1, son + 1 + n, -1);
	std::fill(head + 1, head + 1 + n, -1);
	for (ll i = 1; i <= n - 1; i++) {
		ll u, v; std::cin >> u >> v;
		u++; v++;
		add_edge(u, v); add_edge(v, u);
	}
	auto ksm = [&](ll x, ll y) {
		ll ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret % mod;
	};
	dfs1(1, 1); dfs2(1, 1);
	for (ll i = 1; i <= 6; i++)build(i, 1, 1, n);
	for (ll i = 1; i <= n; i++) {
		ll w; std::cin >> w;
		for (ll j = 1; j <= 6; j++) {
			ll ww = 0;
			while (w % prime[j] == 0) {
				w /= prime[j]; ww++;
			}
			modify(j, 1, rk[i], ww);
		}
	}
	ll q; std::cin >> q;
	while (q--) {
		string op; std::cin >> op;
		if (op == "SEED") {
			ll u, x; std::cin >> u >> x; u++;
			for (ll j = 1; j <= 6; j++) {
				ll ww = 0; while (x % prime[j] == 0) {
					x /= prime[j]; ww++;
				}
				modify(j, 1, rk[u], ww);
			}
		} else {
			ll ans = 1, res = 1;
			ll u; std::cin >> u; u++;
			for (ll i = 1; i <= 6; i++) {
				ll cur = query(i, 1, rk[u], rk[u] + sz[u] - 1);
				res = res % mod * (cur + 1) % mod;
				ans = (ans % mod) * ksm(prime[i], cur) % mod;
			}
			cout << ans << " " << res << endl;
		}
	}
}
signed main() {
	solve();
}
/*一道树剖裸题*/