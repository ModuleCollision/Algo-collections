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
const ll mod = 1e9 + 7;
ll fac[maxn];
void init() {
  fac[0] = 1;
  for (ll i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
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
ll inv(ll x) {
  return ksm(x, mod - 2) % mod;
}
ll comb(ll n, ll m) {
  return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
}
void solve() {
  init();
  ll n; cin >> n;
  vector<ll>A(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> A[i];
  }
  vector<ll>cnt(50, 0);
  for (ll j = 0; j <= 45; j++) {
    for (ll i = 1; i <= n; i++) {
      if ((A[i] >> j) & 1)cnt[j]++;
    }
  }
  ll ans = 0;
  for (ll i = 0; i <= 45; i++) {
    ll cur = ksm(2, i) % mod; ll c = cnt[i]; ll p = 0;
    ll w = ksm(2, n - c) % mod;
    for (ll j = 1; j <= c; j += 2) {
      p = (p % mod + comb(c, j) % mod) % mod;
    }
    p = (p % mod * w) % mod;
    ans = (ans % mod + p % mod * cur % mod) % mod;
  }
  cout << ans % mod << endl;
}
signed main() {
  solve();
}