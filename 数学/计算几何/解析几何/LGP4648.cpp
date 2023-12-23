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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct FenwickTree {

public:
  std::vector<i64>tr; int n;
  FenwickTree(int n): n(n), tr(n + 20) {}
  FenwickTree() {}
  i64 query(int idx) {
    i64 ret = 0;
    for (; idx >= 1; idx -= (idx & -idx)) {
      ret += tr[idx];
    }
    return ret;
  }
  void modify(int idx, i64 v) {
    for (; idx <= n; idx += (idx & -idx)) {
      tr[idx] += v;
    }
  }
  i64 queryRange(int l, int r) {
    return query(r) - query(l - 1);
  }
};
/*切比雪夫距离转曼哈顿距离*/
// (x, y) 曼哈顿 -> (x + y, x - y) 切比雪夫
int main() {
  i64 b, n, d, m; std::cin >> b >> n >> d >> m;
  if (b == 1) {
    std::vector<i64>a(n + 1);
    for (i64 i = 1; i <= n; i++) {
      std::cin >> a[i];
    }
    i64 ans = 0;
    std::sort(a.begin() + 1, a.begin() + 1 + n);
    for (i64 r = 1, l = 1; r <= n; r++) {
      while (a[r] - a[l] > d)l++;
      ans += r - l;
    }
    std::cout << ans << "\n";
  } else if (b == 2) {
    std::vector<std::pair<i64, i64>>p(n + 1);
    for (i64 i = 1; i <= n; i++) {
      i64 x, y; std::cin >> x >> y;
      p[i].first = x + y, p[i].second = x - y;
    }
    i64 ans = 0;
    FenwickTree tr(2 * m);
    std::sort(p.begin() + 1, p.begin() + 1 + n, [&](auto s, auto t)->bool{
      return s.first < t.first;
    });
    for (i64 r = 1, l = 1; r <= n; r++) {
      while (p[r].first - p[l].first > d) {
        tr.modify(p[l].second + m, -1); l++;
      }
      ans += tr.queryRange(std::max(1ll, p[r].second - d + m), std::min(2 * m, p[r].second + m + d));
      tr.modify(p[r].second + m, 1);
    }
    std::cout << ans << "\n";
  } else {
    std::vector pre(77, std::vector (155, std::vector<i64>(155, 0)));
    std::vector<std::array<i64, 3>>w(n + 1);
    for (i64 i = 1; i <= n; i++) {
      i64 x, y, z; std::cin >> x >> y >> z;
      w[i][0] = x, w[i][1] = y + z;
      w[i][2] = y - z;
      pre[x][y + z][y - z + m]++;
    }
    for (i64 i = 1; i <= m; i++) {
      for (i64 j = 1; j <= 2 * m; j++) {
        for (i64 k = 1; k <= 2 * m; k++) {
          pre[i][j][k] = pre[i][j][k] + pre[i][j][k - 1] + pre[i][j - 1][k] - pre[i][j - 1][k - 1];
        }
      }
    }
    i64 ans = 0;
    auto cal = [&](i64 i, i64 x, i64 y, i64 r) {
      if (d < 0)return 0ll;
      i64 X = x + r, Y = y + r; x -= r; y -= r; y += m; Y += m;
      x = std::max(x, 1ll), y = std::max(y, 1ll), X = std::min(X, 2 * m);
      Y = std::min(Y, 2 * m);
      if (X < x or Y < y)return 0ll;
      return pre[i][X][Y] + pre[i][x - 1][y - 1] - pre[i][x - 1][Y] - pre[i][X][y - 1];
    };
    for (i64 i = 1; i <= n; i++) {
      for (i64 j = 1; j <= m; j++) {
        ans += cal(j, w[i][1], w[i][2], d - abs(j - w[i][0]));
      }
    }
    ans -= n; ans / 2; ans /= 2;
    std::cout << ans << "\n";
  }
}
