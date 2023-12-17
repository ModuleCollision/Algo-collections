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
  i64 n, m; std::cin >> n >> m;
  vector dp(n + 5, vector<i64>(m + 5, 0));
  for (i64 i = 1; i <= m; i++)dp[1][i] = 1;
  for (i64 i = 2; i <= n; i++) {
    for (i64 j = 1; j <= m; j++) {
      for (i64 k = (i - 1) * j / (i) + 1; k <= m; k++) {
        if (k * (i) - (i - 1)*j > m)break;
        dp[i][k] = (dp[i][k] % mod + dp[i - 1][j]) % mod;
      }
    }
  }
  i64 ans = 0;
  for (i64 i = 1; i <= m; i++) {
    ans = (ans % mod + dp[n][i]) % mod;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}