/*Tarjan算法求LCA*/
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

 i64 n, m, x, y, k;
 i64 dis[maxn], fa[maxn], ans[maxn];
vector<pair< i64,  i64>>q[maxn];
vector<pair< i64,  i64>>tr[maxn];
void solve() {
  cin >> n >> m;
  vector<bool>vis(n + 5, false);
  for ( i64 i = 1; i <= n - 1; i++) {
    cin >> x >> y >> k;
    tr[x].push_back({y, k});
    tr[y].push_back({x, k});
  }
  for ( i64 i = 1; i <= m; i++) {
    cin >> x >> y;
    q[x].push_back({y, i});
    q[y].push_back({x, i});
  }
  for ( i64 i = 1; i <= n; i++) {
    fa[i] = i;
  }
  auto find = [&]( i64 u) ->  i64 {
    while (fa[u] != u) {
      u = fa[u] = fa[fa[u]];
    }
    return u;
  };
  function<void( i64,  i64,  i64)> dfs = [&] ( i64 u,  i64 f,  i64 d) {
    dis[u] = d;
    for (auto [v, s] : tr[u]) {
      if (v == f) {
        continue;
      }
      dfs(v, u, d + s);
    }
  };
  dfs(1, 0, 0);
  function<void( i64,  i64)>tarjan = [&]( i64 u,  i64 f) {
    fa[u] = u; vis[u] = true;
    for (auto [v, s] : tr[u]) {
      if (v == f) {
        continue;
      }
      tarjan(v, u);
      fa[v] = u;
    }
    for (auto [c, idx] : q[u]) {
      if (vis[c]) {
         i64 k = find(c);
        ans[idx] = dis[u] + dis[c] - dis[k] * 2; //统计答案,idx为编号
      }
    }
  };
  tarjan(1, 1);
  for ( i64 i = 1; i <= m; i++) {
    cout << ans[i] << endl;
  }
}
signed main() {
  solve();
}
/*树上倍增算法求LCA*/
#include<bits/stdc++.h>
using namespace std;
typedef long long  i64;
typedef double db;
typedef long double lb;
const  i64 maxn = 2e4 + 5;
const  i64 inf = 0x3f3f3f3f;
const  i64 mod = 998244353;
 i64 n, m, x, y, k;
vector<pair< i64,  i64>>tr[maxn];
void add_edge( i64 u,  i64 v,  i64 w) {
  tr[u].push_back({v, w});
  tr[v].push_back({u, w});
}
 i64 fa[maxn][20], dis[maxn][20];  i64 dep[maxn];
void dfs( i64 u,  i64 f) {
  fa[u][0] = f;
  dep[u] = dep[fa[u][0]] + 1;
  for ( i64 i = 1; (1 << i) <= dep[u]; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
    dis[u][i] = dis[u][i - 1] + dis[fa[u][i - 1]][i - 1];
  }
  for (auto [x, y] : tr[u]) {
    if (x == f) {
      continue;
    }
    dis[x][0] = y;
    dfs(x, u);
  }
}
 i64 lca( i64 u,  i64 v) {
   i64 ret = 0;
  if (dep[u] < dep[v]) {
    swap(u, v);
  }
  if (dep[u] != dep[v]) {
    for ( i64 i = log2(dep[u] - dep[v]); i >= 0; i--) {
      if (dep[fa[u][i]] >= dep[v]) {
        ret += dis[u][i];
        u = fa[u][i];
      }
    }
  }
  if (u == v) {
    return ret;
  }
  for ( i64 i = log2(dep[u]); i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      ret += dis[u][i]; ret += dis[v][i];
      u = fa[u][i];
      v = fa[v][i];
    }
  }
  if (u != v) {
    ret += dis[u][0];
    ret += dis[v][0];
  }
  return ret;
}
signed main() {
  cin >> n >> m ;
  for ( i64 i = 1; i <= n - 1; i++) {
    cin >> x >> y >> k;
    add_edge(x, y, k);
  }
  dfs(1, 0);
  for ( i64 i = 1; i <= m; i++) {
    cin >> x >> y;
    cout << lca(x, y) << endl;
  }
}