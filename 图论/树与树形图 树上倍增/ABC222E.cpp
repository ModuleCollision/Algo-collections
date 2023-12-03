#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll fa[maxn][30]; ll dep[maxn];
void solve() {
  ll n, m, k; std::cin >> n >> m >> k;
  vector<ll>A(m + 1, 0); for (ll i = 1; i <= m; i++)cin >> A[i];
  vector<vector<pair<ll, ll>>>tr(n + 1);
  vector<ll>d(n + 1, 0);
  for (ll i = 1; i <= n - 1; i++) {
    ll u, v; std::cin >> u >> v;
    tr[u].push_back({v, i});
    tr[v].push_back({u, i});
  }
  vector<ll>p(n + 1);//节点转化为边差分
  function<void(ll, ll)>dfs = [&](ll u, ll f) {
    fa[u][0] = f;
    dep[u] = dep[fa[u][0]] + 1;
    for (ll i = 1; (1 << i) <= dep[u]; i++) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto [v, i] : tr[u]) {
      if (v == f)continue;
      p[v] = i; dfs(v, u);
    }
  };
  dfs(1, 0);
  auto lca = [&](ll u, ll v) {
    if (dep[u] < dep[v])swap(u, v);
    if (dep[u] != dep[v]) {
      for (ll i = log2(dep[u] - dep[v]); i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
          u = fa[u][i];
        }
      }
    }
    if (u == v)return u;
    for (ll i = log2(dep[u]); i >= 0; i--) {
      if (fa[u][i] != fa[v][i]) {
        u = fa[u][i]; v = fa[v][i];
      }
    }
    if (u != v) {
      u = fa[u][0];
    }
    return u;
  };
  for (ll i = 1; i <= m - 1; i++) {
    ll u = A[i], v = A[i + 1];
    ll lc = lca(u, v);
    d[p[u]]++; d[p[v]]++;
    d[p[lc]] -= 2;
  }
  function<void(ll, ll)>dfs2 = [&](ll u, ll f) {
    for (auto [v, i] : tr[u]) {
      if (v == f)continue;
      dfs2(v, u);
      d[p[u]] += d[i];
    }
  };
  dfs2(1, 0);
  ll tot = accumulate(d.begin() + 1, d.begin() + 1 + n, 0);
  vector dp(n + 1, vector<ll>(tot + 1, 0));
  dp[0][0] = 1;
  for (ll i = 1; i <= n - 1; i++) {
    for (ll j = tot; j >= 0; j--) {
      dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
      if (j >= d[i])
        dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - d[i]]) % mod;
    }
  } ll ans = 0;
  for (ll i = 0; i <= tot; i++)if (i + i - tot == k)ans = (ans % mod + dp[n - 1][i]) % mod;
  cout << ans << endl;
}
signed main() {
  solve();
}