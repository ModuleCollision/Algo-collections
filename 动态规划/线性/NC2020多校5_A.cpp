#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll dis[maxn][maxn]; ll t[40005];
void solve() {
  ll n, m, k; std::cin >> n >> m >> k;
  vector dp(2 * k + 5, vector<ll>(2 * n + 5, inf));
  dp[0][1] = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      if (dis[i] == dis[j])continue;
      dis[i][j] = inf;
    }
  }
  for (ll i = 1; i <= m; i++) {
    ll x, y, z; std::cin >> x >> y >> z;
    dis[x][y] = dis[y][x] = min(dis[x][y], z);
  }
  ll cnt = 0;
  for (ll k = 1; k <= n; k++) {
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (ll i = 1; i <= k; i++) {
    ll u, v; std::cin >> u >> v;
    t[++cnt] = u, t[++cnt] = v;
  }
  k *= 2; t[0] = 1;
  for (ll i = 1; i <= k; i++) {
    for (ll j = 1; j <= n; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + dis[t[i - 1]][t[i]]);
      for (ll l = 1; l <= n; l++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][l] + dis[l][t[i]] + dis[t[i - 1]][j]);
        dp[i][l] = min(dp[i][l], dp[i - 1][j] + dis[j][l] + dis[l][t[i]]);
      }
    }
  }
  ll ans = inf;
  for (ll i = 1; i <= n; i++)ans = min(ans, dp[k][i]);
  cout << ans << endl;
}
signed main() {
  solve();
}