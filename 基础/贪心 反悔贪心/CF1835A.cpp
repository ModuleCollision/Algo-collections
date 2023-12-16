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

void solve() {
  i64 a, b, c, k; cin >> a >> b >> c >> k;
  if (a > c or b > c) {
    puts("-1"); return;
  }
  auto ss = [&](i64 x, i64 y) {
    cout << x << " + " << y << " = " << x + y << endl;
  };
  bool f = false;
  i64 w = pow(10, c - 1); i64 s = pow(10, c) - 1;
  for (i64 i = pow(10, a - 1); i < pow(10, a); i++) {
    i64 l = max((i64)pow(10, b - 1), w - i);
    i64 r = min((i64)pow(10, b) - 1, s - i);
    if (l > r)continue;
    i64 q = r - l + 1;
    if (k <= q) {
      ss(i, l + k - 1);
      f = true; break;
    }
    k -= q;
  }
  if (not f) {
    puts("-1"); return;
  }
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}