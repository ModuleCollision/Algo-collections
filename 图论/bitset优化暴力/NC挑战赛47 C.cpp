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
  i64 n, m1, m2, q; std::cin >> n >> m1 >> m2 >> q;
  std::vector < std::bitset < 1000 + 1 >> e1(n + 1), e2(n + 1);
  for (i64 i = 1; i <= n; i++) {
    e1[i].reset(), e2[i].set(); e1[i][i] = 1;
  }
  for (i64 i = 1; i <= m1; i++) {
    i64 u, v; std::cin >> u >> v;
    e1[u][v] = 1;
  }
  for (i64 i = 1; i <= m2; i++) {
    i64 u, v; std::cin >> u >> v;
    e2[u][v] = 0;
  }
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= n; j++) {
      if (e1[j][i])e1[j] |= e1[i];
      if (e2[j][i])e2[j] |= e2[i];
    }
  }
  while (q--) {
    i64 x, y; std::cin >> x >> y;
    std::cout << (e1[x][y] ? "Yes" : "No") << " ";
    puts(e2[x][y] ? "Yes" : "No");
  }

}

int main() {
  solve();
}

