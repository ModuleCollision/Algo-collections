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
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
  i64 H, W, N; std::cin >> H >> W >> N;
  vector pre(H + 5, vector<i64>(W + 5, 0));
  for (i64 i = 1; i <= H; i++) {
    for (i64 j = 1; j <= W; j++)pre[i][j] = 1;
  }
  std::set<pair<i64, i64>>c;
  vector f(H + 5, vector<bool>(W + 5, false));
  while (N--) {
    i64 x, y; std::cin >> x >> y;
    f[x][y] = 1;
    pre[x][y] = 0;
  }
  for (i64 i = 1; i <= H; i++) {
    for (i64 j = 1; j <= W; j++) {
      pre[i][j] = (pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
    }
  }
  auto query = [&](i64 x1, i64 y1, i64 x2, i64 y2) {
    return pre[x1][y1] - pre[x2 - 1][y1] - pre[x1][y2 - 1] + pre[x2 - 1][y2 - 1];
  };
  auto check = [&](i64 x1, i64 y1, i64 x2, i64 y2) {
    return query(x1, y1, x2, y2) == ((x1 - x2 + 1) * (y1 - y2 + 1));
  };
  i64 res = 0;
  for (i64 i = 1; i <= H; i++) {
    for (i64 j = 1; j <= W; j++) {
      i64 ans = 0;
      if (f[i][j])continue;
      i64 l = 1, r = min(H - i + 1, W - j + 1);
      while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (check(i + mid - 1, j + mid - 1, i, j)) {
          l = mid + 1; ans = mid;
        } else {
          r = mid - 1;
        }
      }
      if (check(i + ans - 1, j + ans - 1, i, j))
        res += ans;
      /*i64 l = 0, r = min(H - i + 1, W - j + 1);
      while (l < r) {
        i64 mid = (l + r + 1) >> 1;
        if (check(i + mid - 1, j + mid - 1, i, j)) {
          l = mid; ans = mid;
        } else {
          r = mid - 1;
        }
      }*/
    }
  }
  cout << res << endl;
}
signed main() {
  solve();
}