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
  i64 n, k; std::cin >> n >> k;
  vector<bool>mark(n + 1, 0);
  for (i64 i = 1; i <= k; i++) {
    i64 v; cin >> v; mark[v] = true;
  }
  vector<vector<i64>>g(n + 1);
  for (i64 i = 1; i <= n - 1; i++) {
    i64 u, v; cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }
  vector<i64>mx(n + 1, -inf);
  function<void(i64, i64)>dfs1 = [&](i64 u, i64 f) {
    if (mark[u])mx[u] = max(mx[u], 0i64);
    for (auto v : g[u]) {
      if (v == f)continue;
      dfs1(v, u);
      mx[u] = max(mx[u], mx[v] + 1);
    }
  };
  vector<i64>ans(n + 1, -inf);
  function<void(i64, i64, i64)>dfs2 = [&](i64 u, i64 f, i64 pre) {
    if (mark[u])pre = max(pre, 0i64);
    ans[u] = max(mx[u], pre);
    i64 mx1 = pre, mx2 = -inf;
    for (auto v : g[u]) {
      if (v == f)continue;
      if (mx[v] + 1 >= mx1) {
        mx2 = mx1; mx1 = mx[v] + 1;
      } else if (mx[v] + 1 > mx2) {
        mx2 = mx[v] + 1;
      }
    }
    for (auto v : g[u]) {
      if (v == f)continue;
      if (mx[v] + 1 == mx1) {
        dfs2(v, u, mx2 + 1);
      } else {
        dfs2(v, u, mx1 + 1);
      }
    }
  };
  dfs1(1, 0); dfs2(1, 0, -inf);
  cout << *min_element(ans.begin() + 1, ans.begin() + 1 + n) << endl;
}
signed main() {
  i64 t; cin >> t;
  while (t--)
    solve();
}
