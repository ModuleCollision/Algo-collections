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
i64 dis[1005][1005]; i64 cnt[1005][1005];
void solve() {
  i64 n, m; cin >> n >> m;
  vector<array<i64, 3>>e(m + 1);
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= n; j++) {
      if (i == j)continue;
      dis[i][j] = inf;
    }
  }
  for (i64 i = 1; i <= m; i++) {
    cin >> e[i][0] >> e[i][1] >> e[i][2];
    cnt[e[i][0]][e[i][1]] = cnt[e[i][1]][e[i][0]] = 1;
    dis[e[i][0]][e[i][1]] = dis[e[i][1]][e[i][0]] = e[i][2];
  }
  for (i64 k = 1; k <= n; k++) {
    for (i64 i = 1; i <= n; i++) {
      for (i64 j = 1; j <= n; j++) {
        if (i == j or j == k or i == k)continue;
        if (dis[i][j] > dis[i][k] + dis[k][j]) {
          dis[i][j] = dis[i][k] + dis[k][j];
          cnt[i][j] = cnt[i][k] * cnt[k][j];
        } else if (dis[i][j] == dis[i][k] + dis[k][j]) {
          cnt[i][j] += cnt[i][k] * cnt[k][j];
        }
      }
    }
  }
  for (i64 k = 1; k <= n; k++) {
    f64 ans = 0;
    for (i64 i = 1; i <= n; i++) {
      for (i64 j = 1; j <= n; j++) {
        if (i == j or j == k or i == k)continue;
        if (dis[i][k] + dis[k][j] == dis[i][j]) {
          ans += ((f64)(cnt[i][k]) * cnt[k][j]) / cnt[i][j];
        }
      }
    }
    printf("%.3lf\n", ans);
  }
}
signed main() {
  solve();
}