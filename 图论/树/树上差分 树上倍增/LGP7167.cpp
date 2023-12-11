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
i64 que[maxn], hed = 1, tal = 0;
i64 dep[maxn], fa[maxn][30];
i64 w[maxn][30];
void solve() {
  i64 n, q; cin >> n >> q;
  vector<i64>d(n + 5), c(n + 5);
  for (i64 i = 1; i <= n; i++) {
    cin >> d[i] >> c[i];
  }
  vector<i64>suf(n + 5, n + 1);
  for (i64 i = 1; i <= n; i++) {
    while (hed <= tal and d[que[tal]] < d[i]) {
      suf[que[tal]] = i; tal--;
    }
    que[++tal] = i;
  }
  vector<vector<i64>>tr(n + 5);
  for (i64 i = n; i >= 1; i--) {
    tr[i].push_back(suf[i]);
    tr[suf[i]].push_back(i);
  }
  function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
    fa[u][0] = f;
    dep[u] = dep[fa[u][0]] + 1;
    for (i64 i = 1; (1 << i) <= dep[u]; i++) {
      fa[u][i] = fa[fa[u][i - 1]][i - 1];
      w[u][i] = w[u][i - 1] + w[fa[u][i - 1]][i - 1];
    }
    for (auto v : tr[u]) {
      if (v == f)continue;
      w[v][0] = c[u];
      dfs(v, u);
    }
  };
  dfs(n + 1, 0);
  //cout << "#" << dep[n + 1] << endl;
  auto query = [&](i64 u, i64 v) {
    if (v <= c[u]) {
      return u;
    }
    v -= c[u];
    while (1) {
      if (dep[u] == 2)break; bool f = false;
      for (i64 i = log2(dep[u] - 2); i >= 0; i--) {
        if (v >= w[u][i] and dep[fa[u][i]] >= 2) {
          v -= w[u][i]; u = fa[u][i]; f = true;
        }
      }
      if (not f)break;
    }
    if (v == 0) {
      return u;
    } else if (v > 0) {
      u = fa[u][0];
      if (u == n + 1)u = 0;
    }
    return u;
  };
  while (q--) {
    i64 u, v; cin >> u >> v;
    cout << query(u, v) << "\n";
  }
}
signed main() {
  solve();
}