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
  i64 n; cin >> n;
  i64 a, b, c; cin >> a >> b >> c;
  vector d(n + 1, vector<i64>(n + 1, 0));
  vector dis(n + 1, vector (n + 1, array<i64, 2> {0, 0}));
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= n; j++) {
      cin >> d[i][j]; if (i == j)continue;
      dis[i][j][0] = d[i][j] * a;
      dis[i][j][1] = d[i][j] * b + c;
    }
  }
  i64 ans = inf;
  for (i64 k = 1; k <= n; k++) {
    for (i64 i = 1; i <= n; i++) {
      for (i64 j = 1; j <= n; j++) {
        dis[i][j][0] = min(dis[i][j][0], dis[i][k][0] + dis[k][j][0]);
        dis[i][j][1] = min(dis[i][j][1], dis[i][k][1] + dis[k][j][1]);
      }
    }
  }
  for (i64 i = 1; i <= n; i++)ans = min(ans, dis[1][i][0] + dis[i][n][1]);
  cout << ans << endl;
}
signed main() {
  solve();
}