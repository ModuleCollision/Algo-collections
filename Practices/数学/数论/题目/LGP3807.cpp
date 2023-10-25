#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll p;
/*Lucas定理*/
ll fac[maxn];
void init() {
  cin >> p; fac[0] = 1;
  for (ll i = 1; i <= p; i++) {
    fac[i] = (fac[i - 1] % p * i) % p;
  }
}
ll ksm(ll a, ll b) {
  ll ret = 1;
  while (b) {
    if (b & 1)ret = ret * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ret % p;
}
ll inv(ll x) {
  return ksm(x, p - 2) % p;
}
ll comb(ll n, ll m) {
  if (m > n)return 0ll;
  return fac[n] % p * inv(fac[n - m] % p * fac[m]) % p;
}
ll lucas(ll n, ll m) {
  if (m == 0)return 1;
  return ((comb(n % p, m % p)) * lucas(n / p, m / p)) % p;
}
void solve() {
  ll n, m; cin >> n >> m;
  init();
  cout << lucas(n + m, m) << endl;
}
signed main() {
  ll T; cin >> T;
  while (T--)
    solve();
}