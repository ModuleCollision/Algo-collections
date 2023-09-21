#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n, d; std::cin >> n >> d;
  auto ksm = [&](ll x, ll y) {
    ll ret = 1; if (y < 0)return 0ll;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  }; ll ans = 0;
  for (ll i = 1; i <= (n - d); i++) {
    ll c = ksm(2, i - 1) % mod;//该层节点个数
    ll b = ((d - 1) % mod + mod) % mod * ksm(2, d - 2) % mod;
    b = (b % mod + ksm(2, d)) % mod;
    ans = (ans % mod + c % mod * b % mod) % mod;
  }
  for (ll i = n - d + 1; i <= n - (d + 1) / 2; i++) {
    ll p = d - 1 - (i - (n - d + 1)) * 2;
    ll c = ksm(2, i - 1) % mod;//该层节点个数
    p = p % mod * ksm(2, d - 2) % mod;
    ans = (ans % mod + p % mod * c % mod) % mod;
  }
  cout << ans % mod * 2 % mod << endl;
}
signed main() {
  solve();
}