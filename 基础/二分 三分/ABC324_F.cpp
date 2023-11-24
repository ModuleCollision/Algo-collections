#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 999911659;
/*dp + 二分*/
void solve() {
  ll n, m; cin >> n >> m;
  vector<vector<array<db, 3>>>g(n + 1);
  for (ll i = 1; i <= m; i++) {
    db u, v, a, b; cin >> u >> v >> a >> b;
    g[v].push_back({u, a, b});
  }
  db l = 0, r = 1e18; vector<db>dp(n + 1);
  auto check = [&](db mid) {
    for (ll i = 2; i <= n; i++) {
      dp[i] = -1e18;
      for (auto [v, f, s] : g[i]) {
        ll vv = (ll)v;
        db c = f - s * mid;
        dp[i] = max(dp[i], dp[vv] + c);
      }
    }
    return dp[n];
  };
  double eps = 1e-12;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid) < 0)r = mid;
    else l = mid;
  }
  printf("%.20lf\n", r);
}
signed main() {
  solve();
}