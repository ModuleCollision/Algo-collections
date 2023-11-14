#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, x, y; std::cin >> n >> x >> y;
  vector<ll>p(n + 1), t(n + 1);
  for (ll i = 1; i <= n - 1; i++)cin >> p[i] >> t[i];
  vector<ll>dp(845, 0);
  for (ll i = 0; i < 840; i++) {
    ll T = i; T += x;
    for (ll j = 1; j <= n - 1; j++) {
      T += (p[j] - (T % p[j])) % p[j];
      T += t[j];
    }
    T += y; dp[i] = T - i;
  }
// for (ll i = 0; i <= 840; i++)cout << dp[i] << endl;
  ll Q; std::cin >> Q;
  while (Q--) {
    ll q; std::cin >> q;
    ll ans = dp[q % 840];
    ans += q;
    cout << ans << endl;
  }
}
signed main() {
  solve();
}