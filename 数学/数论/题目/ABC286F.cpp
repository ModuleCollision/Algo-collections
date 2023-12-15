/* 中国剩余定理 */
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



i64 cnt = 0; i64 prime[maxn]; bool vis[maxn];
void init() {
  for (i64 i = 2; i <= 1e6; i++) {
    if (not vis[i]) {
      prime[++cnt] = i;
    }
    for (i64 j = 1; j <= cnt and i * prime[j] <= 1e6; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0)break;
    }
  }
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
  init(); i64 k = 1; i64 b = 0;
  for (i64 i = 1; i <= cnt; i++) {
    k *= prime[i];
    if (k > 1e9) {
      b = i; break;
    }
  }
  vector<i64>r;//模数
  vector<i64>d;//余数
  for (i64 i = 1; i <= b; i++) {
    r.push_back(prime[i]);
    cout << prime[i] << endl; cout << flush;
    for (i64 j = 1; j <= prime[i]; j++) {
      cout << (j) % prime[i] + 1 << " \n"[j == prime[i]];
    }
    cout << flush; i64 v = 0;
    for (i64 j = 1; j <= prime[i]; j++) {
      i64 t; cin >> t; if (j == 1)v = t;
    }
    d.push_back(abs(v - 1));
  }
  i64 ans = 0;
  for (i64 i = 0; i < b; i++) {
    i64 m = k / r[i], s, y;
    exgcd(m, r[i], s, y);
    ans = (ans % k + d[i] % k * s % k * m % k) % k;
  }
  cout << (ans % k + k) % k << endl;
}
signed main() {
  solve();
}