/*中国剩余定理*/


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



i64 exgcd(i64 a, i64 b, i64 &x, i64 &y) {
  if (b == 0) {
    x = 1; y = 0; return a;
  }
  i64 d = exgcd(b, a % b, x, y);
  i64 tmp = x; x = y; y = tmp - a / b * y;
  return d;
}
void solve() {
  vector<i64>r;//模数
  vector<i64>d;//余数
  i64 n; cin >> n; i64 k = 1;
  for (i64 i = 1; i <= n; i++) {
    i64 u, v; cin >> u >> v;
    k *= u; r.push_back(u); d.push_back(v);
  }
  i64 ans = 0;
  for (i64 i = 0; i < n; i++) {
    i64 m = k / r[i], b, y;
    exgcd(m, r[i], b, y);
    ans = (ans % k + d[i] % k * b % k * m % k) % k;
  }
  cout << (ans % k + k) % k << endl;
}
signed main() {
  solve();
}