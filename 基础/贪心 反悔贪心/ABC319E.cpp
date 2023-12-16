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
  i64 n, x, y; std::cin >> n >> x >> y;
  vector<i64>p(n + 1), t(n + 1);
  for (i64 i = 1; i <= n - 1; i++)cin >> p[i] >> t[i];
  vector<i64>dp(845, 0);
  for (i64 i = 0; i < 840; i++) {
    i64 T = i; T += x;
    for (i64 j = 1; j <= n - 1; j++) {
      T += (p[j] - (T % p[j])) % p[j];
      T += t[j];
    }
    T += y; dp[i] = T - i;
  }
// for (i64 i = 0; i <= 840; i++)cout << dp[i] << endl;
  i64 Q; std::cin >> Q;
  while (Q--) {
    i64 q; std::cin >> q;
    i64 ans = dp[q % 840];
    ans += q;
    cout << ans << endl;
  }
}
signed main() {
  solve();
}