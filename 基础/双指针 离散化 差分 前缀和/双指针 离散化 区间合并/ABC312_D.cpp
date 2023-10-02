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
  ll n, m, p; std::cin >> n >> m >> p;
  vector<ll>A(n + 5);
  vector<ll>B(m + 5);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  for (ll i = 1; i <= m; i++)cin >> B[i];
  sort(A.begin() + 1, A.begin() + 1 + n);
  sort(B.begin() + 1, B.begin() + 1 + m);
  vector<ll>pre(m + 1);
  for (ll i = 1; i <= m; i++)pre[i] = (pre[i - 1] + B[i]);
  ll ans = 0;
  for (ll i = 1, j = m; i <= n; i++) {
    while (A[i] + B[j] >= p and j >= 1)j--;
    ans += (m - j) * p;
    ans += (j) * A[i] + (pre[j]);
  }
  cout << ans << endl;
}
signed main() {
  solve();
}