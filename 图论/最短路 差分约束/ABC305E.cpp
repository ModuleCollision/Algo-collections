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
  i64 n, m, k; cin >> n >> m >> k;
  vector<vector<i64>>g(n + 1);
  for (i64 i = 1; i <= m; i++) {
    i64 u, v; std::cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }
  vector<i64>dis(n + 1, -1);
  vector<bool>vis(n + 1);
  priority_queue<pair<i64, i64>>q;
  for (i64 i = 1; i <= k; i++) {
    i64 p, h; std::cin >> p >> h;
    dis[p] = h; q.push({h, p});
  }

  while (q.size()) {
    auto [d, u] = q.top(); q.pop();
    vis[u] = 1;
    for (auto v : g[u]) {
      if (dis[v] < d - 1) {
        dis[v] = d - 1;
        if (not vis[v]) {
          q.push({dis[v], v});
        }
      }
    }
  } i64 cnt = 0;
  vector<i64>ans;
  for (i64 i = 1; i <= n; i++) {
    if (dis[i] >= 0)ans.push_back(i);
  }
  cout << ans.size() << endl;
  for (auto c : ans) {
    cout << c << " ";
  }
  cout << endl;
}
signed main() {
  solve();
}