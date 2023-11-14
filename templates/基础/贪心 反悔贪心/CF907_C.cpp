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
const ll mod = 998244353;
void solve() {
  ll n; cin >> n;
  vector<ll>a(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> a[i];
  sort(a.begin() + 1, a.begin() + 1 + n);
  ll x = 0, ans = 0, i = 1, j = n;
  while (i < j) {
    if (x + a[i] >= a[j]) {
      ll t = a[j] - x;
      ans += t + 1;
      j--; a[i] -= t; x = 0;
    } else {
      x += a[i]; ans += a[i++];
    }
  }
  if (a[i] == 0) {
    cout << ans << "\n";
    return;
  }
  ll k = a[j] - x;
  ans += (k % 2 ? (a[j] == 1 ? 1 : k / 2 + 2) : k / 2 + 1);
  cout << ans << "\n";
}
signed main() {
  ll T; cin >> T;
  while (T--)
    solve();
}