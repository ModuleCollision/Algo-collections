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

/*dp + 二分*/
void solve() {
  i64 n, m; cin >> n >> m;
  vector<vector<array<f64, 3>>>g(n + 1);
  for (i64 i = 1; i <= m; i++) {
    f64 u, v, a, b; std::cin >> u >> v >> a >> b;
    g[v].push_back({u, a, b});
  }
  f64 l = 0, r = 1e18; vector<f64>dp(n + 1);
  auto check = [&](f64 mid) {
    for (i64 i = 2; i <= n; i++) {
      dp[i] = -1e18;
      for (auto [v, f, s] : g[i]) {
        i64 vv = (i64)v;
        f64 c = f - s * mid;
        dp[i] = max(dp[i], dp[vv] + c);
      }
    }
    return dp[n];
  };
  double eps = 1e-12;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (check(mid) < 0)r = mid;
    else l = mid;
  }
  printf("%.20lf\n", r);
}
signed main() {
  solve();
}