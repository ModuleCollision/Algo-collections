#include<bits/extc++.h>

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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

 i64 fa[maxn][30];  i64 dep[maxn];
void solve() {
   i64 n, m, k; std::cin >> n >> m >> k;
  vector< i64>A(m + 1, 0); for ( i64 i = 1; i <= m; i++)cin >> A[i];
  vector<vector<pair< i64,  i64>>>tr(n + 1);
  vector< i64>d(n + 1, 0);
  for ( i64 i = 1; i <= n - 1; i++) {
     i64 u, v; std::cin >> u >> v;
    tr[u].push_back({v, i});
    tr[v].push_back({u, i});
  }
  vector< i64>p(n + 1);//节点转化为边差分
  function<void( i64,  i64)>dfs = [&]( i64 u,  i64 f) {
    fa[u][0] = f;
    dep[u] = dep[fa[u][0]] + 1;
    for ( i64 i = 1; (1 << i) <= dep[u]; i++) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for (auto [v, i] : tr[u]) {
      if (v == f)continue;
      p[v] = i; dfs(v, u);
    }
  };
  dfs(1, 0);
  auto lca = [&]( i64 u,  i64 v) {
    if (dep[u] < dep[v])swap(u, v);
    if (dep[u] != dep[v]) {
      for ( i64 i = log2(dep[u] - dep[v]); i >= 0; i--) {
        if (dep[fa[u][i]] >= dep[v]) {
          u = fa[u][i];
        }
      }
    }
    if (u == v)return u;
    for ( i64 i = log2(dep[u]); i >= 0; i--) {
      if (fa[u][i] != fa[v][i]) {
        u = fa[u][i]; v = fa[v][i];
      }
    }
    if (u != v) {
      u = fa[u][0];
    }
    return u;
  };
  for ( i64 i = 1; i <= m - 1; i++) {
     i64 u = A[i], v = A[i + 1];
     i64 lc = lca(u, v);
    d[p[u]]++; d[p[v]]++;
    d[p[lc]] -= 2;
  }
  function<void( i64,  i64)>dfs2 = [&]( i64 u,  i64 f) {
    for (auto [v, i] : tr[u]) {
      if (v == f)continue;
      dfs2(v, u);
      d[p[u]] += d[i];
    }
  };
  dfs2(1, 0);
   i64 tot = accumulate(d.begin() + 1, d.begin() + 1 + n, 0);
  vector dp(n + 1, vector< i64>(tot + 1, 0));
  dp[0][0] = 1;
  for ( i64 i = 1; i <= n - 1; i++) {
    for ( i64 j = tot; j >= 0; j--) {
      dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
      if (j >= d[i])
        dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - d[i]]) % mod;
    }
  }  i64 ans = 0;
  for ( i64 i = 0; i <= tot; i++)if (i + i - tot == k)ans = (ans % mod + dp[n - 1][i]) % mod;
  cout << ans << endl;
}
signed main() {
  solve();
}