#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n; std::cin >> n; vector<ll>A(n + 5, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
  vector cnt(35, vector<ll>(2, 0)); ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 30; j >= 0; j--) {
      ll c = (A[i] >> j) & 1; ll cc = c ^ 1;
      ans = (ans % mod + (1 << j) % mod * cnt[j][cc] % mod * (n - i + 1) % mod) % mod;
      cnt[j][c] += i;
    }
  }
  cout << ans << endl;
}
signed main() {
  solve();
}