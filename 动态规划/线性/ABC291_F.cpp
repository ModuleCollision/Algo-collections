#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 305;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
string s;
void solve() {
  ll n, m; std::cin >> n >> m;
  vector<ll>w(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> s;
    for (ll j = 0; j < s.size(); j++) {
      if (s[j] == '1')w[i] += (1 << j);
    }
  }
  vector<ll>dp1(n + 1, inf); dp1[n] = 0;
  for (ll i = n - 1; i >= 1; i--) {
    for (ll j = 0; j < m; j++) {
      if ((w[i] >> j) & 1) {
        dp1[i] = min(dp1[i], dp1[i + j + 1] + 1);
      }
    }
  }
  vector<ll>dp2(n + 1, inf); dp2[1] = 0;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j < m; j++) {
      if ((w[i] >> j) & 1)dp2[i + j + 1] = min(dp2[i + j + 1], dp2[i] + 1);
    }
  }
  vector<ll>ans(n + 1, inf);
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j < m; j++) {
      if ((w[i] >> j) & 1) {
        for (ll k = i + 1; k < i + j + 1; k++)ans[k] = min(ans[k], dp2[i] + dp1[i + j + 1] + 1);
      }
    }
  }
  for (ll i = 2; i <= n - 1; i++) {
    if (ans[i] >= inf) {
      cout << -1 << " ";
    } else cout << ans[i] << " ";
  }
  cout << endl;
}
signed main() {
  solve();
}