#include<bits/stdc++.h>
using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
  int n, m; i64 k; cin >> n >> m >> k;
  vector<pair<i64, i64>>e(m + 1);
  vector<i64>a(n + 1);
  for (int i = 1; i <= n; i++)cin >> a[i];
  vector<vector<int>>g(n + 1);
  for (int i = 1; i <= m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
  }
  vector<int>dp(n + 1, 0);
  auto check = [&](i64 x) {
    std::fill(dp.begin() + 1, dp.begin() + 1 + n, 0);
    vector<int>dd(n + 1, 0);
    for (int i = 1; i <= n; i++)g[i].clear();
    int cnt = 0; queue<int>q;
    for (int i = 1; i <= n; i++) {
      if (a[i] > x)continue;
      for (auto v : g[i]) {
        if (a[v] > x)continue;
        dd[v]++;
      }
    }
    int m = 0;
    for (int i = 1; i <= n; i++) {
      if (not dd[i])q.push(i), cnt++, dp[i] = 1;
    }
    while (q.size()) {
      auto u = q.front(); q.pop();
      m = max(m, dp[u]);
      for (auto v : g[u]) {
        if (a[v] > x)continue;
        dp[v] = max(dp[v], dp[u] + 1);
        dd[v]--; if (not dd[v]) {
          q.push(v), cnt++;
        }
      }
    }
    return cnt < n or m >= k;
  };
  i64 r = 1e15;
  i64 l = 0; i64 ans = -1;
  while (l <= r) {
    i64 mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid - 1, ans = mid;
    } else l = mid + 1;
  }
  cout << ans << "\n";
}
signed main() {
  solve();
}