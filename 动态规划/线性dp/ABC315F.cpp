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
  i64 n; std::cin >> n;
  vector<pair<i64, i64>>w(n + 5);
  for (i64 i = 1; i <= n; i++) {
    std::cin >> w[i].fi >> w[i].se;
  }
  auto dis = [&](i64 i, i64 j)->f64{
    return (f64)sqrt((f64)(w[i].fi - w[j].fi) * (w[i].fi - w[j].fi) + (w[i].se - w[j].se) * (w[i].se - w[j].se));
  };
  vector dp(n + 5, vector<f64>(n + 5, (f64)(1e10)));
  dp[1][1] = 0.0;
  for (i64 i = 2; i <= n; i++) {
    for (i64 j = max(2ll, i - 30); j <= i; j++) {//选择了J个
      i64 sk = i - j;//跳过的
      for (i64 k = max(1ll, i - 1 - sk); k < i; k++) {
        dp[i][j] = min(dp[i][j], dp[k][j - 1] + (f64)dis(i, k));
      }
    }
  }
  f64 ans = (f64)1e10;
  for (i64 i = 2; i <= n; i++) {
    i64 sk = n - i;//跳过的
    ans = min(ans, dp[n][i] + ((sk >= 1) ? (1 << (sk - 1)) : 0.0));
  }
  printf("%.12lf", ans);
}
signed main() {
  solve();
}