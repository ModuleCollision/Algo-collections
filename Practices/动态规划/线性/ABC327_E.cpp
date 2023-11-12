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
  int n; cin >> n;
  vector<int>p(n + 1, 0); for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  vector dp(n + 1, vector<f64>(n + 1, -inf));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (j >= 1) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] * (0.9) + p[i]);
      }
    }
  }
  auto ksm = [&](f64 x, int y) {
    f64 ret = 1.0;
    while (y) {
      if (y & 1)ret = ret * x;
      x = x * x;
      y >>= 1;
    }
    return ret;
  };
  auto cal = [&](f64 v, int k) -> f64{
    v /= ((1 - ksm(0.9, k)) / (0.1));
    v -= (k ? (1200.0 / sqrt(k)) : 0.0);
    return v;
  };
  f64 ans = -inf;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ans = max(ans, cal(dp[i][j], j));
    }
  }
  printf("%.15lf", ans);
}
signed main() {
  solve();
}