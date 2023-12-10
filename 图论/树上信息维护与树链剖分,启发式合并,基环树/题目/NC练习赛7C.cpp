#include<bits/stdc++.h>

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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 1e5 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

int son[maxn];
int fa[maxn], rk[maxn], dfn[maxn], top[maxn], sz[maxn];
int cnt = 0;
struct edge {
	int v; int nx;
} e[maxn];
int head[maxn]; i64 tot_edge = 0;
void add_edge(int u, int v) {
	e[tot_edge].v = v;
	e[tot_edge].nx = head[u];
	head[u] = tot_edge++;
}

std::vector<i64>prime {0, 2, 3, 5, 7, 11, 13};


struct SegmentTree {

	struct sq {
		int l; int r; i64 v;
	};
	std::vector<sq>tr; int n;
	SegmentTree() {}
	SegmentTree(int n): tr(n * 4 + 5), n(n) {}
	void init(int n) {
		tr.resize(4 * n + 5);
		this -> n = n;
	}
	void pushup(int p) {
		tr[p].v = tr[p << 1].v + tr[p << 1 | 1].v;
	}
	void build(int p, int l, int r) {
		tr[p].l = l; tr[p].r = r;
		if (l == r) {
			tr[p].v = 0; return;
		}
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		pushup(p);
	}
	void modify(int p, int idx, i64 w) {
		if (tr[p].l == tr[p].r) {
			tr[p].v += w;
			return;
		}
		int mid = (tr[p].l + tr[p].r) >> 1;
		if (idx <= mid)modify(p << 1, idx, w);
		else if (idx > mid)modify(p << 1 | 1, idx, w);
		pushup(p);
	}
	i64 query( i64 p, i64 l, i64 r) {
		if (tr[p].l >= l and tr[p].r <= r) {
			return tr[p].v;
		}
		i64 ret = 0;
		i64 mid = (tr[p].l + tr[p].r) >> 1;
		if (l <= mid)ret += query( p << 1, l, r);
		if (r > mid)ret += query( p << 1 | 1, l, r);
		return ret;
	}
};
void dfs1(i64 u, i64 f) {
	sz[u] = 1; fa[u] = f;
	for (i64 ec = head[u]; ec != -1; ec = e[ec].nx) {
		i64 v = e[ec].v;
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
	cnt++; rk[u] = cnt;
	dfn[cnt] = u; if (son[u] == -1)return;
	dfs2(son[u], t);
	for (i64 ec = head[u]; ec != -1; ec = e[ec].nx) {
		i64 v = e[ec].v;
		if (v == fa[u])continue;
		if (v == son[u])continue;
		dfs2(v, v);
	}
}
i64 n;
std::vector<SegmentTree>t(7);
void solve() {
	std::cin >> n;
	std::fill(son + 1, son + 1 + n, -1);
	std::fill(head + 1, head + 1 + n, -1);
	for (i64 i = 1; i <= n - 1; i++) {
		i64 u, v; std::cin >> u >> v;
		u++; v++;
		add_edge(u, v); add_edge(v, u);
	}
	auto ksm = [&](i64 x, i64 y) {
		i64 ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret % mod;
	};

	dfs1(1, 1); dfs2(1, 1);
	for (i64 i = 1; i <= 6; i++)t[i].init(n), t[i].build(1, 1, n);
	for (i64 i = 1; i <= n; i++) {
		i64 w; std::cin >> w;
		for (i64 j = 1; j <= 6; j++) {
			i64 ww = 0;
			while (w % prime[j] == 0) {
				w /= prime[j]; ww++;
			}
			t[j].modify(1, rk[i], ww);
		}
	}
	i64 q; std::cin >> q;
	while (q--) {
		std::string op; std::cin >> op;
		if (op == "SEED") {
			i64 u, x; std::cin >> u >> x; u++;
			for (i64 j = 1; j <= 6; j++) {
				i64 ww = 0; while (x % prime[j] == 0) {
					x /= prime[j]; ww++;
				}
				t[j].modify(1, rk[u], ww);
			}
		} else {
			i64 ans = 1, res = 1;
			i64 u; std::cin >> u; u++;
			for (i64 i = 1; i <= 6; i++) {
				i64 cur = t[i].query(1, rk[u], rk[u] + sz[u] - 1);
				res = res % mod * (cur + 1) % mod;
				ans = (ans % mod) * ksm(prime[i], cur) % mod;
			}
			std::cout << ans << " " << res << "\n";
		}
	}
}
signed main() {
	solve();
}
/*一道树剖裸题*/