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
bool vis[505][505];
void solve() {
  i64 n; cin >> n;
  vector<i64>a(n + 1);
  for (i64 i = 1; i <= n; i++)cin >> a[i];
  vector dp(n + 1, vector<i64>(n + 1, inf));
  dp[0][0] = 0;
  for (i64 i = 1; i <= n; i++) {
    dp[i][i] = 1;
    if (i + 1 <= n) {
      if (a[i] == a[i + 1])dp[i][i + 1] = 1;
      else dp[i][i + 1] = 2;
    }
  }
  for (i64 len = 3; len <= n; len++) {
    for (i64 i = 1; i + len - 1 <= n; i++) {
      i64 j = i + len - 1;
      if (a[i] == a[j])dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
      for (i64 k = i + 1; k <= j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k - 1] + dp[k][j]);
      }
    }
  }
  cout << dp[1][n] << "\n";
}
signed main() {
  solve();
}