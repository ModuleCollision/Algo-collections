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

constexpr i64 mod = 19650827;
constexpr i64 maxn = 1e3 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  i64 n; std::cin >> n;
  std::vector<i64>a(n + 1);
  std::vector dp(n + 1, std::vector (n + 1, std::array<i64, 2> {0, 0}));
  for (i64 i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (i64 i = 1; i <= n; i++) {
    dp[i][i][0] = 1;
  }
  for (i64 len = 2; len <= n; len++) {
    for (i64 i = 1; i + len - 1 <= n; i++) {
      i64 j = i + len - 1;
      if (a[i] < a[i + 1]) {
        dp[i][j][0] = (dp[i][j][0] % mod + dp[i + 1][j][0]) % mod;
      }
      if (a[i] < a[j]) {
        dp[i][j][0] = (dp[i][j][0] % mod + dp[i + 1][j][1]) % mod;
        dp[i][j][1] = (dp[i][j][1] % mod + dp[i][j - 1][0]) % mod;
      }
      if (a[j] > a[j - 1]) {
        dp[i][j][1] = (dp[i][j][1] % mod + dp[i][j - 1][1]) % mod;
      }
    }
  }
  std::cout << (dp[1][n][0] + dp[1][n][1]) % mod;
}

i32 main() {
  solve();
  return 0;
}