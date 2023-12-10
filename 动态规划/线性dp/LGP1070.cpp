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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 1e3 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
  i64 n, m, p; std::cin >> n >> m >> p;
  std::vector<i64>a(n + 1);
  std::vector t(n + 1, std::vector<i64>(m + 1, 0));
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= m; j++) {
      std::cin >> t[i][j];
    }
  }
  for (i64 i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector dp(m + 1, -inf); dp[0] = 0;
  dp[0] = 0;
  for (i64 i = 1; i <= m; i++) {
    for (i64 j = 1; j <= n; j++) {
      i64 pre = ((j - 2 + n) % n) + 1;
      i64 cur = t[pre][i];
      for (i64 k = 1; k <= p and k <= i; k++) {
        dp[i] = std::max(dp[i], dp[i - k] + cur - a[pre]);
        pre = ((pre - 2 + n) % n) + 1;
        cur += t[pre][i - k];
      }
    }
  }
  std::cout << dp[m] << "\n";
}

i32 main() {
  solve();
  return 0;
}