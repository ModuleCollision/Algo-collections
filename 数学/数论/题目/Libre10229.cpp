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

constexpr i64 mod = 999911659;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;



i64 fac[5][maxn]; i64 inv[5][maxn], facinv[5][maxn];
i64 mody[5] = {0, 35617, 4679, 3, 2};
i64 ksm(i64 x, i64 y, i64 p) {
  i64 ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % p;
    x = x * x % p;
    y >>= 1;
  }
  return ret % p;
}
void init(i64 idx) {
  fac[idx][0] = 1; fac[idx][1] = 1;
  inv[idx][1] = 1; facinv[idx][0] = 1;
  facinv[idx][1] = 1; i64 p = mody[idx];
  for (i64 i = 2; i <= 2e5; i++) {
    fac[idx][i] = (fac[idx][i - 1] % p * i) % p;
    inv[idx][i] = (p - p / i) % p * inv[idx][p % i] % p;
    facinv[idx][i] = (facinv[idx][i - 1] * inv[idx][i]) % p;
  }
}
i64 comb(i64 n, i64 m, i64 idx) {
  if (m > n)return 0ll; i64 p = mody[idx];
  return (fac[idx][n] % p * facinv[idx][m] % p * facinv[idx][n - m] % p) % p;
}
i64 lucas(i64 n, i64 m, i64 idx) {
  if (m == 0)return 1ll; i64 p = mody[idx];
  return (comb(n % p, m % p, idx) * lucas(n / p, m / p, idx)) % p;
}
i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
  if (b == 0) {
    x = 1; y = 0; return a;
  }
  i64 d = exgcd(b, a % b, x, y);
  i64 tmp = x; x = y; y = tmp - a / b * y;
  return d;
}
void solve() {
  i64 n, g; cin >> n >> g;
  vector<i64>r(1);//reminder
  for (i64 j = 1; j <= 4; j++) {
    i64 cur = 0;
    for (i64 i = 1; i <= sqrt(n); i++) {
      if (n % i == 0) {
        cur = (cur % mody[j] + lucas(n, i, j) % mody[j]) % mody[j];
        if (i != n / i) {
          cur = (cur % mody[j] + lucas(n, n / i, j) % mody[j]) % mody[j];
        }
      }
    }
    r.push_back(cur % mody[j]);
  }
  i64 ans = 0; i64 k = 999911658;
  for (i64 i = 1; i <= 4; i++) {
    i64 m = k / mody[i], invm, y;
    exgcd(m, mody[i], invm, y);
    invm = (invm % mody[i] + mody[i]) % mody[i];
    ans = (ans % k + r[i] % k * invm % k * m % k) % k;
  }
  ans = (ans % k + k) % k;
  cout << ksm(g, ans + k, mod) % mod << endl;
}
signed main() {
  for (i64 i = 1; i <= 4; i++)init(i);
  solve();
}