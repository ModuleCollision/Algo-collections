#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 999911659;
ll fac[5][maxn]; ll inv[5][maxn], facinv[5][maxn];
ll mody[5] = {0, 35617, 4679, 3, 2};
ll ksm(ll x, ll y, ll p) {
  ll ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % p;
    x = x * x % p;
    y >>= 1;
  }
  return ret % p;
}
void init(ll idx) {
  fac[idx][0] = 1; fac[idx][1] = 1;
  inv[idx][1] = 1; facinv[idx][0] = 1;
  facinv[idx][1] = 1; ll p = mody[idx];
  for (ll i = 2; i <= 2e5; i++) {
    fac[idx][i] = (fac[idx][i - 1] % p * i) % p;
    inv[idx][i] = (p - p / i) % p * inv[idx][p % i] % p;
    facinv[idx][i] = (facinv[idx][i - 1] * inv[idx][i]) % p;
  }
}
ll comb(ll n, ll m, ll idx) {
  if (m > n)return 0ll; ll p = mody[idx];
  return (fac[idx][n] % p * facinv[idx][m] % p * facinv[idx][n - m] % p) % p;
}
ll lucas(ll n, ll m, ll idx) {
  if (m == 0)return 1ll; ll p = mody[idx];
  return (comb(n % p, m % p, idx) * lucas(n / p, m / p, idx)) % p;
}
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0; return a;
  }
  ll d = exgcd(b, a % b, x, y);
  ll tmp = x; x = y; y = tmp - a / b * y;
  return d;
}
void solve() {
  ll n, g; cin >> n >> g;
  vector<ll>r(1);//reminder
  for (ll j = 1; j <= 4; j++) {
    ll cur = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
        cur = (cur % mody[j] + lucas(n, i, j) % mody[j]) % mody[j];
        if (i != n / i) {
          cur = (cur % mody[j] + lucas(n, n / i, j) % mody[j]) % mody[j];
        }
      }
    }
    r.push_back(cur % mody[j]);
  }
  ll ans = 0; ll k = 999911658;
  for (ll i = 1; i <= 4; i++) {
    ll m = k / mody[i], invm, y;
    exgcd(m, mody[i], invm, y);
    invm = (invm % mody[i] + mody[i]) % mody[i];
    ans = (ans % k + r[i] % k * invm % k * m % k) % k;
  }
  ans = (ans % k + k) % k;
  cout << ksm(g, ans + k, mod) % mod << endl;
}
signed main() {
  for (ll i = 1; i <= 4; i++)init(i);
  solve();
}