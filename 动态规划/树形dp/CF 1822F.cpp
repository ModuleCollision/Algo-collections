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
  i64 n, k, c; cin >> n >> k >> c;
  vector<i64>tr[n + 1];
  for (i64 i = 1; i <= n - 1; i++) {
    i64 u, v; cin >> u >> v;
    tr[u].push_back(v);
    tr[v].push_back(u);
  }
  vector<i64>dis(n + 1);
  vector<i64>sif(n + 1, 0);
  function<void(i64, i64, i64)>dfs1 = [&](i64 u, i64 f, i64 s) {
    sif[u] = s;
    for (auto v : tr[u]) {
      if (v == f)continue;
      dfs1(v, u, s + 1);
      dis[u] = max(dis[u], dis[v] + 1);
    }
  };
  dfs1(1, 0, 0);
  vector<i64>ans(n + 1);
  function<void(i64, i64, i64)>dfs2 = [&](i64 u, i64 f, i64 pre) {
    ans[u] = max(dis[u], pre);
    i64 mx1 = pre, mx2 = -inf;
    for (auto v : tr[u]) {
      if (v == f)continue;
      if (dis[v] + 1 >= mx1) {
        mx2 = mx1;
        mx1 = dis[v] + 1;
      } else if (dis[v] + 1 > mx2) {
        mx2 = dis[v] + 1;
      }
    }
    for (auto v : tr[u]) {
      if (v == f)continue;
      if (dis[v] + 1 == mx1) {
        dfs2(v, u, mx2 + 1);
      } else {
        dfs2(v, u, mx1 + 1);
      }
    }
  };
  dfs2(1, 0, 0);
  i64 res = -inf;
  for (i64 i = 1; i <= n; i++) {
    i64 cur = ans[i] * k - sif[i] * c;
    res = max(res, cur);
  }
  cout << res << endl;
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}

