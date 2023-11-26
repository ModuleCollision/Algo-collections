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
  i64 l = 0, r = 0;
  vector<array<i64, 3>>e(m + 1); vector<vector<pair<i64, i64>>>g(n + 1);
  for (i64 i = 1; i <= m; i++) {
    i64 u, v, w; cin >> u >> v >> w;
    e[i] = {u, v, w}; r = max(r, w);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector<i64>c(n + 5, 0);

  auto check = [&](i64 x) {
    function<bool(i64)>dfs = [&](i64 u)->bool {
      for (auto [v, w] : g[u]) {
        if (w < x)continue;
        if (c[v]) {
          if (c[v] == c[u])
            return false;
        } else {
          c[v] = 3 - c[u]; bool f = dfs(v);
          if (not f)return false;
        }
      }
      return true;
    };
    std::fill(c.begin() + 1, c.begin() + 1 + n, 0ll);
    for (i64 i = 1; i <= n; i++) {
      if (c[i])continue;
      c[i] = 1; bool f = dfs(i);
      if (not f)return false;
    }
    return true;
  };
  i64 ans = -1; r++;
  while (l + 1 < r) {
    i64 mid = (l + r) >> 1;
    if (check(mid))r = mid;
    else l = mid;
  }
  cout << l << "\n";
}
signed main() {
  solve();
}