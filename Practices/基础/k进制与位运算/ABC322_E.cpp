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
  int n, k, p; std::cin >> n >> k >> p;
  auto conv = [&](int x) {
    vector<int>ret;
    while (x) {
      ret.push_back(x % (p + 1)); x /= (p + 1);
    }
    return ret;
  };
  auto con2dec = [&](vector<int>f) {
    int ret = 0; for (auto c : f) {
      ret = (ret * (p + 1) + c);
    }
    return ret;
  };
  vector<int>c(n + 1); vector a(n + 1, vector<int>(k + 1, 0));
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 1; j <= k; j++)cin >> a[i][j];
  }
  vector dp(n + 1, vector<int>(100005, 0x3f3f3f3f)); dp[0][0] = 0;
  int mx = 1; for (int i = 1; i <= k; i++)mx *= (p + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= mx - 1; j++) {
      auto r = conv(j);
      while (r.size() < k)r.push_back(0);
      reverse(r.begin(), r.end());
      for (int q = 0; q < k; q++) {
        r[q] = min(p, r[q] + a[i][q + 1]);
      }
      int f = con2dec(r);
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      dp[i][f] = min(dp[i][f], dp[i - 1][j] + c[i]);
    }
  }
  if (dp[n][mx - 1] == 0x3f3f3f3f) {
    puts("-1");
  } else cout << dp[n][mx - 1] << endl;
}
signed main() {
  solve();
}