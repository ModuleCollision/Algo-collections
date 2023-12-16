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

i64 son[maxn], dfn[maxn], rk[maxn]; i64 tot = 0;
i64 c1[maxn], c2[maxn];//点 -->边 边 --> 点
i64 dep[maxn]; i64 fa[maxn][30]; i64 top[maxn];
i64 sz[maxn], tr[maxn]; i64 n;

void add(i64 idx, i64 v) {
  for (; idx <= n; idx += (idx & -idx))tr[idx] += v;
}
i64 query(i64 idx) {
  i64 ret = 0;
  for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
  return ret;
}
void modify(i64 idx, i64 v) {
  i64 vv = query(idx) - query(idx - 1);
  add(idx, -vv);
  add(idx, v);
}
i64 queryrange(i64 l, i64 r) {
  return query(r) - query(l - 1);
}
i64 querysum(i64 x, i64 y) {
  i64 ret = 0, fx = top[x], fy = top[y];
  while (fx != fy) {
    if (dep[fx] >= dep[fy])
      ret += queryrange(dfn[fx], dfn[x]), x = fa[fx][0];
    else
      ret += queryrange(dfn[fy], dfn[y]), y = fa[fy][0];
    fx = top[x]; fy = top[y];
  }
  if (dfn[x] < dfn[y]) {
    ret += queryrange(dfn[x], dfn[y]);
  } else {
    ret += queryrange(dfn[y], dfn[x]);
  }
  return ret;
}
void solve() {
  std::cin >> n;
  vector<vector<pair<i64, i64>>>g(n + 1);
  vector<i64>w(n + 1);
  for (i64 i = 1; i <= n - 1; i++) {
    i64 u, v; std::cin >> u >> v >> w[i];
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
    fa[u][0] = f;
    dep[u] = dep[fa[u][0]] + 1;
    for (i64 i = 1; (1 << i) <= dep[u]; i++) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto [v, idx] : g[u]) {
      if (v == f)continue;
      c1[v] = idx; c2[idx] = v;
      dfs(v, u);
    }
  };
  auto lca = [&](i64 u, i64 v) {
    if (dep[u] < dep[v])swap(u, v);
    if (dep[u] != dep[v]) {
      for (i64 i = log2(dep[u] - dep[v]); i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
          u = fa[u][i];
        }
      }
    }
    if (u == v) {
      return u;
    }
    for (i64 i = log2(dep[u]); i >= 0; i--) {
      if (fa[u][i] != fa[v][i]) {
        u = fa[u][i];
        v = fa[v][i];
      }
    }
    if (u != v) {
      u = fa[u][0];
    }
    return u;
  };
  function<void(i64, i64)>dfs1 = [&](i64 u, i64 f) {
    son[u] = -1; sz[u] = 1;
    for (auto [v, idx] : g[u]) {
      if (v == f)continue;

      dfs1(v, u);
      sz[u] += sz[v];
      if (son[u] == -1 or sz[v] > sz[son[u]]) {
        son[u] = v;
      }
    }
  };
  function<void(i64, i64)>dfs2 = [&](i64 u, i64 t) {
    top[u] = t; tot++;
    dfn[u] = tot;
    rk[tot] = u;
    if (son[u] == -1)return;
    dfs2(son[u], t);
    for (auto [v, idx] : g[u]) {
      if (v == fa[u][0])continue;
      if (v == son[u])continue;
      dfs2(v, v);
    }
    return;
  };
  dfs(1, 0);
  dfs1(1, 0); dfs2(1, 0);
  for (i64 i = 1; i <= n - 1; i++) {
    add(dfn[c2[i]], w[i]);
  }
  i64 q; cin >> q;
  while (q--) {
    i64 opt; cin >> opt;
    if (opt == 1) {
      i64 idx, w; cin >> idx >> w;
      idx = dfn[c2[idx]];
      modify(idx, w);
    } else {
      i64 u, v; cin >> u >> v;
      cout << querysum(u, v) - (query(dfn[lca(u, v)]) - query(dfn[lca(u, v)] - 1)) << endl;
    }
  }

}
signed main() {
  solve();
}