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
  vector<vector<i64>>g(n + 1);
  for (i64 i = 1; i <= m; i++) {
    i64 u, v; cin >> u >> v;
    g[u].push_back(v); g[v].push_back(u);
  }
  vector<bool>vis(n + 1);
  vis[1] = true;
  priority_queue<i64, vector<i64>, greater<>>q;
  q.push(1);
  vector<i64>ans;
  while (q.size()) {
    auto u = q.top(); q.pop(); ans.push_back(u);
    for (auto v : g[u]) {
      if (not vis[v]) {
        vis[v] = true;
        q.push(v);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }
}
signed main() {
  solve();
}