#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  function<ll(ll, ll, ll&, ll&)>exgcd = [&](ll a, ll b, ll & x, ll & y) {
    if (b == 0) {
      x = 1; y = 0; return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll tmp = x; x = y;
    y = tmp - (a / b) * y;
    return d;
  };
  ll n, p, x, q, y;
  std::cin >> n >> p >> x >> q >> y;
  ll tot = 0;
  for (ll i = 1; i <= n; i++) {
    ll v; std::cin >> v;
    tot = (tot % n + v) % n;
  }
  ll a, b; ll d = exgcd(y, n, a, b);
  ll ans = inf;
  for (ll i = 0; i <= n; i++) {
    ll nd = (tot + i % n * x) % n;
    ll cost = p * i;
    if (nd % d)continue;
    ll c = nd / d * a;
    ll t = n / d;
    c = (c % t + t) % t;
    cost += (1 * c * q);
    ans = min(ans, cost);
  }
  if (ans == inf)puts("-1");
  else
    cout << ans << endl;
}
signed main() {
  solve();
}
/*整理后发现求a * x + tot = b * y + c * n, 枚举x做ex _ gcd 即可*/