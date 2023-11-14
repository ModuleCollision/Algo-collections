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
bool vis[maxn]; ll cnt = 0;
ll prime[maxn];
void init() {
  for (ll i = 2; i <= 1e6; i++) {
    if (not vis[i]) {
      prime[++cnt] = i;
    }
    for (ll j = 1; j <= cnt and i * prime[j] <= 1e6; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0)break;
    }
  }
}
void solve() {
  ll n, m; cin >> n >> m;
  vector<vector<ll>>g(n + 1);
  vector<bool>vis(n + 1);
  while (m--) {
    ll u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ll ans = 0; vis[1] = true;
  function<void(ll, ll)>dfs = [&](ll u, ll cnt) {
    ans += (cnt == n);
    for (auto v : g[u]) {
      if (not vis[v]) {
        vis[v] = true;
        dfs(v, cnt + 1);
        vis[v] = false;
      }
    }
  };
  dfs(1, 1);
  cout << ans << endl;
}
signed main() {
  solve();
}