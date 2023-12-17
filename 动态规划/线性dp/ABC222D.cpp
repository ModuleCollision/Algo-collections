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
  i64 n; std::cin >> n;
  vector<i64>A(n + 2, 0), B(n + 2, 0);
  for (i64 i = 1; i <= n; i++) {
    cin >> A[i];
  }
  for (i64 j = 1; j <= n; j++)cin >> B[j];
  vector dp(n + 2, vector<i64>(3010));
  for (i64 j = A[1]; j <= B[1]; j++)dp[1][j] = 1, dp[1][j] += dp[1][j - 1];
  for (i64 i = 2; i <= n; i++) {
    for (i64 j = A[i]; j <= B[i]; j++) {
      dp[i][j] = (dp[i][j - 1] % mod + dp[i - 1][min(j, B[i - 1])]) % mod;
    }
  }
  cout << dp[n][B[n]] % mod << endl;
}
signed main() {
  solve();
}