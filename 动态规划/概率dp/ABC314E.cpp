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
  vector<int>c(n + 5, 0), p(n + 5, 0);
  vector s(n + 5, vector<int>(105, 0));
  for (i64 i = 1; i <= n; i++) {
    cin >> c[i] >> p[i];
    for (i64 j = 1; j <= p[i]; j++)cin >> s[i][j];
  }
  vector<f64>dp(m + 5, inf); dp[0] = 0;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      i64 cnt = 0; f64 w = 0;
      for (int k = 1; k <= p[j]; k++) {
        if (not s[j][k])cnt++;
        else if (i >= s[j][k])w += dp[i - s[j][k]] / p[j];
      }
      w += c[j]; w /= (1 - (f64)(cnt) / p[j]);
      dp[i] = min(dp[i], w);
    }
  }
  printf("%.10lf", dp[m]);
}
signed main() {
  solve();
}


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
  std::map<i64, f64>dp;
  for (i64 i = 1; i <= n; i++) {
    cin >> c[i] >> p[i];
    for (i64 j = 1; j <= p[i]; j++)cin >> s[i][j];
  }
  function<f64(i64)>dfs = [&](i64 u) {
    if (u == 0)return dp[u] = 0;
    if (dp.count(u))return dp[u];
    dp[u] = inf;
    for (i64 j = 1; j <= n; j++) {
      i64 cnt = 0; f64 w = 0;
      for (i64 k = 1; k <= p[j]; k++) {
        if (not s[j][k])cnt++;
        else if (u >= s[j][k])w += dfs(u - s[j][k]) / p[j];
      }
      w += c[j]; w /= (1 - (f64)(cnt) / p[j]);
      dp[u] = min(dp[u], w);
    }
    return dp[u];
  };
  printf("%.10lf", dfs(m));
}
signed main() {
  solve();
}