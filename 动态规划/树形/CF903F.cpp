#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 305;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
const ll p = 233;
void solve() {
  ll n, k; std::cin >> n >> k;
  vector<bool>mark(n + 1, 0);
  for (ll i = 1; i <= k; i++) {
    ll v; cin >> v; mark[v] = true;
  }
  vector<vector<ll>>g(n + 1);
  for (ll i = 1; i <= n - 1; i++) {
    ll u, v; cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }
  vector<ll>mx(n + 1, -inf);
  function<void(ll, ll)>dfs1 = [&](ll u, ll f) {
    if (mark[u])mx[u] = max(mx[u], 0ll);
    for (auto v : g[u]) {
      if (v == f)continue;
      dfs1(v, u);
      mx[u] = max(mx[u], mx[v] + 1);
    }
  };
  vector<ll>ans(n + 1, -inf);
  function<void(ll, ll, ll)>dfs2 = [&](ll u, ll f, ll pre) {
    if (mark[u])pre = max(pre, 0ll);
    ans[u] = max(mx[u], pre);
    ll mx1 = pre, mx2 = -inf;
    for (auto v : g[u]) {
      if (v == f)continue;
      if (mx[v] + 1 >= mx1) {
        mx2 = mx1; mx1 = mx[v] + 1;
      } else if (mx[v] + 1 > mx2) {
        mx2 = mx[v] + 1;
      }
    }
    for (auto v : g[u]) {
      if (v == f)continue;
      if (mx[v] + 1 == mx1) {
        dfs2(v, u, mx2 + 1);
      } else {
        dfs2(v, u, mx1 + 1);
      }
    }
  };
  dfs1(1, 0); dfs2(1, 0, -inf);
  cout << *min_element(ans.begin() + 1, ans.begin() + 1 + n) << endl;
}
signed main() {
  ll t; cin >> t;
  while (t--)
    solve();
}
