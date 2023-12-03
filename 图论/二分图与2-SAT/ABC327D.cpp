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
  vector<i64>a(m + 1), b(m + 1);
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }
  vector<i64>c(n + 1, 0);
  auto dfs = [&](auto self, i64 u)->bool{
    for (auto v : g[u]) {
      if (c[v]) {
        if (c[v] == c[u])return false;
      } else {
        c[v] = 3 - c[u];
        bool f = self(self, v); if (not f)return false;
      }
    }
    return true;
  };
  for (int i = 1; i <= n; i++) {
    if (not c[i]) {
      c[i] = 1; bool f = dfs(dfs, i);
      if (not f) {
        puts("No"); return;
      }
    }
  }
  puts("Yes");
}
signed main() {
  solve();
}