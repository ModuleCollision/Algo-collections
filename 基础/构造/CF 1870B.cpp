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

char s[maxn];
void solve() {
  i64 n, m, k; std::cin >> n >> m >> k;
  pair<i64, i64>q[m + 5];
  for (i64 i = 1; i <= m; i++) {
    std::cin >> q[i].second;
    q[i].first = i;
  }
  i64 cur = 0;
  for (i64 i = 1; i <= m; i++) {
    if (q[i].second == (n + k - 1) / k)++cur;
    if (q[i].second > (n + k - 1) / k) {
      puts("NO"); return;
    }
  }
  i64 tmp = (n % k); if (not tmp)tmp = k;
  if (cur <= tmp) {
    puts("YES");
  } else puts("NO");
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}