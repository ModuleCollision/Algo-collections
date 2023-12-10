#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  string s; std::cin >> s;
  ll len = s.size(); s = " " + s;
  ll m; std::cin >> m;
  string l, r; std::cin >> l >> r; l = " " + l; r = " " + r;
  vector dp(len + 5, vector<ll>(m + 5, 0));
  dp[0][0] = 1;
  for (ll i = 1; i <= len; i++) {
    for (ll j = 0; j <= m; j++) {
      dp[i][j] |= dp[i - 1][j];
      if (j >= 1) {
        for (auto k = l[j]; k <= r[j]; k++) {
          if (k == s[i])continue;
          dp[i][j] |= dp[i - 1][j - 1];
        }
      }
    }
  }
  if (dp[len][m]) {
    puts("YES");
  } else {
    puts("NO");
  }
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}