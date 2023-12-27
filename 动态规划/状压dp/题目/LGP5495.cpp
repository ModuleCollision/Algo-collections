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
constexpr i64 maxn = 2e7 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

#define uint unsigned int
uint seed;
inline uint getnext() {
  seed ^= seed << 13;
  seed ^= seed >> 17;
  seed ^= seed << 5;
  return seed;
}


bool vis[maxn]; i64 prime[maxn];

int main() {
  int n; std::cin >> n >> seed;
  std::vector<int>a(n + 1);
  std::vector<u32>b(n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = getnext();
    b[i] = a[i];
  }
  for (i64 i = 2; i <= n; i++) {
    if (not vis[i]) {
      for (i64 j = i; j <= n; j += i) {
        vis[j] = 1; b[j] += b[j / i];
      }
    }
  }
  u32 ans = 0;
  for (int i = 1; i <= n; i++) {
    //. std::cout << b[i] << " \n"[i == n];
    ans ^= b[i];
  }
  std::cout << ans;
}

/*将其视作求某个集合子集的前缀和, 做SOS-dp即可*/