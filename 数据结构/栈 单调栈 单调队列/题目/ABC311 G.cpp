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

const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;



/*折半 + 暴搜*/
int main() {
  i64 n, m; std::cin >> n >> m;
  std::vector a(n + 1, std::vector<i64>(m + 1, 0));
  auto pre = a;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= m; j++) {
      std::cin >> a[i][j];
      pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
    }
  }
  auto get = [&](i64 x1, i64 y1, i64 x2, i64 y2) {
    return pre[x2][y2] - pre[x2][y1 - 1] - pre[x1][y2 - 1] + pre[x1 - 1][x2 - 1];
  };
  i64 ans = 0;
  for (i64 u = 1; u <= n; u++) {
    for (i64 d = u; d >= 1; d--) {
      std::vector<i64>w(m + 1);
      for (i64 i = 1; i <= m; i++) {
        i64 cur = inf;
        for (i64 j = d; j <= u; j++) {
          cur = std::min(cur, a[j][i]);
        }
        w[i] = cur;
      }
      std::vector<i64>l(m + 1, 0), r(m + 1, m + 1);
      std::vector<i64>q;
      for (i64 i = 1; i <= m; i++) {
        while (q.size() and w[q.back()] > w[i]) {
          r[q.back()] = i; q.pop_back();
        }
      }
      while (q.size())q.pop_back();
      for (i64 i = m; i >= 1; i--) {
        while (q.size() and w[q.back()] > w[i]) {
          l[q.back()] = i; q.pop_back();
        }
      }
      for (i64 i = 1; i <= m; i++) {
        i64 L = l[i] + 1;
        i64 R = r[i] - 1;
        ans = std::max(ans, w[i] * get(d, L, u, R));
      }
    }
  }
  std::cout << ans << "\n";
}