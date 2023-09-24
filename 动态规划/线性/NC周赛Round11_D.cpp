#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, m; std::cin >> n >> m;
  vector<ll>A(n + 5, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
  sort(A.begin() + 1, A.begin() + 1 + n);
  vector dp(n + 5, vector<ll>(n - m + 5, 0));
  for (ll i = 1; i <= n; i++)dp[i][1] = 1;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j < i; j++) {
      if (A[i] % A[j] == 0) {
        for (ll k = 2; k <= n - m; k++) {
          dp[i][k] = (dp[i][k] % mod + dp[j][k - 1]) % mod;
        }
      }
    }
  }
  ll ans = 0;
  for (ll i = 1; i <= n; i++)ans = (ans % mod + dp[i][n - m]) % mod;
  cout << ans << endl;
}
signed main() {
  solve();
}