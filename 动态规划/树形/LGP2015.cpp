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
pair<i64, i64>g[105][105];
void solve() {
  i64 n, q; cin >> n >> q;
  vector<vector<pair<i64, i64>>>tr(n + 1);
  for (i64 i = 1; i <= n - 1; i++) {
    i64 u, v, w; cin >> u >> v >> w;
    tr[u].push_back({v, w});
    tr[v].push_back({u, w});
  }
  vector<i64>sz(n + 1);
  vector dp(n + 1, vector<i64>(q + 1, 0));
  function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
    sz[u] = 1;
    for (auto [v, w] : tr[u]) {
      if (v == f)continue;
      dfs(v, u);
      vector<i64>tmp(sz[u] + sz[v] + 1, 0);
      for (i64 j = min(sz[u] - 1, q); j >= 0; j--) {
        for (i64 k = min(sz[v], q - j - 1); k >= 0; k--) {
          tmp[j + k + 1] = max(tmp[j + k + 1], dp[u][j] + dp[v][k] + w);
        }
      }
      for (i64 j = min(sz[u] - 1, q); j >= 0; j--) {
        tmp[j] = max(tmp[j], dp[u][j]);
      }
      for (i64 j = 0; j <= min(sz[v] + sz[u] - 1, q); j++) {
        dp[u][j] = tmp[j];
      }
      sz[u] += sz[v];
    }
  };
  dfs(1, 0);
  cout << dp[1][q] << "\n";
}
signed main() {
  solve();
}