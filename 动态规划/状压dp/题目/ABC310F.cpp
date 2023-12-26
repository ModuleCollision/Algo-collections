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

i64 ins(i64 msk, i64 k) {
  for (i64 i = 10; i >= k + 1; i--)msk = msk | (((msk >> (i - k - 1)) & 1) << (i - 1));
  msk |= (1 << (k - 1));
  return msk;
}
i64 ksm(i64 a, i64 b) {
  i64 ret = 1;
  while (b) {
    if (b & 1)ret = ret * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ret % mod;
}
void solve() {
  i64 n; std::cin >> n;
  vector<i64>A(n + 1, 0); for (i64 i = 1; i <= n; i++)cin >> A[i];
  vector<i64>pre(n + 1, 0);
  pre[0] = 1;
  for (i64 i = 1; i <= n; i++) {
    pre[i] = (pre[i - 1] % mod * A[i]) % mod;
  }
  vector dp(n + 1, vector<i64>(1 << (11), 0));
  dp[0][0] = 1;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 0; j < (1 << 10); j++) {
      for (i64 k = 1; k <= 10 and k <= A[i]; k++)dp[i][ins(j, k)] = (dp[i][ins(j, k)] % mod + dp[i - 1][j]) % mod;
      if (A[i] > 10)dp[i][j] = (dp[i][j] + dp[i - 1][j] % mod * (A[i] - 10) % mod) % mod;
    }
  }
  i64 ans = 0;
  for (i64 i = 0; i < (1 << 10); i++) {
    if ((i >> 9) & 1)ans = (ans % mod + dp[n][i]) % mod;
  }
  cout << ans % mod*ksm(pre[n], mod - 2) % mod << endl;
}
signed main() {
  solve();
}