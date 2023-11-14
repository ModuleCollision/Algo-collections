
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  int n, m; std::cin >> n >> m;
  vector<ll>c(n + 5, 0), p(n + 5, 0);
  vector s(n + 5, vector<ll>(105, 0));
  std::map<ll, db>dp;
  for (ll i = 1; i <= n; i++) {
    cin >> c[i] >> p[i];
    for (ll j = 1; j <= p[i]; j++)cin >> s[i][j];
  }
  function<db(ll)>dfs = [&](ll u) {
    if (u == 0)return dp[u] = 0;
    if (dp.count(u))return dp[u];
    dp[u] = inf;
    for (ll j = 1; j <= n; j++) {
      ll cnt = 0; db w = 0;
      for (ll k = 1; k <= p[j]; k++) {
        if (not s[j][k])cnt++;
        else if (u >= s[j][k])w += dfs(u - s[j][k]) / p[j];
      }
      w += c[j]; w /= (1 - (db)(cnt) / p[j]);
      dp[u] = min(dp[u], w);
    }
    return dp[u];
  };
  printf("%.10lf", dfs(m));
}
signed main() {
  solve();
}