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
  i64 n, m; std::cin >> n >> m;
  map<i64, pair<i64, i64>>ks;
  vector<i64>cnt(m + 5);
  std::map<pair<i64, i64>, i64>sk;
  for (i64 i = 1; i <= m; i++) {
    i64 l, r; std::cin >> l >> r;
    ks[i] = {l, r};
    sk[ {l, r}] = i;
  }
  i64 q; std::cin >> q; vector<i64>xx(q + 5);
  for (i64 i = 1; i <= q; i++) {
    std::cin >> xx[i];
  }
  i64 l = 1, r = q + 1, ans = 0;
  auto check = [&](i64 mid) {
    vector<i64>d(n + 5);
    for (i64 i = 1; i <= mid; i++) {
      d[xx[i]]++;
    }
    for (i64 i = 1; i <= n; i++) {
      d[i] += d[i - 1];
    }
    for (i64 i = 1; i <= m; i++) {
      i64 l = ks[i].first, r = ks[i].second;
      i64 len = (r - l + 1);
      i64 c = d[r] - d[l - 1];
      if (c >= (len) / 2 + 1) {
        return true;
      }
    }
    return false;
  };
  bool f = 0;
  while (l < r) {
    i64 mid = (l + r) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (r == q + 1)
    puts("-1"); else cout << r << endl;
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)solve();
}