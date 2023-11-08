#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll ksm(ll x, ll y) {
  ll ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret % mod;
}
ll inv(ll x) {
  return ksm(x, mod - 2) % mod;
}
void solve() {
  ll n; cin >> n;
  vector<ll>a(n + 1); for (ll i = 1; i <= n; i++)cin >> a[i];
  vector<ll>dp(n + 1, 0);
  ll w = inv(n) % mod;
  dp[0] = 1 % mod;
  vector<ll>pre(n + 1); pre[0] = dp[0] % mod; ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    dp[i] = (pre[i - 1] % mod * w % mod * a[i]) % mod;
    pre[i] = (pre[i - 1] % mod + pre[i - 1] % mod * w % mod) % mod;
    ans = (ans % mod + dp[i]) % mod;
  }
  cout << ans % mod << endl;
}
signed main() {
  solve();
}