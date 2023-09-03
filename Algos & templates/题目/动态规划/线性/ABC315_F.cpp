#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n; std::cin >> n;
  vector<pair<ll, ll>>w(n + 5);
  for (ll i = 1; i <= n; i++) {
    std::cin >> w[i].fi >> w[i].se;
  }
  auto dis = [&](ll i, ll j)->db{
    return (db)sqrt((db)(w[i].fi - w[j].fi) * (w[i].fi - w[j].fi) + (w[i].se - w[j].se) * (w[i].se - w[j].se));
  };
  vector dp(n + 5, vector<db>(n + 5, (db)(1e10)));
  dp[1][1] = 0.0;
  for (ll i = 2; i <= n; i++) {
    for (ll j = max(2ll, i - 30); j <= i; j++) {//选择了J个
      ll sk = i - j;//跳过的
      for (ll k = max(1ll, i - 1 - sk); k < i; k++) {
        dp[i][j] = min(dp[i][j], dp[k][j - 1] + (db)dis(i, k));
      }
    }
  }
  db ans = (db)1e10;
  for (ll i = 2; i <= n; i++) {
    ll sk = n - i;//跳过的
    ans = min(ans, dp[n][i] + ((sk >= 1) ? (1 << (sk - 1)) : 0.0));
  }
  printf("%.12lf", ans);
}
signed main() {
  solve();
}