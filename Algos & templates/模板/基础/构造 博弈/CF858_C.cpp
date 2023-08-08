#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1000005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll prime[maxn]; bool vis[maxn]; ll cnt = 0;
ll buf[maxn];
void solve() {
  ll n;
  std::cin >> n; vector<ll>A(2 * n + 5, 0);
  ll ans = 0, sum = 0;
  for (ll i = 1; i <= (n << 1); i++) {
    std::cin >> A[i]; ans += abs(A[i]);
    sum += abs(A[i] + 1);
  }
  if (n == 1) {
    ans = min(ans, A[1] - A[2]);
  } else if (n == 2) {
    ans = min(ans, abs(A[1] - 2) + abs(A[2] - 2) + abs(A[3] - 2) + abs(A[4] - 2));
  }
  if (not(n & 1)) {
    for (ll i = 1; i <= (n << 1); i++) {
      ans = min(ans, sum - abs(A[i] + 1) + abs(A[i] - n));
    }
  }
  cout << abs(ans) << endl;
}
signed main() {

  ll T; std::cin >> T;
  while (T--)
    solve();
}