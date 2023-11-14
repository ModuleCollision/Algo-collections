#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e3 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 998244353;
ll n, k;
ll p = 0;
vector<ll>st[maxn];
pair<ll, ll>c[maxn]; //记录编号的状压与个数
ll dp[15][1005][1005];
void solve() {
  cin >> n >> k;
  function<void(ll, ll, ll, ll)>dfs = [&](ll idx, ll r, ll val, ll cnt) {
    if (idx >= n) {
      auto &[x, y] = c[++p];
      st[r].push_back(p);
      x = val, y = cnt;
      return;
    }
    bool f = true;
    if (idx > 0 and ((val >> (idx - 1)) & 1)) {
      f = false;
    }
    if (f) {
      dfs(idx + 2, r, val + (1 << idx), cnt + 1);
    }
    dfs(idx + 1, r, val, cnt);
  };
  for (ll i = 1; i <= n; i++) {
    dfs(0, i, 0, 0);
  }
  for (auto s : st[1]) {
    dp[1][s][c[s].second] = 1;
  }
  auto check = [&](ll v1, ll v2)->bool{
    if ((v1 >> 1)&v2) {
      return false;
    }
    if ((v1 << 1)&v2) {
      return false;
    }
    if (v1 & v2) {
      return false;
    }
    return true;
  };
  for (ll cnt = 0; cnt <= k; cnt++) {
    for (ll i = 2; i <= n; i++) {
      for (auto s : st[i]) {
        for (auto d : st[i - 1]) {
          if (cnt >= c[s].second) {
            if (check(c[s].first, c[d].first)) {
              dp[i][s][cnt] += dp[i - 1][d][cnt - c[s].second];
            }
          }
        }
      }
    }
  }
  ll ans = 0;
  for (auto s : st[n]) {
    ans += dp[n][s][k];
  }
  cout << ans << endl;
}
signed main() {
  solve();
}