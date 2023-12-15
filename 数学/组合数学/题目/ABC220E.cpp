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
  i64 n, d; std::cin >> n >> d;
  auto ksm = [&](i64 x, i64 y) {
    i64 ret = 1; if (y < 0)return 0i64;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  }; i64 ans = 0;
  for (i64 i = 1; i <= (n - d); i++) {
    i64 c = ksm(2, i - 1) % mod;//该层节点个数
    i64 b = ((d - 1) % mod + mod) % mod * ksm(2, d - 2) % mod;
    b = (b % mod + ksm(2, d)) % mod;
    ans = (ans % mod + c % mod * b % mod) % mod;
  }
  for (i64 i = n - d + 1; i <= n - (d + 1) / 2; i++) {
    i64 p = d - 1 - (i - (n - d + 1)) * 2;
    i64 c = ksm(2, i - 1) % mod;//该层节点个数
    p = p % mod * ksm(2, d - 2) % mod;
    ans = (ans % mod + p % mod * c % mod) % mod;
  }
  cout << ans % mod * 2 % mod << endl;
}
signed main() {
  solve();
}