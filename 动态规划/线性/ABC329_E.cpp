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
  i64 n, m; string s, t;
  cin >> n >> m >> s >> t;
  vector dp(n, vector<bool>(m, false));
  if (s[0] == t[0])dp[0][0] = true;
  for (i64 i = 1; i < n; i++) {
    for (i64 j = 0; j < m; j++) {
      if (dp[i - 1][j]) {
        if (s[i] == t[0]) dp[i][0] = true;
        if (j + 1 < m and s[i] == t[j + 1]) {
          dp[i][j + 1] = true;
        }
        if (j == m - 1) {
          for (i64 k = 0; k < m; k++) {
            if (s[i] == t[k])dp[i][k] = true;
          }
        }
      }
    }
  }
  puts(dp[n - 1][m - 1] ? "Yes" : "No");
}
signed main() {
  solve();
}