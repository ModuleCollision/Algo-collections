#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n; cin >> n;
  vector<ll>d(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> d[i];
  vector<ll>l(3), c(3), k(3);
  for (ll i = 1; i <= 2; i++) {
    cin >> l[i] >> c[i] >> k[i];
  }
  vector dp(n + 1, vector<ll>(k[1] + 1, inf));
  for (ll i = 0; i <= k[1]; i++) {
    dp[0][i] = 0;
  }
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j <= k[1]; j++) {
      for (ll k = j; k >= 0; k--) {
        ll w = max(0ll, d[i] - k * l[1]);
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + (w + l[2] - 1) / l[2]);
      }
    }
  }
  ll ans = inf;
  for (ll i = 0; i <= k[1]; i++) {
    if (dp[n][i] <= k[2]) {
      ans = min(ans, dp[n][i] * c[2] + i * c[1]);
    }
  }
  if (ans == inf) {
    puts("-1"); return;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}