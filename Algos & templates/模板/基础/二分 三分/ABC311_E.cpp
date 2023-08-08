#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 25;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll H, W, N; std::cin >> H >> W >> N;
  vector pre(H + 5, vector<ll>(W + 5, 0));
  for (ll i = 1; i <= H; i++) {
    for (ll j = 1; j <= W; j++)pre[i][j] = 1;
  }
  std::set<pair<ll, ll>>c;
  vector f(H + 5, vector<bool>(W + 5, false));
  while (N--) {
    ll x, y; std::cin >> x >> y;
    f[x][y] = 1;
    pre[x][y] = 0;
  }
  for (ll i = 1; i <= H; i++) {
    for (ll j = 1; j <= W; j++) {
      pre[i][j] = (pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
    }
  }
  auto query = [&](ll x1, ll y1, ll x2, ll y2) {
    return pre[x1][y1] - pre[x2 - 1][y1] - pre[x1][y2 - 1] + pre[x2 - 1][y2 - 1];
  };
  auto check = [&](ll x1, ll y1, ll x2, ll y2) {
    return query(x1, y1, x2, y2) == ((x1 - x2 + 1) * (y1 - y2 + 1));
  };
  ll res = 0;
  for (ll i = 1; i <= H; i++) {
    for (ll j = 1; j <= W; j++) {
      ll ans = 0;
      if (f[i][j])continue;
      ll l = 1, r = min(H - i + 1, W - j + 1);
      while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(i + mid - 1, j + mid - 1, i, j)) {
          l = mid + 1; ans = mid;
        } else {
          r = mid - 1;
        }
      }
      if (check(i + ans - 1, j + ans - 1, i, j))
        res += ans;
      /*ll l = 0, r = min(H - i + 1, W - j + 1);
      while (l < r) {
        ll mid = (l + r + 1) >> 1;
        if (check(i + mid - 1, j + mid - 1, i, j)) {
          l = mid; ans = mid;
        } else {
          r = mid - 1;
        }
      }*/
    }
  }
  cout << res << endl;
}
signed main() {
  solve();
}