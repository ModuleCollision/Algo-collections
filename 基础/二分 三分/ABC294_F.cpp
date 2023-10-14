/*浮点二分模板*/
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
void solve() {
  ll n, m, k; std::cin >> n >> m >> k;
  vector<pair<ll, ll>>p(n + 1), q(m + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> p[i].fi >> p[i].se;
  }
  for (ll i = 1; i <= m; i++) {
    cin >> q[i].fi >> q[i].se;
  }
  db l = 0.0000, r = 100.00000;
  auto check = [&](db mid) {
    mid /= 100.0;
    vector<db>s1(n + 1), s2(m + 1);
    for (ll i = 1; i <= n; i++) {
      s1[i] = (1.0 - mid) * p[i].fi - mid * p[i].se;
    }
    for (ll i = 1; i <= m; i++) {
      s2[i] = (mid - 1.0) * q[i].fi + mid * q[i].se;
      s2[i] = -s2[i];
    }
    ll ret = 0;
    sort(s2.begin() + 1, s2.begin() + 1 + m);
    for (ll i = 1; i <= n; i++) {
      ll idx = lower_bound(s2.begin() + 1, s2.begin() + 1 + m, -s1[i]) - s2.begin();
      ret += m - idx + 1;
    }
    return ret >= k;
  };
  while (r - l > 0.0000000001) {
    db mid = (r + l) / 2;
    if (check(mid))l = mid;
    else r = mid;
  }
  printf("%.10lf\n", l);
}
signed main() {
  solve();
}