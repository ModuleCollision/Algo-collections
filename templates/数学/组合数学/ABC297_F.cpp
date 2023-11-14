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
ll fac[maxn];
void init() {
  fac[0] = 1;
  for (ll i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
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
  if (n < m)return 0ll;
  return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
  ll ans = 0; init();
  ll h, w, k; std::cin >> h >> w >> k;
  if (k == 1) {
    cout << 1 << endl; return;
  }
  for (ll i = 1; i <= h; i++) {
    for (ll j = 1; j <= w; j++) {
      ll cur = 0;
      for (ll u = 0; u <= 2; u++) {
        for (ll v = 0; v <= 2; v++) {
          cur += comb((i - u) * (j - v), k) % mod * (v == 1 ? -2 : 1) % mod * (u == 1 ? -2 : 1);
          cur = (cur % mod + mod) % mod;
        }
      }
      ans = (ans % mod + cur % mod * i * j * (h - i + 1) % mod * (w - j + 1) % mod) % mod;
    }
  }
  ans = (ans % mod * inv(comb(h * w, k))) % mod;
  cout << ans << endl;
}
signed main() {

  solve();
}