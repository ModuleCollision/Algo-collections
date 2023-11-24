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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
  i64 n; cin >> n;
  vector dp(n + 1, vector<i64>(5, 0));
  dp[1][1] = 1; dp[1][2] = 1; dp[1][3] = 1;
  dp[1][0] = 1;
  for (i64 i = 2; i <= n; i++) {
    dp[i][0] += dp[i - 1][3];
    dp[i][0] += dp[i - 1][0];
    dp[i][0] %= 10000;
    dp[i][1] += dp[i - 1][2];
    dp[i][1] += dp[i - 1][0];
    dp[i][1] %= 10000;
    dp[i][2] += dp[i - 1][0];
    dp[i][2] += dp[i - 1][1];
    dp[i][2] %= 10000;
    dp[i][3] += dp[i - 1][0];
    dp[i][3] += dp[i - 1][1];
    dp[i][3] += dp[i - 1][2];
    dp[i][3] %= 10000;
  }
  cout << dp[n][0] % 10000 << "\n";
}
signed main() {
  solve();
}