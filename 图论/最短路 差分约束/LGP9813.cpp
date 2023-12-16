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
  i64 k, n, m; cin >> k >> n >> m;
  vector<vector<array<i64, 3>>>g(n + 1);
  for (i64 i = 1; i <= m; i++) {
    i64 u, v, t, h; cin >> u >> v >> t >> h;
    g[u].push_back({v, t, h});
    g[v].push_back({u, t, h});
  }
  vector dis(n + 1, vector<i64>(k + 5, inf));
  i64 s, t; cin >> s >> t;
  dis[s][0] = 0;
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, greater<>>q;
  q.push({0, s});
  vector<bool>vis(n + 1, false);
  while (q.size()) {
    auto [d, u] = q.top(); q.pop(); vis[u] = true;
    i64 mn = inf;
    for (auto [v, t, h] : g[u]) {
      for (i64 j = 0; j <= k; j++) {
        if (j >= h) {
          dis[v][j] = min(dis[v][j], dis[u][j - h] + t);
        }
        mn = min(mn, dis[v][j]);
      }
      if (not vis[v]) {
        q.push({mn, v});
      }
    }
  }
  i64 ans = inf;
  for (i64 j = 0; j < k; j++) {
    ans = min(ans, dis[t][j]);
  }
  if (ans == inf) {
    puts("-1"); return;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}