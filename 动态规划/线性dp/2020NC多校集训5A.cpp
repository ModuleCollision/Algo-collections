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

i64 dis[maxn][maxn]; i64 t[40005];
void solve() {
  i64 n, m, k; std::cin >> n >> m >> k;
  vector dp(2 * k + 5, vector<i64>(2 * n + 5, inf));
  dp[0][1] = 0;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= n; j++) {
      if (dis[i] == dis[j])continue;
      dis[i][j] = inf;
    }
  }
  for (i64 i = 1; i <= m; i++) {
    i64 x, y, z; std::cin >> x >> y >> z;
    dis[x][y] = dis[y][x] = min(dis[x][y], z);
  }
  i64 cnt = 0;
  for (i64 k = 1; k <= n; k++) {
    for (i64 i = 1; i <= n; i++) {
      for (i64 j = 1; j <= n; j++) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (i64 i = 1; i <= k; i++) {
    i64 u, v; std::cin >> u >> v;
    t[++cnt] = u, t[++cnt] = v;
  }
  k *= 2; t[0] = 1;
  for (i64 i = 1; i <= k; i++) {
    for (i64 j = 1; j <= n; j++) {
      dp[i][j] = min(dp[i][j], dp[i - 1][j] + dis[t[i - 1]][t[i]]);
      for (i64 l = 1; l <= n; l++) {
        dp[i][j] = min(dp[i][j], dp[i - 1][l] + dis[l][t[i]] + dis[t[i - 1]][j]);
        dp[i][l] = min(dp[i][l], dp[i - 1][j] + dis[j][l] + dis[l][t[i]]);
      }
    }
  }
  i64 ans = inf;
  for (i64 i = 1; i <= n; i++)ans = min(ans, dp[k][i]);
  cout << ans << endl;
}
signed main() {
  solve();
}