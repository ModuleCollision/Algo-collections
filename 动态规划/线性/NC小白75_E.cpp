#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1000005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, m; std::cin >> n >> m;
  vector dp(n + 5, vector<ll>(m + 5, 0));
  for (ll i = 1; i <= m; i++)dp[1][i] = 1;
  for (ll i = 2; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      for (ll k = (i - 1) * j / (i) + 1; k <= m; k++) {
        if (k * (i) - (i - 1)*j > m)break;
        dp[i][k] = (dp[i][k] % mod + dp[i - 1][j]) % mod;
      }
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= m; i++) {
    ans = (ans % mod + dp[n][i]) % mod;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}