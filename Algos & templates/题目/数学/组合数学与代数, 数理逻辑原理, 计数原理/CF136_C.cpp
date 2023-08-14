#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll fac[maxn * 2]; ll dp[maxn * 2][2];//几张牌, 谁赢的概率
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
ll comb(ll n, ll m) {
  return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
  fac[0] = 1;
  for (ll i = 1; i <= 1e5; i++)fac[i] = fac[i - 1] % mod * i % mod;
  dp[2][0] = 1;//Alice赢的方案数
  for (ll i = 4; i <= 1e5; i += 2) {
    //Alice拿到最大的
    dp[i][0] = (dp[i][0] % mod + comb(i - 1, i / 2 - 1) % mod) % mod;
    //Bob拿到最大的, Bob拿到次大的
    dp[i][1] = (dp[i][1] % mod + comb(i - 2, i / 2) % mod) % mod;
    //Bob拿到最大的, Alice拿到次大的
    dp[i][0] = (dp[i][0] % mod + dp[i - 2][1]) % mod;
    dp[i][1] = (dp[i][1] % mod + dp[i - 2][0]) % mod;
  }
  ll T; std::cin >> T;
  while (T--) {
    ll n; cin >> n; cout << dp[n][0] % mod << " " << dp[n][1] % mod << " " << 1 << endl;
  }
}
signed main() {
  solve();
}