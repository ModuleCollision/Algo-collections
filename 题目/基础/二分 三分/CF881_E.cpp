#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, m; std::cin >> n >> m;
  map<ll, pair<ll, ll>>ks;
  vector<ll>cnt(m + 5);
  std::map<pair<ll, ll>, ll>sk;
  for (ll i = 1; i <= m; i++) {
    ll l, r; std::cin >> l >> r;
    ks[i] = {l, r};
    sk[ {l, r}] = i;
  }
  ll q; std::cin >> q; vector<ll>xx(q + 5);
  for (ll i = 1; i <= q; i++) {
    std::cin >> xx[i];
  }
  ll l = 1, r = q + 1, ans = 0;
  auto check = [&](ll mid) {
    vector<ll>d(n + 5);
    for (ll i = 1; i <= mid; i++) {
      d[xx[i]]++;
    }
    for (ll i = 1; i <= n; i++) {
      d[i] += d[i - 1];
    }
    for (ll i = 1; i <= m; i++) {
      ll l = ks[i].first, r = ks[i].second;
      ll len = (r - l + 1);
      ll c = d[r] - d[l - 1];
      if (c >= (len) / 2 + 1) {
        return true;
      }
    }
    return false;
  };
  bool f = 0;
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (r == q + 1)
    puts("-1"); else cout << r << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)solve();
}