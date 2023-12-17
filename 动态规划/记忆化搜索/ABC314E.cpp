
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

void solve() {
  int n, m; std::cin >> n >> m;
  vector<i64>c(n + 5, 0), p(n + 5, 0);
  vector s(n + 5, vector<i64>(105, 0));
  std::map<i64, db>dp;
  for (i64 i = 1; i <= n; i++) {
    cin >> c[i] >> p[i];
    for (i64 j = 1; j <= p[i]; j++)cin >> s[i][j];
  }
  function<db(i64)>dfs = [&](i64 u) {
    if (u == 0)return dp[u] = 0;
    if (dp.count(u))return dp[u];
    dp[u] = inf;
    for (i64 j = 1; j <= n; j++) {
      i64 cnt = 0; db w = 0;
      for (i64 k = 1; k <= p[j]; k++) {
        if (not s[j][k])cnt++;
        else if (u >= s[j][k])w += dfs(u - s[j][k]) / p[j];
      }
      w += c[j]; w /= (1 - (db)(cnt) / p[j]);
      dp[u] = min(dp[u], w);
    }
    return dp[u];
  };
  printf("%.10lf", dfs(m));
}
signed main() {
  solve();
}