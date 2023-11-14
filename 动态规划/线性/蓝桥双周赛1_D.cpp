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
void solve() {
  ll n, m, q; std::cin >> n >> m >> q;
  vector<bool>vis(n + 1);
  for (ll i = 1; i <= q; i++) {
    ll t; cin >> t; vis[t] = true;
  }
  vector<pair<ll, ll>>w(m + 1);
  for (ll i = 1; i <= m; i++)cin >> w[i].fi >> w[i].se;
  vector<ll>pre(n + 1); ll p = 0;
  for (ll i = 1; i <= n; i++) {
    if (not vis[i]) {
      pre[i] = p;
    } else {
      p = i;
    }
  }
  vector<ll>dp(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    if (vis[i]) {
      dp[i] = max(dp[i], dp[i - 1]); continue;
    }
    dp[i] = max(dp[i], dp[i - 1]); ll d = i - pre[i];
    for (ll j = 1; j <= m; j++) {
      auto [k, s] = w[j];
      if (d >= (1 << k))dp[i] = max(dp[i], dp[i - (1 << k)] + s);
    }
  }
  ll ans = 0;
  cout << dp[n] << endl;
}
signed main() {
  solve();
}