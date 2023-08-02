#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, k; std::cin >> n >> k;
  vector<ll>A(n + 5, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  ll cnt = 0; vector<ll>p(10005, 0); vector<bool>vis(10005, false);
  for (ll i = 2; i <= 10000; i++) {
    if (not vis[i]) {
      p[++cnt] = i;
    }
    for (ll j = 1; j <= cnt and p[j]*i <= 10000; j++) {
      vis[p[j]*i] = 1;
      if (i % p[j] == 0)break;
    }
  }
  ll dp[n + 5][n + 5][10005];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (ll i = 1; i <= n; i++) {
    for (ll z = 0; z <= i; z++)
      for (ll j = 0; j <= 10000; j++) {
        dp[i][z][j] += dp[i - 1][z][j];
        if (j >= A[i] and z >= 1) {
          dp[i][z][j] += dp[i - 1][z - 1][j - A[i]];
        }
      }
  }
  ll ans = 0;
  for (ll i = 2; i <= 10000; i++) {
    if (not vis[i]) {
      ans += dp[n][k][i];
    }
  }
  cout << ans << endl;
}

signed main() {
  solve();
}
