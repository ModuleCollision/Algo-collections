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

i64 fa[maxn];
i64 dis[maxn][30]; i64 p[maxn][30]; i64 dep[maxn];
i64 find(i64 x) {
  while (x != fa[x])
    x = fa[x] = fa[fa[x]];
  return x;
}
bool same(i64 x, i64 y) {
  return find(x) == find(y);
}
void merge(i64 x, i64 y) {
  i64 a = find(x), b = find(y);
  fa[a] = b;
}
void solve() {
  i64 n, m, q;
  std::cin >> n >> m >> q;
  vector<array<i64, 3>> w;
  std::iota(fa + 1, fa + 1 + n, 1);
  vector<vector<array<i64, 2>>> tr(n + 1);
  for (i64 i = 1; i <= m; i++) {
    i64 u, v, c;
    std::cin >> u >> v >> c;
    w.push_back({u, v, c});
  }
  std::sort(w.begin(), w.end(), [&](auto q, auto s) -> bool {
    return q[2] < s[2];
  });
  for (auto [u, v, c] : w) {
    if (same(u, v))
      continue;
    merge(u, v);
    tr[u].push_back({v, c});
    tr[v].push_back({u, c});
  }
  function<void(i64, i64)> dfs = [&](i64 u, i64 f) {
    p[u][0] = f;
    dep[u] = dep[p[u][0]] + 1;
    for (i64 i = 1; (1 << i) <= dep[u]; i++) {
      p[u][i] = p[p[u][i - 1]][i - 1];
      dis[u][i] = max(dis[u][i - 1], dis[p[u][i - 1]][i - 1]);
    }
    for (auto [x, y] : tr[u]) {
      if (x == f)
        continue;
      dis[x][0] = y;
      dfs(x, u);
    }
  };
  auto lca = [&](i64 u, i64 v) {
    i64 ret = 0;
    if (dep[u] < dep[v])
      swap(u, v);
    if (dep[u] != dep[v]) {
      for (i64 i = log2(dep[u] - dep[v]); i >= 0; i--) {
        if (dep[p[u][i]] >= dep[v]) {
          ret = max(ret, dis[u][i]);
          u = p[u][i];
        }
      }
    }
    if (u == v)
      return ret;
    for (i64 i = log2(dep[u]); i >= 0; i--) {
      if (p[u][i] != p[v][i]) {
        ret = max(ret, dis[u][i]);
        ret = max(ret, dis[v][i]);
        u = p[u][i];
        v = p[v][i];
      }
    }
    if (u != v) {
      ret = max(ret, dis[u][0]);
      ret = max(ret, dis[v][0]);
    }
    return ret;
  };
  dfs(1, 0);
  while (q--) {
    i64 u, v, c;
    std::cin >> u >> v >> c;
    i64 lc = lca(u, v);
    // cout << "#" << lc << " " << endl;
    if (c <= lc) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
}
signed main() {
  solve();
}