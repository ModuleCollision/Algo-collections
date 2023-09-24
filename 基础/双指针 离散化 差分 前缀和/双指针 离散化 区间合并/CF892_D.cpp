#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n, ans = 0; std::cin >> n;
  vector<pair<ll, ll>>w;
  for (ll i = 1; i <= n; i++) {
    ll q1, q2, q3, q4; cin >> q1 >> q2 >> q3 >> q4;
    w.push_back({q1, q4});
  }
  std::sort(w.begin(), w.end(), [&](pair<ll, ll>x, pair<ll, ll>y)->bool{
    if (x.fi != y.fi)return x.fi < y.fi;
    return x.se < y.se;
  });
  ll cnt = 0; vector<pair<ll, ll>>p(n + 1);
  for (auto [l, r] : w) {
    if (cnt and l <= p[cnt].se)p[cnt].se = max(p[cnt].se, r);
    else p[++cnt] = {l, r};
  }//区间合并
  ll q; std::cin >> q;
  while (q--) {
    ll x; std::cin >> x;
    auto idx = upper_bound(p.begin() + 1, p.begin() + 1 + cnt, pair<ll, ll> {x, 1e18}) - p.begin() - 1;
    if (x >= p[idx].fi and x <= p[idx].se)x = max(x, p[idx].se);
    cout << x << " ";
  }
  cout << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}