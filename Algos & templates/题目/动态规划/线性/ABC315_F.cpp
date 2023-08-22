#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n; std::cin >> n;
  vector dp(n + 5, vector<db>(35, inf));
  vector<pair<ll, ll>>w(n + 1);
  for (ll i = 1; i <= n; i++)cin >> w[i].first >> w[i].second;
  dp[1][0] = 0;
  auto dis = [&](ll i, ll j) {
    return  (db)sqrt((db)(w[i].fi - w[j].fi) * (db)(w[i].fi - w[j].fi) + (db)(w[i].se - w[j].se) * (db)(w[i].se - w[j].se));
  };
  for (ll i = 2; i <= n; i++) {
    for (ll j = 0; j <= 30; j++) {
      if (i - j - 1 <= 0)break;
      for (ll k = i - j - 1; k < i; k++) {
        dp[i][j] = min(dp[i][j], dis(i, k) + dp[k][j - (i - k - 1)]);
      }
    }
  }
  db ans = dp[n][0];
  for (ll j = 1; j <= 30; j++) {
    ans = min(ans, dp[n][j] + (1 << (j - 1)));
  }
  printf("%.12lf", ans);
}
signed main() {
  solve();
}