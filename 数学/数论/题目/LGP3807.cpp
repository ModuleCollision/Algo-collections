/*Lucas定理 求解模小素数 p 的组合数值*/


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

constexpr i64 mod = 1145141;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 p, fac[maxn];
void init() {
  cin >> p; fac[0] = 1;
  for (i64 i = 1; i <= p; i++) {
    fac[i] = (fac[i - 1] % p * i) % p;
  }
}
i64 ksm(i64 a, i64 b) {
  i64 ret = 1;
  while (b) {
    if (b & 1)ret = ret * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ret % p;
}
i64 inv(i64 x) {
  return ksm(x, p - 2) % p;
}
i64 comb(i64 n, i64 m) {
  if (m > n)return 0ll;
  return fac[n] % p * inv(fac[n - m] % p * fac[m]) % p;
}
i64 lucas(i64 n, i64 m) {
  if (m == 0)return 1;
  return ((comb(n % p, m % p)) * lucas(n / p, m / p)) % p;
}
void solve() {
  i64 n, m; cin >> n >> m;
  init();
  cout << lucas(n + m, m) << endl;
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}