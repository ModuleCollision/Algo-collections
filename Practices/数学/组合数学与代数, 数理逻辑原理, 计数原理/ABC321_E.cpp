#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e4 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  auto solve = [&](ll x, ll k, ll n) {
    if (k < 0)return 0ll;
    if (k >= 64)return 0ll;
    ll num = (1 << k), l = x;
    l <<= k; ll r = l + num - 1;
    if (l > n)return 0ll;
    ll ret = min(r, n) - l + 1;
    return ret;
  };
  ll T; std::cin >> T;
  while (T--) {
    ll n, x, k; std::cin >> n >> x >> k;
    ll ans = 0;
    if (k)ans += solve(x, k, n);
    while (x > 1 and k > 0) {
      --k; ans += solve(x ^ 1, k - 1, n);
      x >>= 1;
    }
    if (x and k == 0)ans++;
    cout << ans << endl;
  }
}
signed main() {
  solve();
}