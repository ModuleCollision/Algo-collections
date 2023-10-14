#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll son[maxn], dfn[maxn], rk[maxn]; ll tot = 0;
ll c1[maxn], c2[maxn];//点 -->边 边 --> 点
ll dep[maxn]; ll fa[maxn][30]; ll top[maxn];
ll sz[maxn], tr[maxn]; ll n;

void add(ll idx, ll v) {
  for (; idx <= n; idx += (idx & -idx))tr[idx] += v;
}
ll query(ll idx) {
  ll ret = 0;
  for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
  return ret;
}
void modify(ll idx, ll v) {
  ll vv = query(idx) - query(idx - 1);
  add(idx, -vv);
  add(idx, v);
}
ll queryrange(ll l, ll r) {
  return query(r) - query(l - 1);
}
ll querysum(ll x, ll y) {
  ll ret = 0, fx = top[x], fy = top[y];
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
  vector<vector<pair<ll, ll>>>g(n + 1);
  vector<ll>w(n + 1);
  for (ll i = 1; i <= n - 1; i++) {
    ll u, v; std::cin >> u >> v >> w[i];
    g[u].push_back({v, i});
    g[v].push_back({u, i});
  }
  function<void(ll, ll)>dfs = [&](ll u, ll f) {
    fa[u][0] = f;
    dep[u] = dep[fa[u][0]] + 1;
    for (ll i = 1; (1 << i) <= dep[u]; i++) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto [v, idx] : g[u]) {
      if (v == f)continue;
      c1[v] = idx; c2[idx] = v;
      dfs(v, u);
    }
  };
  auto lca = [&](ll u, ll v) {
    if (dep[u] < dep[v])swap(u, v);
    if (dep[u] != dep[v]) {
      for (ll i = log2(dep[u] - dep[v]); i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
          u = fa[u][i];
        }
      }
    }
    if (u == v) {
      return u;
    }
    for (ll i = log2(dep[u]); i >= 0; i--) {
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
  function<void(ll, ll)>dfs1 = [&](ll u, ll f) {
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
  function<void(ll, ll)>dfs2 = [&](ll u, ll t) {
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
  for (ll i = 1; i <= n - 1; i++) {
    add(dfn[c2[i]], w[i]);
  }
  ll q; cin >> q;
  while (q--) {
    ll opt; cin >> opt;
    if (opt == 1) {
      ll idx, w; cin >> idx >> w;
      idx = dfn[c2[idx]];
      modify(idx, w);
    } else {
      ll u, v; cin >> u >> v;
      cout << querysum(u, v) - (query(dfn[lca(u, v)]) - query(dfn[lca(u, v)] - 1)) << endl;
    }
  }

}
signed main() {
  solve();
}