/*Tarjan算法求LCA*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e4 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll n, m, x, y, k;
ll dis[maxn], fa[maxn], ans[maxn];
vector<pair<ll, ll>>q[maxn];
vector<pair<ll, ll>>tr[maxn];
void solve() {
  cin >> n >> m;
  vector<bool>vis(n + 5, false);
  for (ll i = 1; i <= n - 1; i++) {
    cin >> x >> y >> k;
    tr[x].push_back({y, k});
    tr[y].push_back({x, k});
  }
  for (ll i = 1; i <= m; i++) {
    cin >> x >> y;
    q[x].push_back({y, i});
    q[y].push_back({x, i});
  }
  for (ll i = 1; i <= n; i++) {
    fa[i] = i;
  }
  auto find = [&](ll u) -> ll {
    while (fa[u] != u) {
      u = fa[u] = fa[fa[u]];
    }
    return u;
  };
  function<void(ll, ll, ll)> dfs = [&] (ll u, ll f, ll d) {
    dis[u] = d;
    for (auto [v, s] : tr[u]) {
      if (v == f) {
        continue;
      }
      dfs(v, u, d + s);
    }
  };
  dfs(1, 0, 0);
  function<void(ll, ll)>tarjan = [&](ll u, ll f) {
    fa[u] = u; vis[u] = true;
    for (auto [v, s] : tr[u]) {
      if (v == f) {
        continue;
      }
      tarjan(v, u);
      fa[v] = u;
    }
    for (auto [c, idx] : q[u]) {
      if (vis[c]) {
        ll k = find(c);
        ans[idx] = dis[u] + dis[c] - dis[k] * 2; //统计答案,idx为编号
      }
    }
  };
  tarjan(1, 1);
  for (ll i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
}
signed main() {
  solve();
}
/*树上倍增算法求LCA*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef long double lb;
const ll maxn = 2e4 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
ll n, m, x, y, k;
vector<pair<ll, ll>>tr[maxn];
void add_edge(ll u, ll v, ll w) {
  tr[u].push_back({v, w});
  tr[v].push_back({u, w});
}
ll fa[maxn][20], dis[maxn][20]; ll dep[maxn];
void dfs(ll u, ll f) {
  fa[u][0] = f;
  dep[u] = dep[fa[u][0]] + 1;
  for (ll i = 1; (1 << i) <= dep[u]; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
    dis[u][i] = dis[u][i - 1] + dis[fa[u][i - 1]][i - 1];
  }
  for (auto [x, y] : tr[u]) {
    if (x == f) {
      continue;
    }
    dis[x][0] = y;
    dfs(x, u);
  }
}
ll lca(ll u, ll v) {
  ll ret = 0;
  if (dep[u] < dep[v]) {
    swap(u, v);
  }
  if (dep[u] != dep[v]) {
    for (ll i = log2(dep[u] - dep[v]); i >= 0; i--) {
      if (dep[fa[u][i]] >= dep[v]) {
        ret += dis[u][i];
        u = fa[u][i];
      }
    }
  }
  if (u == v) {
    return ret;
  }
  for (ll i = log2(dep[u]); i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      ret += dis[u][i]; ret += dis[v][i];
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  if (u != v) {
    ret += dis[u][0];
    ret += dis[v][0];
  }
  return ret;
}
signed main() {
  cin >> n >> m ;
  for (ll i = 1; i <= n - 1; i++) {
    cin >> x >> y >> k;
    add_edge(x, y, k);
  }
  dfs(1, 0);
  for (ll i = 1; i <= m; i++) {
    cin >> x >> y;
    cout << lca(x, y) << endl;
  }
}