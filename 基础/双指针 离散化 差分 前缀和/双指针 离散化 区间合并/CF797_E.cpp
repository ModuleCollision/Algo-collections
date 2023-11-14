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
  ll n, k; cin >> n >> k;
  vector<ll>A(n + 1, 0); ll ans = 0;
  for (ll i = 1; i <= n; i++)cin >> A[i], ans += (A[i] / k), A[i] %= k;
  sort(A.begin() + 1, A.begin() + 1 + n);
  for (ll l = 1, r = n; l < r; l++) {
    if (A[l] + A[r] < k) {
      continue;
    } else {
      ans += 1; r--;
    }
  }
  cout << ans << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}