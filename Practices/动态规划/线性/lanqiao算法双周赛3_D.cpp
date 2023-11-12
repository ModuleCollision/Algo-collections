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
i64 G[1005][1005];
i64 dp[1005][1005][4];
void solve() {
  int n, m, q; cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++)cin >> G[i][j];
  }
  dp[1][1][0] = G[1][1];
  auto check = [&](int x, int y) {
    return x >= 1 and x <= n and y >= 1 and y <= m;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (i == 1 and j == 1)continue;
      for (int k = 0; k <= q; k++) {
        if (check(i - 1, j)) {
          if (__gcd(G[i][j], G[i - 1][j]) != 1) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + G[i][j]);
          } else {
            if (k >= 1) {
              dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + G[i][j]);
            }
          }
        }
        if (check(i, j - 1)) {
          if (__gcd(G[i][j], G[i][j - 1]) != 1) {
            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k] + G[i][j]);
          } else {
            if (k >= 1) {
              dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + G[i][j]);
            }
          }
        }
      }
    }
  }
  i64 ans = 0;
  for (int k = 0; k <= q; k++) {
    ans = max(ans, dp[n][m][k]);
  }
  if (ans == 0) {
    puts("-1"); return;
  }
  cout << ans << "\n";
}
signed main() {
  solve();
}