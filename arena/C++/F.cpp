#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n, k; std::cin >> n >> k;
  vector<vector<ll>>tr(n + 1); vector<ll>d(n + 1, 0);
  vector<bool>mark(n + 1);
  vector<pair<ll, ll>>e(n + 1);
  for (ll i = 1; i <= k; i++) {
    ll a; cin >> a; mark[a] = 1;
  }
  for (ll i = 1; i <= n - 1; i++) {
    ll u, v; std::cin >> u >> v;
    tr[u].push_back(v); tr[v].push_back(u);
    d[u]++; d[v]++; e[i].fi = u; e[i].se = v;
  }
  queue<ll>q;
  for (ll i = 1; i <= n; i++) {
    if (d[i] == 1 and not mark[i]) {
      q.push(i);
    }
  }
  ll cnt = n;
  vector<bool>vis(n + 1, false); //去掉的节点
  while (q.size()) {
    ll u = q.front(); q.pop(); vis[u] = 1; cnt--;
    for (auto v : tr[u]) {
      --d[v];
      if (d[v] == 1 and (not mark[v]))q.push(v);
    }
  }

  vector<vector<ll>>g(n + 1);
  for (ll i = 1; i <= n - 1; i++) {
    auto [u, v] = e[i];
    if (vis[u] or vis[v])continue;
    g[u].push_back(v); g[v].push_back(u);
  }
  vector<ll>sz(n + 1, 0), w(n + 1, 0); vector<ll>cen;
  function<void(ll, ll)>dfs = [&](ll u, ll f) {
    sz[u] = 1; w[u] = 0;
    //cout << u << " ";
    for (auto v : g[u]) {
      if (v == f)continue;
      dfs(v, u);
      sz[u] += sz[v];
      w[u] = max(w[u], sz[v]);
    }
    w[u] = max(w[u], cnt - sz[u]);
    if (w[u] <= cnt / 2) {
      cen.push_back(u);
    }
  };
  for (ll i = 1; i <= n; i++) {
    if (not vis[i]) {
      dfs(i, 0); break;
    }
  }
  auto u = cen.front();//重心
  ll ans = 0;
  function<void(ll, ll, ll)>dfs2 = [&](ll u, ll f, ll d) {
    if (mark[u])ans = max(ans, d);
    for (auto v : g[u]) {
      if (v == f)continue;
      dfs2(v, u, d + 1);
    }
  };
  dfs2(u, 0, 0);
  cout << ans << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}