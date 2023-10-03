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
ll ins(ll msk, ll k) {
  for (ll i = 10; i >= k + 1; i--)msk = msk | (((msk >> (i - k - 1)) & 1) << (i - 1));
  msk |= (1 << (k - 1));
  return msk;
}
ll ksm(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1)ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret % mod;
}
void solve() {
  ll n; std::cin >> n;
  vector<ll>A(n + 1, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
  vector<ll>pre(n + 1, 0);
  pre[0] = 1;
  for (ll i = 1; i <= n; i++) {
    pre[i] = (pre[i - 1] % mod * A[i]) % mod;
  }
  vector dp(n + 1, vector<ll>(1 << (11), 0));
  dp[0][0] = 1;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j < (1 << 10); j++) {
      for (ll k = 1; k <= 10 and k <= A[i]; k++)dp[i][ins(j, k)] = (dp[i][ins(j, k)] % mod + dp[i - 1][j]) % mod;
      if (A[i] > 10)dp[i][j] = (dp[i][j] + dp[i - 1][j] % mod * (A[i] - 10) % mod) % mod;
    }
  }
  ll ans = 0;
  for (ll i = 0; i < (1 << 10); i++) {
    if ((i >> 9) & 1)ans = (ans % mod + dp[n][i]) % mod;
  }
  cout << ans % mod*ksm(pre[n], mod - 2) % mod << endl;
}
signed main() {
  solve();
}