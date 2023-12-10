#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, k, c; cin >> n >> k >> c;
  vector<ll>tr[n + 1];
  for (ll i = 1; i <= n - 1; i++) {
    ll u, v; cin >> u >> v;
    tr[u].push_back(v);
    tr[v].push_back(u);
  }
  vector<ll>dis(n + 1);
  vector<ll>sif(n + 1, 0);
  function<void(ll, ll, ll)>dfs1 = [&](ll u, ll f, ll s) {
    sif[u] = s;
    for (auto v : tr[u]) {
      if (v == f)continue;
      dfs1(v, u, s + 1);
      dis[u] = max(dis[u], dis[v] + 1);
    }
  };
  dfs1(1, 0, 0);
  vector<ll>ans(n + 1);
  function<void(ll, ll, ll)>dfs2 = [&](ll u, ll f, ll pre) {
    ans[u] = max(dis[u], pre);
    ll mx1 = pre, mx2 = -inf;
    for (auto v : tr[u]) {
      if (v == f)continue;
      if (dis[v] + 1 >= mx1) {
        mx2 = mx1;
        mx1 = dis[v] + 1;
      } else if (dis[v] + 1 > mx2) {
        mx2 = dis[v] + 1;
      }
    }
    for (auto v : tr[u]) {
      if (v == f)continue;
      if (dis[v] + 1 == mx1) {
        dfs2(v, u, mx2 + 1);
      } else {
        dfs2(v, u, mx1 + 1);
      }
    }
  };
  dfs2(1, 0, 0);
  ll res = -inf;
  for (ll i = 1; i <= n; i++) {
    ll cur = ans[i] * k - sif[i] * c;
    res = max(res, cur);
  }
  cout << res << endl;
}
signed main() {
  ll T; cin >> T;
  while (T--)
    solve();
}

