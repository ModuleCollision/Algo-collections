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
  i64 n; cin >> n;
  vector<i64>dis(n + 1, 0);
  vector<vector<i64>>g(n + 1);
  for (i64 i = 1; i <= n - 1; i++) {
    i64 u, v; cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }
  auto dfs = [&](auto self, i64 u, i64 d, i64 f)->void {
    dis[u] = d;
    for (auto v : g[u]) {
      if (v == f)continue;
      self(self, v, d + 1, u);
    }
  };
  dfs(dfs, 1, 0, 0);
  auto p = max_element(dis.begin() + 1, dis.begin() + 1 + n) - dis.begin();
  dfs(dfs, p, 0, 0);
  auto dis2 = dis;
  auto q = max_element(dis.begin() + 1, dis.begin() + 1 + n) - dis.begin();
  dfs(dfs, q, 0, 0);
  for (int i = 1; i <= n; i++)dis[i] = max(dis[i], dis2[i]);
  sort(dis.begin() + 1, dis.begin() + 1 + n);
  for (i64 i = 1; i <= n; i++) {
    auto idx = lower_bound(dis.begin() + 1, dis.begin() + 1 + n, i) - dis.begin();
    if (idx > n)idx--;
    while (idx and dis[idx] >= i)idx--;
    cout << min(n, idx + 1) << " \n"[i == n];
  }
}
signed main() {
  solve();
}