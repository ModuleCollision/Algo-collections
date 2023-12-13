/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

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
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e7 + 500;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


int main() {
  i64 n, d; std::cin >> n >> d;
  std::vector<i64>w(n + 1); f64 tot = 0.0;
  for (i64 i = 0; i < n; i ++) {
    std::cin >> w[i]; tot += w[i];
  }
  tot /= d; tot *= tot;
  std::vector dp(d + 1, std::vector<i64>((1 << n) + 1, inf));
  dp[0][0] = 0;
  i64 ans = inf;

  for (i64 i = 1; i <= d; i++) {
    for (i64 j = 1; j < (1 << n); j++) {
      for (i64 k = j; k; k = (j & (k - 1))) {
        i64 q = j ^ k;
        i64 cur = 0;
        for (i64 s = 0; s < n; s++) {
          if (((k >> s) & 1)) {
            cur += w[s];
          }
        }
        cur *= cur;
        dp[i][j] = std::min(dp[i][j], dp[i - 1][q] + cur);
        if (j == (1 << n) - 1)ans = std::min(ans, dp[i][j]);
      }
    }
  }
//  std::cout << ans << "\n";
  f64 res = ((f64)(ans) * 1.0 / d) - tot;
  printf("%.8lf", res);
}

