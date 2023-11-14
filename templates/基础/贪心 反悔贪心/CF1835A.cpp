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

void solve() {
  ll a, b, c, k; cin >> a >> b >> c >> k;
  if (a > c or b > c) {
    puts("-1"); return;
  }
  auto ss = [&](ll x, ll y) {
    cout << x << " + " << y << " = " << x + y << endl;
  };
  bool f = false;
  ll w = pow(10, c - 1); ll s = pow(10, c) - 1;
  for (ll i = pow(10, a - 1); i < pow(10, a); i++) {
    ll l = max((ll)pow(10, b - 1), w - i);
    ll r = min((ll)pow(10, b) - 1, s - i);
    if (l > r)continue;
    ll q = r - l + 1;
    if (k <= q) {
      ss(i, l + k - 1);
      f = true; break;
    }
    k -= q;
  }
  if (not f) {
    puts("-1"); return;
  }
}
signed main() {
  ll T; cin >> T;
  while (T--)
    solve();
}