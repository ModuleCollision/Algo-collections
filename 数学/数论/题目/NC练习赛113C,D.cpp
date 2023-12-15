/*求解 基于 ax + by = c 的最小正整数解*/
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


void solve() {
  function<i64(i64, i64, i64&, i64&)>exgcd = [&](i64 a, i64 b, i64 & x, i64 & y) {
    if (b == 0) {
      x = 1; y = 0; return a;
    }
    i64 d = exgcd(b, a % b, x, y);
    i64 tmp = x; x = y;
    y = tmp - (a / b) * y;
    return d;
  };
  i64 n, p, x, q, y;
  std::cin >> n >> p >> x >> q >> y;
  i64 tot = 0;
  for (i64 i = 1; i <= n; i++) {
    i64 v; std::cin >> v;
    tot = (tot % n + v) % n;
  }
  i64 a, b; i64 d = exgcd(y, n, a, b);
  i64 ans = inf;
  for (i64 i = 0; i <= n; i++) {
    i64 nd = (tot + i % n * x) % n;
    i64 cost = p * i;
    if (nd % d)continue;
    i64 c = nd / d * a;
    i64 t = n / d;
    c = (c % t + t) % t;
    cost += (1 * c * q);
    ans = min(ans, cost);
  }
  if (ans == inf)puts("-1");
  else
    cout << ans << endl;
}
signed main() {
  solve();
}