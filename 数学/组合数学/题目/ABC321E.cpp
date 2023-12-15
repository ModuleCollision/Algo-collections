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
  auto solve = [&](i64 x, i64 k, i64 n) {
    if (k < 0)return 0i64;
    if (k >= 64)return 0i64;
    i64 num = (1 << k), l = x;
    l <<= k; i64 r = l + num - 1;
    if (l > n)return 0i64;
    i64 ret = min(r, n) - l + 1;
    return ret;
  };
  i64 T; std::cin >> T;
  while (T--) {
    i64 n, x, k; std::cin >> n >> x >> k;
    i64 ans = 0;
    if (k)ans += solve(x, k, n);
    while (x > 1 and k > 0) {
      --k; ans += solve(x ^ 1, k - 1, n);
      x >>= 1;
    }
    if (x and k == 0)ans++;
    cout << ans << endl;
  }
}
signed main() {
  solve();
}