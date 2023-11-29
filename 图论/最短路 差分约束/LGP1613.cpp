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
bool t[55][55][66];
i64 dis[55][55];
void solve() {
  i64 n, m; cin >> n >> m;
  vector<vector<i64>>g(n + 1);
  memset(dis, 0x3f, sizeof(dis));
  for (i64 i = 1; i <= m; i++) {
    i64 u, v; cin >> u >> v;
    dis[u][v] = 1;
    t[u][v][0] = true;
  }
  for (i64 s = 1; s <= 64; s++) {
    for (i64 i = 1; i <= n; i++) {
      for (i64 k = 1; k <= n; k++) {
        for (i64 j = 1; j <= n; j++) {
          if (t[i][k][s - 1] and t[k][j][s - 1]) {
            t[i][j][s] = true; dis[i][j] = 1;
          }
        }
      }
    }
  }
  for (i64 k = 1; k <= n; k++) {
    for (i64 i = 1; i <= n; i++) {
      for (i64 j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  cout << dis[1][n] << "\n";
}
signed main() {
  solve();
}