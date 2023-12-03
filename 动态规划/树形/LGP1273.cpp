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
  i64 n, m; cin >> n >> m;
  vector<vector<pair<i64, i64>>>g(n + 1);
  for (i64 i = 1; i <= n - m; i++) {
    i64 k; cin >> k;
    for (i64 j = 1; j <= k; j++) {
      i64 a, c; cin >> a >> c;
      g[i].push_back({a, c});
      g[a].push_back({i, c});
    }
  }
  vector<i64>q(n + 1), sz(n + 1);
  for (i64 i = n - m + 1; i <= n; i++)cin >> q[i];
  vector dp(n + 1, vector (m + 1, -inf));
  //u 子树选了 v个数, 能获得的最大利润
  vector<i64>dis(n + 1);
  auto check = [&](i64 x) {
    return x >= n - m + 1 and x <= n;
  };
  function<void(i64, i64, i64)>dfs1 = [&](i64 x, i64 y, i64 d) {
    dis[x] = d;
    for (auto [v, w] : g[x]) {
      if (v == y)continue;
      dfs1(v, x, d + w);
    }
  };
  i64 ans = 0;
  dfs1(1, 0, 0);
  function<void(i64, i64)>dfs2 = [&](i64 u, i64 f) {
    dp[u][0] = 0;
    if (check(u)) {
      sz[u] = 1;
      dp[u][1] = q[u];
      return;
    }
    for (auto [v, w] : g[u]) {
      if (v == f)continue;
      dfs2(v, u);
      vector<i64>tmp(sz[u] + sz[v] + 1, -inf);
      for (i64 i = 0; i <= sz[u]; i++) {
        for (i64 j = 0; j <= sz[v]; j++) {
          tmp[i + j] = max(tmp[i + j], dp[u][i] + dp[v][j] - (j ? w : 0));
        }
      }
      for (i64 j = 0; j <= sz[u] + sz[v]; j++) {
        dp[u][j] = max(dp[u][j], tmp[j]);
        if (dp[u][j] - dis[u] >= 0)ans = max(ans, j);
      }
      sz[u] += sz[v];
    }
  };
  dfs2(1, 0);
  cout << ans << "\n";
}
signed main() {
  solve();
}