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
ll cnt = 0; ll prime[maxn]; bool vis[maxn];
void init() {
  for (ll i = 2; i <= 1e6; i++) {
    if (not vis[i]) {
      prime[++cnt] = i;
    }
    for (ll j = 1; j <= cnt and i * prime[j] <= 1e6; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0)break;
    }
  }
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
  init(); ll k = 1; ll b = 0;
  for (ll i = 1; i <= cnt; i++) {
    k *= prime[i];
    if (k > 1e9) {
      b = i; break;
    }
  }
  vector<ll>r;//模数
  vector<ll>d;//余数
  for (ll i = 1; i <= b; i++) {
    r.push_back(prime[i]);
    cout << prime[i] << endl; cout << flush;
    for (ll j = 1; j <= prime[i]; j++) {
      cout << (j) % prime[i] + 1 << " \n"[j == prime[i]];
    }
    cout << flush; ll v = 0;
    for (ll j = 1; j <= prime[i]; j++) {
      ll t; cin >> t; if (j == 1)v = t;
    }
    d.push_back(abs(v - 1));
  }
  ll ans = 0;
  for (ll i = 0; i < b; i++) {
    ll m = k / r[i], s, y;
    exgcd(m, r[i], s, y);
    ans = (ans % k + d[i] % k * s % k * m % k) % k;
  }
  cout << (ans % k + k) % k << endl;
}
signed main() {
  solve();
}