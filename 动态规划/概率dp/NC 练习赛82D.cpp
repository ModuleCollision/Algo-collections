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
  auto ksm = [&](i64 a, i64 b) {
    i64 ret = 1;
    while (b) {
      if (b & 1)ret = ret * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ret;
  };
  auto inv = [&](i64 x) {
    return ksm(x, mod - 2) % mod;
  };
  i64 n, p, q; std::cin >> n >> p >> q;
  i64 ws = p % mod * inv(q) % mod;
  vector<i64>f(n + 5, 0);
  f[0] = 0; f[1] = 1;
  for (i64 i = 2; i <= n; i++) {
    f[i] = (f[i] % mod + f[i - 1] % mod + f[i - 2] % mod) % mod;
  }
  vector C(n + 5, vector<i64>(n + 5, 0));
  for (i64 i = 0; i <= n; i++) {
    for (i64 j = 0; j <= i; j++)
      if (not j)C[i][j] = 1;
      else C[i][j] = (C[i - 1][j] % mod + C[i - 1][j - 1]) % mod;
  }
  vector<i64>dp(n + 5, 0);//此为概率逆推
  for (i64 i = 1; i <= n; i++) {
    dp[i] = (dp[i] % mod + f[n - i + 1]) % mod;
    for (i64 j = 1; j <= i; j++) {
      i64 wss = ((1 - ws) % mod + mod) % mod;
      //枚举可以转移到的状态然后求和
      i64 v = (dp[i - j] % mod * C[i][j] % mod * ksm(ws, j) % mod * ksm(wss, i - j)) % mod;
      dp[i] = (dp[i] % mod + v) % mod;
    }
    i64 wss = ((1 - ws) % mod + mod) % mod;
    i64 p = ((1 - ksm(wss, i)) % mod + mod) % mod;
    dp[i] = ((dp[i]) % mod * inv(p)) % mod;
  }
  cout << dp[n] % mod << endl;
  //为n最终全部发送完的期望代价
}
signed main() {
  solve();
}