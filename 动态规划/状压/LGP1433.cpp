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
signed main() {
  i64 n; cin >> n;
  vector dp((1 << (n + 1)) + 1, vector<f64>(n + 2, inf));
  dp[1][0] = 0;
  vector<pair<f64, f64>>w(n + 5);
  for (i64 i = 1; i <= n; i++) {
    cin >> w[i].first >> w[i].second;
  }
  auto dis = [&](i64 x, i64 y) {
    auto [x1, y1] = w[x];
    auto [x2, y2] = w[y];
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  };
  for (i64 i = 1; i < (1 << (n + 1)); i++) {
    if (not (i & 1))continue;
    for (i64 j = 0; j <= n; j++) {
      if ((i >> j) & 1) {
        for (i64 k = 1; k <= n; k++) {
          if (not ((i >> k) & 1)) {
            dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + dis(j, k));
          }
        }
      }
    }
  }
  f64 ans = inf;
  for (i64 i = 1; i <= n; i ++) {
    ans = min(ans , dp[(1 << (n + 1)) - 1][i]);
  }
  printf("%.2lf", ans);
}