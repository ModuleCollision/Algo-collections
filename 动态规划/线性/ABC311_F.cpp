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
ll fac[maxn];
void init() {
  fac[0] = 1;
  for (ll i = 1; i <= 1e6; i++) {
    fac[i] = (fac[i - 1] % mod * i) % mod;
  }
}
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
  fac[n] % mod*inv(fac[n - m] % mod * fac[m]) % mod;
}
void solve() {
  init(); ll n, m; std::cin >> n >> m;
  vector<ll>w(m + 1);
  vector<string>s(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> s[i]; s[i] = " " + s[i];
  }
  for (ll i = 1; i <= m; i++) {
    w[i] = n + 1;
    for (ll j = n; j >= 1; j--)if (s[j][i] == '#')w[i] = j;
  }
  vector dp(m + 5, vector<ll>(n + 5, 0));
  vector p(m + 5, vector<ll>(n + 5, 0));
  for (ll i = 0; i <= n + 1; i++) {
    p[0][i] = 1;
  }
  for (ll i = 1; i <= m; i++) {
    for (ll j = w[i]; j >= 1; j--) {
      dp[i][j] = (dp[i][j] % mod + p[i - 1][j - 1]) % mod;
    }
    for (ll j = n + 1; j >= 0; j--)p[i][j] = (p[i][j + 1] % mod + dp[i][j]) % mod;
  }
  ll ans = 0;
  cout << p[m][1] << endl;
}
signed main() {
  solve();
}