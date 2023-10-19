#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n, m, k; cin >> n >> m >> k;
  vector<vector<ll>>g(n + 1);
  for (ll i = 1; i <= m; i++) {
    ll u, v; std::cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }
  vector<ll>dis(n + 1, -1);
  vector<bool>vis(n + 1);
  priority_queue<pair<ll, ll>>q;
  for (ll i = 1; i <= k; i++) {
    ll p, h; std::cin >> p >> h;
    dis[p] = h; q.push({h, p});
  }

  while (q.size()) {
    auto [d, u] = q.top(); q.pop();
    vis[u] = 1;
    for (auto v : g[u]) {
      if (dis[v] < d - 1) {
        dis[v] = d - 1;
        if (not vis[v]) {
          q.push({dis[v], v});
        }
      }
    }
  } ll cnt = 0;
  vector<ll>ans;
  for (ll i = 1; i <= n; i++) {
    if (dis[i] >= 0)ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (auto c : ans) {
    cout << c << " ";
  }
  cout << endl;
}
signed main() {
  solve();
}