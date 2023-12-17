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
  vector<i64>d(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> d[i];
  vector<i64>l(3), c(3), k(3);
  for (i64 i = 1; i <= 2; i++) {
    cin >> l[i] >> c[i] >> k[i];
  }
  vector dp(n + 1, vector<i64>(k[1] + 1, inf));
  for (i64 i = 0; i <= k[1]; i++) {
    dp[0][i] = 0;
  }
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 0; j <= k[1]; j++) {
      for (i64 k = j; k >= 0; k--) {
        i64 w = max(0ll, d[i] - k * l[1]);
        dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + (w + l[2] - 1) / l[2]);
      }
    }
  }
  i64 ans = inf;
  for (i64 i = 0; i <= k[1]; i++) {
    if (dp[n][i] <= k[2]) {
      ans = min(ans, dp[n][i] * c[2] + i * c[1]);
    }
  }
  if (ans == inf) {
    puts("-1"); return;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}