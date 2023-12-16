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

i64 dfn[maxn], low[maxn], dfncnt, in_stack[maxn], tp;
i64 s[maxn];
i64 scc[maxn], sc; i64 sz[maxn], in[maxn];
void solve() {
  i64 n; cin >> n;
  vector<vector<i64>>g(2 * n + 1);
  i64 m; cin >> m;
  function<void(i64)>tarjan = [&](i64 u) {
    low[u] = dfn[u] = ++dfncnt;
    s[++tp] = u, in_stack[u] = 1;
    for (auto v : g[u]) {
      if (not dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if (in_stack[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      ++sc;
      while (s[tp] != u) {
        scc[s[tp]] = sc; sz[sc]++;
        in_stack[s[tp]] = 0;
        tp--;
      }
      scc[s[tp]] = sc; sz[sc]++;
      in_stack[s[tp]] = 0; --tp;
    }
  };
  for (i64 i = 1; i <= m; i++) {
    i64 a1, a2, c1, c2;
    cin >> a1 >> a2 >> c1 >> c2;
    g[2 * a1 + c1].push_back(2 * a2 + 1 - c2);
    g[2 * a2 + c2].push_back(2 * a1 + 1 - c1);
  }
  for (i64 i = 0; i < 2 * n; i++) {
    if (not dfn[i])tarjan(i);
  }
  for (i64 i = 0; i < 2 * n; i += 2) {
    if (scc[i] == scc[i + 1]) {
      puts("NO"); return;
    }
  }
  puts("YES");
  for (i64 i = 0; i < 2 * n; i++) {
    cout << (scc[i] < scc[i + 1]) << " \n"[i == 2 * n - 1];
  }
}
signed main() {
  solve();
}