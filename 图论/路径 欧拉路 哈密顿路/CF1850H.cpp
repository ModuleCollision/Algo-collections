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

void solve() {
  i64 n, m; std::cin >> n >> m; bool flag = true;
  vector<vector<pair<i64, i64>>>g(n + 1);
  vector<i64>val(n + 1, 0);
  vector<array<i64, 3>>e(m + 1);
  for (i64 i = 1; i <= m; i++) {
    i64 u, v, w; std::cin >> u >> v >> w;
    g[u].push_back({v, w});
    g[v].push_back({u, -w});
    e[i] = {u, v, w};
  }
  vector<bool>vis(n + 1, false);

  function<void(i64, i64 )>dfs = [&](i64 u, i64 w) {
    vis[u] = 1;
    for (auto [v, x] : g[u]) {
      if (not vis[v]) {
        val[v] = val[u] + x;
        dfs(v, w + x);
      }
    }
  };
  for (i64 i = 1; i <= n; i++) {
    if (not vis[i]) {
      dfs(i, 0);
    }
  }
  for (i64 i = 1; i <= m; i++) {
    auto [u, v, w] = e[i];
    if (val[u] + w != val[v]) {
      puts("NO"); return;
    }
  }
  puts("YES");
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}