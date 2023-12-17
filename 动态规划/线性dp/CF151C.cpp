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
  string s; std::cin >> s;
  i64 len = s.size(); s = " " + s;
  i64 m; std::cin >> m;
  string l, r; std::cin >> l >> r; l = " " + l; r = " " + r;
  vector dp(len + 5, vector<i64>(m + 5, 0));
  dp[0][0] = 1;
  for (i64 i = 1; i <= len; i++) {
    for (i64 j = 0; j <= m; j++) {
      dp[i][j] |= dp[i - 1][j];
      if (j >= 1) {
        for (auto k = l[j]; k <= r[j]; k++) {
          if (k == s[i])continue;
          dp[i][j] |= dp[i - 1][j - 1];
        }
      }
    }
  }
  if (dp[len][m]) {
    puts("YES");
  } else {
    puts("NO");
  }
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}