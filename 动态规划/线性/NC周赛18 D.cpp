/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

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
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  i64 n, x; std::cin >> n >> x;
  std::vector<i64>a(n + 1), b(n + 1);
  for (i64 i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (i64 i = 1; i <= n; i++)std::cin >> b[i];
  std::vector dp(n + 1, std::vector(x + 1, std::array<i64, 3> { -inf, -inf, -inf})); // 0 不买 1 原价买 2 半价买
  dp[0][0][0] = 0;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 0; j <= x; j++) {
      dp[i][j][0] = std::max({dp[i - 1][j][0], dp[i - 1][j][1], dp[i - 1][j][2]});
      if (j >= a[i])
        dp[i][j][1] = std::max({dp[i - 1][j - a[i]][0], dp[i - 1][j - a[i]][1], dp[i - 1][j - a[i]][2]}) + b[i];
      if (j >= a[i] / 2)
        dp[i][j][2] = dp[i - 1][j - a[i] / 2][1] + b[i];
    }
  }
  i64 ans = 0;
  for (i64 j = 0; j <= x; j++)ans = std::max({ans, dp[n][j][0], dp[n][j][1], dp[n][j][2]});
  std::cout << ans;
}

int main() {
  solve();
}

