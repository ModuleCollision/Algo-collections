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
  ll n, m; std::cin >> n >> m; bool flag = true;
  vector<vector<pair<ll, ll>>>g(n + 1);
  vector<ll>val(n + 1, 0);
  vector<array<ll, 3>>e(m + 1);
  for (ll i = 1; i <= m; i++) {
    ll u, v, w; std::cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, -w});
    e[i] = {u, v, w};
  }
  vector<bool>vis(n + 1, false);

  function<void(ll, ll )>dfs = [&](ll u, ll w) {
    vis[u] = 1;
    for (auto [v, x] : g[u]) {
      if (not vis[v]) {
        val[v] = val[u] + x;
        dfs(v, w + x);
      }
    }
  };
  for (ll i = 1; i <= n; i++) {
    if (not vis[i]) {
      dfs(i, 0);
    }
  }
  for (ll i = 1; i <= m; i++) {
    auto [u, v, w] = e[i];
    if (val[u] + w != val[v]) {
      puts("NO"); return;
    }
  }
  puts("YES");
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}