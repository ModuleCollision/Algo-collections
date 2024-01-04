/*浮点二分模板*/
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
  i64 n, m, k; std::cin >> n >> m >> k;
  vector<pair<i64, i64>>p(n + 1), q(m + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  for (i64 i = 1; i <= m; i++) {
    cin >> q[i].first >> q[i].second;
  }
  f64 l = 0.0000, r = 100.00000;
  auto check = [&](f64 mid) {
    mid /= 100.0;
    vector<f64>s1(n + 1), s2(m + 1);
    for (i64 i = 1; i <= n; i++) {
      s1[i] = (1.0 - mid) * p[i].first - mid * p[i].second;
    }
    for (i64 i = 1; i <= m; i++) {
      s2[i] = (mid - 1.0) * q[i].first + mid * q[i].second;
      s2[i] = -s2[i];
    }
    i64 ret = 0;
    sort(s2.begin() + 1, s2.begin() + 1 + m);
    for (i64 i = 1; i <= n; i++) {
      i64 idx = lower_bound(s2.begin() + 1, s2.begin() + 1 + m, -s1[i]) - s2.begin();
      ret += m - idx + 1;
    }
    return ret >= k;
  };
  while (r - l > 0.0000000001) {
    f64 mid = (r + l) / 2;
    if (check(mid))l = mid;
    else r = mid;
  }
  printf("%.10lf\n", l);
}
signed main() {
  solve();
}