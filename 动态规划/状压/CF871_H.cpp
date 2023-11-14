#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, k; cin >> n >> k;
  vector<ll>A(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  vector dp(n + 1, vector<ll>((1 << 6) + 1, 0));
  for (ll i = 1; i <= n; i++) {
    dp[i][A[i]] = 1;
    for (ll j = 0; j < (1 << 6); j++) {
      dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
    }
    for (ll j = 0; j < (1 << 6); j++) {
      dp[i][j & A[i]] = (dp[i][j & A[i]] % mod + dp[i - 1][j]) % mod;
    }
  }
  ll ans = 0;
  auto count = [&](ll x) {
    ll cnt = 0;
    for (ll i = 6; i >= 0; i--) {
      if ((x >> i) & 1)cnt++;
    }
    return cnt == k;
  };
  for (ll i = 0; i < (1 << 6); i++) {
    if (count(i)) {
      ans = (ans % mod + dp[n][i]) % mod;
    }
  }
  cout << ans << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}