#include<bits/stdc++.h>
using i8 = signed char;
typedef long long ll;
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
const i64 mod = 9901;
const i64 maxn = 5e7 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 inv[maxn];
signed main() {
  i64 a, b; cin >> a >> b;
  if (not a) {
    puts("0"); return 0;
  }
  auto ksm = [&](i64 x, i64 y) {
    i64 ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  };
  i64 ans = 1;
  auto inv = [&](i64 x) {
    return ksm(x, mod - 2) % mod;
  };
  auto cal = [&](i64 p, i64 s) {
    i64 w = ((ksm(p, s + 1) % mod - 1) % mod + mod) % mod;
    if (p % mod == 1)return (s + 1) % mod;
    auto q = inv(p - 1) % mod;
    return w % mod * q % mod;
  };
  for (i64 i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      i64 s = 0;
      while (a % i == 0)a /= i, s++;
      s *= b;
      ans = (ans % mod * cal(i, s)) % mod;
    }
  }
  if (a > 1) {
    ans = (ans % mod * cal(a, b)) % mod;
  }
  cout << ans << "\n";
}