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
  if (n < m)return 0i64;
  return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
  i64 ans = 0; init();
  i64 h, w, k; std::cin >> h >> w >> k;
  if (k == 1) {
    cout << 1 << endl; return;
  }
  for (i64 i = 1; i <= h; i++) {
    for (i64 j = 1; j <= w; j++) {
      i64 cur = 0;
      for (i64 u = 0; u <= 2; u++) {
        for (i64 v = 0; v <= 2; v++) {
          cur += comb((i - u) * (j - v), k) % mod * (v == 1 ? -2 : 1) % mod * (u == 1 ? -2 : 1);
          cur = (cur % mod + mod) % mod;
        }
      }
      ans = (ans % mod + cur % mod * i * j * (h - i + 1) % mod * (w - j + 1) % mod) % mod;
    }
  }
  ans = (ans % mod * inv(comb(h * w, k))) % mod;
  cout << ans << endl;
}
signed main() {

  solve();
}