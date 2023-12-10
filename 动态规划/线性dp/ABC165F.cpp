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
  vector<i64>a(n + 5);
  vector<vector<i64>>g(n + 5);
  for (i64 i = 1; i <= n; i++)cin >> a[i];
  for (int i = 1; i <= n - 1; i++) {
    i64 u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<i64>ans(n + 5, 0); auto b = ans;
  std::fill(b.begin(), b.end(), inf);
  function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
    i64 p = lower_bound(b.begin() + 1, b.begin() + 1 + n, a[u]) - b.begin();
    i64 tmp = b[p];
    b[p] = a[u];
    ans[u] = max(ans[f], p);
    for (auto v : g[u]) {
      if (v == f)continue;
      dfs(v, u);
    }
    b[p] = tmp;
  };
  dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }
}
signed main() {
  solve();
}