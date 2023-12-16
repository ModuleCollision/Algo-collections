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
  i64 n; std::cin >> n; vector<i64>A(n + 5, 0); for (i64 i = 1; i <= n; i++)cin >> A[i];
  vector cnt(35, vector<i64>(2, 0)); i64 ans = 0;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 30; j >= 0; j--) {
      i64 c = (A[i] >> j) & 1; i64 cc = c ^ 1;
      ans = (ans % mod + (1 << j) % mod * cnt[j][cc] % mod * (n - i + 1) % mod) % mod;
      cnt[j][c] += i;
    }
  }
  cout << ans << endl;
}
signed main() {
  solve();
}