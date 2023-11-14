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
ll exgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1; y = 0; return a;
  }
  ll d = exgcd(b, a % b, x, y);
  ll tmp = x; x = y; y = tmp - a / b * y;
  return d;
}
void solve() {
  vector<ll>r;//模数
  vector<ll>d;//余数
  ll n; cin >> n; ll k = 1;
  for (ll i = 1; i <= n; i++) {
    ll u, v; cin >> u >> v;
    k *= u; r.push_back(u); d.push_back(v);
  }
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll m = k / r[i], b, y;
    exgcd(m, r[i], b, y);
    ans = (ans % k + d[i] % k * b % k * m % k) % k;
  }
  cout << (ans % k + k) % k << endl;
}
signed main() {
  solve();
}