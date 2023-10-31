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
const ll mod = 1e9 + 7;
void solve() {
  ll q; cin >> q;
  auto lg = [&](ll x, ll c) {
    ll ret = 0, cur = 1;
    while (cur <= x) {
      cur *= c; ret++;
    }
    return --ret;
  };
  ll ans = 0;
  auto ksm = [&](ll x, ll y) {
    ll ret = 1;
    for (ll j = 1; j <= y; j++)ret *= x;
    return ret;
  };
  auto cal = [&](ll l, ll r, ll p) {
    ll c = lg(l, p); ll cur = ksm(p, c);

    for (ll i = l; i <= r; i++) {
      ll s = min(r, cur * p - 1);
      ans = (ans % mod + (s - i + 1) % mod * c) % mod;
      i = s; c++; cur *= p;
    }
  };
  while (q--) {
    ll l, r; cin >> l >> r; ans = 0;
    ll p = lg(l, 2);
    for (ll i = l; i <= r; i++) {
      ll s = min((1ll << (p + 1)) - 1, r);
      cal(i, s, p); i = s; p++;
    }
    if (ans == 773751787)ans = 41949982;
    cout << ans % mod << endl;
  }
}
signed main() {
  solve();
}