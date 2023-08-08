#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  auto ksm = [&](ll a, ll b) {
    ll ret = 1;
    while (b) {
      if (b & 1)ret = ret * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ret;
  };
  auto inv = [&](ll x) {
    return ksm(x, mod - 2) % mod;
  };
  ll n, p, q; std::cin >> n >> p >> q;
  ll ws = p % mod * inv(q) % mod;
  vector<ll>f(n + 5, 0);
  f[0] = 0; f[1] = 1;
  for (ll i = 2; i <= n; i++) {
    f[i] = (f[i] % mod + f[i - 1] % mod + f[i - 2] % mod) % mod;
  }
  vector C(n + 5, vector<ll>(n + 5, 0));
  for (ll i = 0; i <= n; i++) {
    for (ll j = 0; j <= i; j++)
      if (not j)C[i][j] = 1;
      else C[i][j] = (C[i - 1][j] % mod + C[i - 1][j - 1]) % mod;
  }
  vector<ll>dp(n + 5, 0);//此为概率逆推
  for (ll i = 1; i <= n; i++) {
    dp[i] = (dp[i] % mod + f[n - i + 1]) % mod;
    for (ll j = 1; j <= i; j++) {
      ll wss = ((1 - ws) % mod + mod) % mod;
      //枚举可以转移到的状态然后求和
      ll v = (dp[i - j] % mod * C[i][j] % mod * ksm(ws, j) % mod * ksm(wss, i - j)) % mod;
      dp[i] = (dp[i] % mod + v) % mod;
    }
    ll wss = ((1 - ws) % mod + mod) % mod;
    ll p = ((1 - ksm(wss, i)) % mod + mod) % mod;
    dp[i] = ((dp[i]) % mod * inv(p)) % mod;
  }
  cout << dp[n] % mod << endl;
  //为n最终全部发送完的期望代价
}
signed main() {
  solve();
}