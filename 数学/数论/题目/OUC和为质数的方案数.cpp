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
  i64 n, k; std::cin >> n >> k;
  vector<i64>A(n + 5, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  i64 cnt = 0; vector<i64>p(10005, 0); vector<bool>vis(10005, false);
  for (i64 i = 2; i <= 10000; i++) {
    if (not vis[i]) {
      p[++cnt] = i;
    }
    for (i64 j = 1; j <= cnt and p[j]*i <= 10000; j++) {
      vis[p[j]*i] = 1;
      if (i % p[j] == 0)break;
    }
  }
  i64 dp[n + 5][n + 5][10005];
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (i64 i = 1; i <= n; i++) {
    for (i64 z = 0; z <= i; z++)
      for (i64 j = 0; j <= 10000; j++) {
        dp[i][z][j] += dp[i - 1][z][j];
        if (j >= A[i] and z >= 1) {
          dp[i][z][j] += dp[i - 1][z - 1][j - A[i]];
        }
      }
  }
  i64 ans = 0;
  for (i64 i = 2; i <= 10000; i++) {
    if (not vis[i]) {
      ans += dp[n][k][i];
    }
  }
  cout << ans << endl;
}

signed main() {
  solve();
}
