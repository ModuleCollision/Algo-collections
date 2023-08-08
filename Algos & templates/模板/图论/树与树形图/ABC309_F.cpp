#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll N, M; std::cin >> N >> M;
  vector<vector<ll>>tr(N + 5);
  for (ll i = 2; i <= N; i++) {
    ll p; std::cin >> p; tr[p].push_back(i);
    tr[i].push_back(p);
  }
  vector<ll>w(N + 5, 0);
  for (ll i = 1; i <= M; i++) {
    ll x, y; std::cin >> x >> y;
    w[x] = y;
  }
  vector<bool>vis(N + 5, false);
  function<void(ll, ll, ll)>dfs = [&](ll u, ll f, ll dep) {
    ll des = dep;
    if (w[u]) {
      des = max(des, w[u] + 1);
    }
    if (des) {
      vis[u] = 1;
    }
    for (auto v : tr[u]) {
      if (v == f)continue;
      dfs(v, u, max(des - 1, 0ll));
    }
  };
  dfs(1, 0, w[1] + 1);
  ll ans = 0;
  for (ll i = 1; i <= N; i++) {
    if (vis[i])ans++;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}