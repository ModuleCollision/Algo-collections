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

i64 fac[maxn];
void init() {
  fac[0] = 1;
  for (i64 i = 1; i <= 1e6; i++) {
    fac[i] = (fac[i - 1] % mod * i) % mod;
  }
}
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
  fac[n] % mod*inv(fac[n - m] % mod * fac[m]) % mod;
}
void solve() {
  init(); i64 n, m; std::cin >> n >> m;
  vector<i64>w(m + 1);
  vector<string>s(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> s[i]; s[i] = " " + s[i];
  }
  for (i64 i = 1; i <= m; i++) {
    w[i] = n + 1;
    for (i64 j = n; j >= 1; j--)if (s[j][i] == '#')w[i] = j;
  }
  vector dp(m + 5, vector<i64>(n + 5, 0));
  vector p(m + 5, vector<i64>(n + 5, 0));
  for (i64 i = 0; i <= n + 1; i++) {
    p[0][i] = 1;
  }
  for (i64 i = 1; i <= m; i++) {
    for (i64 j = w[i]; j >= 1; j--) {
      dp[i][j] = (dp[i][j] % mod + p[i - 1][j - 1]) % mod;
    }
    for (i64 j = n + 1; j >= 0; j--)p[i][j] = (p[i][j + 1] % mod + dp[i][j]) % mod;
  }
  i64 ans = 0;
  cout << p[m][1] << endl;
}
signed main() {
  solve();
}