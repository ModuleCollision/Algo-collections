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
  i64 n, ans = 0; std::cin >> n;
  vector<pair<i64, i64>>w;
  for (i64 i = 1; i <= n; i++) {
    i64 q1, q2, q3, q4; cin >> q1 >> q2 >> q3 >> q4;
    w.push_back({q1, q4});
  }
  std::sort(w.begin(), w.end(), [&](pair<i64, i64>x, pair<i64, i64>y)->bool{
    if (x.fi != y.fi)return x.fi < y.fi;
    return x.se < y.se;
  });
  i64 cnt = 0; vector<pair<i64, i64>>p(n + 1);
  for (auto [l, r] : w) {
    if (cnt and l <= p[cnt].se)p[cnt].se = max(p[cnt].se, r);
    else p[++cnt] = {l, r};
  }//区间合并
  i64 q; std::cin >> q;
  while (q--) {
    i64 x; std::cin >> x;
    auto idx = upper_bound(p.begin() + 1, p.begin() + 1 + cnt, pair<i64, i64> {x, 1e18}) - p.begin() - 1;
    if (x >= p[idx].fi and x <= p[idx].se)x = max(x, p[idx].se);
    cout << x << " ";
  }
  cout << endl;
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}