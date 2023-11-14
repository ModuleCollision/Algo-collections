/*浮点二分模板*/
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
  ll k, n, m; cin >> k >> n >> m;
  vector<vector<array<ll, 3>>>g(n + 1);
  for (ll i = 1; i <= m; i++) {
    ll u, v, t, h; cin >> u >> v >> t >> h;
    g[u].push_back({v, t, h});
    g[v].push_back({u, t, h});
  }
  vector dis(n + 1, vector<ll>(k + 5, inf));
  ll s, t; cin >> s >> t;
  dis[s][0] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>>q;
  q.push({0, s});
  vector<bool>vis(n + 1, false);
  while (q.size()) {
    auto [d, u] = q.top(); q.pop(); vis[u] = true;
    ll mn = inf;
    for (auto [v, t, h] : g[u]) {
      for (ll j = 0; j <= k; j++) {
        if (j >= h) {
          dis[v][j] = min(dis[v][j], dis[u][j - h] + t);
        }
        mn = min(mn, dis[v][j]);
      }
      if (not vis[v]) {
        q.push({mn, v});
      }
    }
  }
  ll ans = inf;
  for (ll j = 0; j < k; j++) {
    ans = min(ans, dis[t][j]);
  }
  if (ans == inf) {
    puts("-1"); return;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}