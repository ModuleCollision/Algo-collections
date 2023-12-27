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
  i64 n, k; cin >> n >> k;
  vector<i64>A(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  vector dp(n + 1, vector<i64>((1 << 6) + 1, 0));
  for (i64 i = 1; i <= n; i++) {
    dp[i][A[i]] = 1;
    for (i64 j = 0; j < (1 << 6); j++) {
      dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
    }
    for (i64 j = 0; j < (1 << 6); j++) {
      dp[i][j & A[i]] = (dp[i][j & A[i]] % mod + dp[i - 1][j]) % mod;
    }
  }
  i64 ans = 0;
  auto count = [&](i64 x) {
    i64 cnt = 0;
    for (i64 i = 6; i >= 0; i--) {
      if ((x >> i) & 1)cnt++;
    }
    return cnt == k;
  };
  for (i64 i = 0; i < (1 << 6); i++) {
    if (count(i)) {
      ans = (ans % mod + dp[n][i]) % mod;
    }
  }
  cout << ans << endl;
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}