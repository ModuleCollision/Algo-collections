#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n, k; std::cin >> n >> k;
  vector<pair<ll, ll>>w(n + 5);
  for (ll i = 1; i <= n; i++)cin >> w[i].first >> w[i].second;
  ll l = 1, r = 1e9 + 7;
  auto check = [&](ll x) {
    ll ww = 0;
    for (ll i = 1; i <= n; i++) {
      if (x <= w[i].first)ww += w[i].second;
    }
    return ww <= k;
  };
  ll ans = 0;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if (check(mid))r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}