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
  vector<ll>A(n + 2, 0), B(n + 2, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (ll j = 1; j <= n; j++)cin >> B[j];
  vector dp(n + 2, vector<ll>(3010));
  for (ll j = A[1]; j <= B[1]; j++)dp[1][j] = 1, dp[1][j] += dp[1][j - 1];
  for (ll i = 2; i <= n; i++) {
    for (ll j = A[i]; j <= B[i]; j++) {
      dp[i][j] = (dp[i][j - 1] % mod + dp[i - 1][min(j, B[i - 1])]) % mod;
    }
  }
  cout << dp[n][B[n]] % mod << endl;
}
signed main() {
  solve();
}