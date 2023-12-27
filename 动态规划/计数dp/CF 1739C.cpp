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

i64 fac[maxn * 2]; i64 dp[maxn * 2][2];//几张牌, 谁赢的概率
i64 ksm(i64 x, i64 y) {
  i64 ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret % mod;
}
i64 inv(i64 x) {
  return ksm(x, mod - 2) % mod;
}
i64 comb(i64 n, i64 m) {
  return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
  fac[0] = 1;
  for (i64 i = 1; i <= 1e5; i++)fac[i] = fac[i - 1] % mod * i % mod;
  dp[2][0] = 1;//Alice赢的方案数
  for (i64 i = 4; i <= 1e5; i += 2) {
    //Alice拿到最大的
    dp[i][0] = (dp[i][0] % mod + comb(i - 1, i / 2 - 1) % mod) % mod;
    //Bob拿到最大的, Bob拿到次大的
    dp[i][1] = (dp[i][1] % mod + comb(i - 2, i / 2) % mod) % mod;
    //Bob拿到最大的, Alice拿到次大的
    dp[i][0] = (dp[i][0] % mod + dp[i - 2][1]) % mod;
    dp[i][1] = (dp[i][1] % mod + dp[i - 2][0]) % mod;
  }
  i64 T; std::cin >> T;
  while (T--) {
    i64 n; cin >> n; cout << dp[n][0] % mod << " " << dp[n][1] % mod << " " << 1 << endl;
  }
}
signed main() {
  solve();
}