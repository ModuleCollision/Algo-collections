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
  for (i64 i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
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
i64 inv(i64 x) {
  return ksm(x, mod - 2) % mod;
}
i64 comb(i64 n, i64 m) {
  return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
}
void solve() {
  init();
  i64 n; cin >> n;
  vector<i64>A(n + 1, 0);
  for (i64 i = 1; i <= n; i++) {
    cin >> A[i];
  }
  vector<i64>cnt(50, 0);
  for (i64 j = 0; j <= 45; j++) {
    for (i64 i = 1; i <= n; i++) {
      if ((A[i] >> j) & 1)cnt[j]++;
    }
  }
  i64 ans = 0;
  for (i64 i = 0; i <= 45; i++) {
    i64 cur = ksm(2, i) % mod; i64 c = cnt[i]; i64 p = 0;
    i64 w = ksm(2, n - c) % mod;
    for (i64 j = 1; j <= c; j += 2) {
      p = (p % mod + comb(c, j) % mod) % mod;
    }
    p = (p % mod * w) % mod;
    ans = (ans % mod + p % mod * cur % mod) % mod;
  }
  cout << ans % mod << endl;
}
signed main() {
  solve();
}