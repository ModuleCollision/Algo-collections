#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll fa[maxn];
ll dis[maxn][30]; ll p[maxn][30]; ll dep[maxn];
ll find(ll x) {
  while (x != fa[x])
    x = fa[x] = fa[fa[x]];
  return x;
}
bool same(ll x, ll y) {
  return find(x) == find(y);
}
void merge(ll x, ll y) {
  ll a = find(x), b = find(y);
  fa[a] = b;
}
void solve() {
  ll n, m, q;
  std::cin >> n >> m >> q;
  vector<array<ll, 3>> w;
  std::iota(fa + 1, fa + 1 + n, 1);
  vector<vector<array<ll, 2>>> tr(n + 1);
  for (ll i = 1; i <= m; i++) {
    ll u, v, c;
    std::cin >> u >> v >> c;
    w.push_back({u, v, c});
  }
  std::sort(w.begin(), w.end(), [&](auto q, auto s) -> bool {
    return q[2] < s[2];
  });
  for (auto [u, v, c] : w) {
    if (same(u, v))
      continue;
    merge(u, v);
    tr[u].push_back({v, c});
    tr[v].push_back({u, c});
  }
  function<void(ll, ll)> dfs = [&](ll u, ll f) {
    p[u][0] = f;
    dep[u] = dep[p[u][0]] + 1;
    for (ll i = 1; (1 << i) <= dep[u]; i++) {
      p[u][i] = p[p[u][i - 1]][i - 1];
      dis[u][i] = max(dis[u][i - 1], dis[p[u][i - 1]][i - 1]);
    }
    for (auto [x, y] : tr[u]) {
      if (x == f)
        continue;
      dis[x][0] = y;
      dfs(x, u);
    }
  };
  auto lca = [&](ll u, ll v) {
    ll ret = 0;
    if (dep[u] < dep[v])
      swap(u, v);
    if (dep[u] != dep[v]) {
      for (ll i = log2(dep[u] - dep[v]); i >= 0; i--) {
        if (dep[p[u][i]] >= dep[v]) {
          ret = max(ret, dis[u][i]);
          u = p[u][i];
        }
      }
    }
    if (u == v)
      return ret;
    for (ll i = log2(dep[u]); i >= 0; i--) {
      if (p[u][i] != p[v][i]) {
        ret = max(ret, dis[u][i]);
        ret = max(ret, dis[v][i]);
        u = p[u][i];
        v = p[v][i];
      }
    }
    if (u != v) {
      ret = max(ret, dis[u][0]);
      ret = max(ret, dis[v][0]);
    }
    return ret;
  };
  dfs(1, 0);
  while (q--) {
    ll u, v, c;
    std::cin >> u >> v >> c;
    ll lc = lca(u, v);
    // cout << "#" << lc << " " << endl;
    if (c <= lc) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
}
signed main() {
  solve();
}