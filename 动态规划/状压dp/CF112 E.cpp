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
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 dp[(1 << 22)];
int main() {
  memset(dp, -1, sizeof(dp));
  /*std::vector<i64>pre(1 << n), w(n);
  for (i64 i = 0; i < n; i++)std::cin >> w[i];
  for (i64 i = 0; i < (1 << n); i++) {
    for (i64 j = 0; j < n; j++) {
      if ((i >> j) & 1)pre[i] += w[j];
    }
  }
  一维前缀和
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < (1 << n); j++) {
      if ((j >> i) & 1)pre[j] += pre[j ^ (1 << i)];
    }
  }
  高维前缀和*/

  i64 n; std::cin >> n;
  std::vector<i64>a(n + 1);
  for (i64 i = 0; i < n; i++) {
    std::cin >> a[i]; dp[a[i]] = a[i];
  }
  for (i64 j = 0; j < (1 << 22); j++) {
    if (dp[j] != -1)continue;
    for (i64 i = 0; i < 22; i++) {
      if ((j >> i) & 1) {
        if (dp[j ^ (1 << i)] != -1) {
          dp[j] = (dp[j ^ (1 << i)]); break;
        }
      }
    }
  }
  for (i64 i = 0; i < n; i++) {
    i64 t = ((1 << 22) - 1) & (~a[i]);
    std::cout << dp[t] << " \n"[i == n];
  }
}

