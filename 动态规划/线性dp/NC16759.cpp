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

i64 dp[35][35][35][35];
vector<array<i64, 2>>dir = {{ -1, 0}, {0, -1}};
void solve() {
  i64 n; std::cin >> n;
  vector A(n + 1, vector<i64>(n + 1, 0));
  i64 x, y, z;
  while (cin >> x >> y >> z and (x and y and z)) {
    A[x][y] = z;
  }
  dp[1][1][1][1] = A[1][1];
  auto check = [&](i64 x, i64 y) {
    return x >= 1 and x <= n and y >= 1 and y <= n;
  };
  for (i64 x1 = 1; x1 <= n; x1++) {
    for (i64 y1 = 1; y1 <= n; y1++) {
      for (i64 x2 = 1; x2 <= n; x2++) {
        for (i64 y2 = 1; y2 <= n; y2++) {
          if (x1 == 1 and x2 == 1 and y1 == 1 and y2 == 1)continue;
          for (i64 i = 0; i < 2; i++) {
            for (i64 j = 0; j < 2; j++) {
              i64 xx1 = x1 + dir[i][0], yy1 = y1 + dir[i][1];
              i64 xx2 = x2 + dir[j][0], yy2 = y2 + dir[j][1];
              if (check(xx1, yy1) and check(xx2, yy2)) {
                dp[x1][y1][x2][y2] = max(dp[x1][y1][x2][y2], dp[xx1][yy1][xx2][yy2] + A[x1][y1] + ((x1 != x2 or y1 != y2) ? A[x2][y2] : 0));
              }
            }
          }
        }
      }
    }
  }
  cout << dp[n][n][n][n] << endl;
}
signed main() {
  solve();
}