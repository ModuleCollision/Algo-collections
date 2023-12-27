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
  string s; cin >> s;
  i64 n = s.size(); s = " " + s;
  vector dp(n + 1, vector<i64>(4, 0));
  //0 一定不是雷 1 一定是雷 满足下一位不是雷
  //2 i + 1是雷
  dp[0][0] = 1; dp[0][2] = 1;
  dp[0][1] = 0;
  for (i64 i = 1; i <= n; i++) {
    if (s[i] == '*') {
      dp[i][0] = 0;
      dp[i][1] = (dp[i][1] % mod + dp[i - 1][2]) % mod;
      dp[i][2] = (dp[i][2] % mod + dp[i - 1][2]) % mod;
    } else if (s[i] == '1') {
      dp[i][0] = (dp[i][0] % mod + dp[i - 1][1]) % mod;
      dp[i][1] = 0;
      dp[i][2] = (dp[i][2] % mod + dp[i - 1][0]) % mod;
    } else if (s[i] == '2') {
      dp[i][0] = 0;
      dp[i][1] = 0;
      dp[i][2] = (dp[i][2] % mod + dp[i - 1][1]) % mod;
    } else if (s[i] == '0') {
      dp[i][0] = (dp[i][0] % mod + dp[i - 1][0]) % mod;
      dp[i][1] = 0;
      dp[i][2] = 0;
    } else {
      dp[i][0] = (dp[i - 1][0] % mod + dp[i - 1][1]) % mod;
      dp[i][1] = (dp[i][1] % mod + dp[i - 1][2]) % mod;
      dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
    }
  }
  i64 ans = (dp[n][0] % mod + dp[n][1]) % mod;
  cout << ans << "\n";
}
signed main() {
  solve();
}