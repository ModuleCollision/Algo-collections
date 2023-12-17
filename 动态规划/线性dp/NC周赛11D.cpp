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
  vector<i64>A(n + 5, 0); for (i64 i = 1; i <= n; i++)cin >> A[i];
  sort(A.begin() + 1, A.begin() + 1 + n);
  vector dp(n + 5, vector<i64>(n - m + 5, 0));
  for (i64 i = 1; i <= n; i++)dp[i][1] = 1;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j < i; j++) {
      if (A[i] % A[j] == 0) {
        for (i64 k = 2; k <= n - m; k++) {
          dp[i][k] = (dp[i][k] % mod + dp[j][k - 1]) % mod;
        }
      }
    }
  }
  i64 ans = 0;
  for (i64 i = 1; i <= n; i++)ans = (ans % mod + dp[i][n - m]) % mod;
  cout << ans << endl;
}
signed main() {
  solve();
}