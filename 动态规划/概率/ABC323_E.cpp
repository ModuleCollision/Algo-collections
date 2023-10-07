#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 305;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  auto ksm = [&](ll x, ll y) {
    ll ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  };
  auto inv = [&](ll x) {
    return ksm(x, mod - 2) % mod;
  };
  /*类背包却不是背包，求的是排列的方案数*/
  ll n, x; std::cin >> n >> x;
  vector<ll>t(n + 1); for (ll i = 1; i <= n; i++)cin >> t[i];
  vector<ll>dp(x + 1, 0);
  dp[0] = 1; ll w = inv(n) % mod;
  for (ll i = 1; i <= x; i++) {
    for (ll j = 1; j <= n; j++) {
      if (i >= t[j]) {
        dp[i] = (dp[i] % mod + dp[i - t[j]] % mod * w) % mod;
      }
    }
  }
  ll ans = 0;
  for (ll i = max(0ll, x + 1 - t[1]); i <= x; i++) {
    ans = (ans % mod + dp[i] % mod * w) % mod;
  }
  cout << ans % mod << endl;
}
signed main() {
  solve();
}