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
  auto ksm = [&](i64 x, i64 y) {
    i64 ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  };
  auto inv = [&](i64 x) {
    return ksm(x, mod - 2) % mod;
  };
  /*类背包却不是背包，求的是排列的方案数*/
  i64 n, x; std::cin >> n >> x;
  vector<i64>t(n + 1); for (i64 i = 1; i <= n; i++)cin >> t[i];
  vector<i64>dp(x + 1, 0);
  dp[0] = 1; i64 w = inv(n) % mod;
  for (i64 i = 1; i <= x; i++) {
    for (i64 j = 1; j <= n; j++) {
      if (i >= t[j]) {
        dp[i] = (dp[i] % mod + dp[i - t[j]] % mod * w) % mod;
      }
    }
  }
  i64 ans = 0;
  for (i64 i = max(0ll, x + 1 - t[1]); i <= x; i++) {
    ans = (ans % mod + dp[i] % mod * w) % mod;
  }
  cout << ans % mod << endl;
}
signed main() {
  solve();
}