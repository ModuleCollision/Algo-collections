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
  i64 n, m, q; std::cin >> n >> m >> q;
  vector<bool>vis(n + 1);
  for (i64 i = 1; i <= q; i++) {
    i64 t; cin >> t; vis[t] = true;
  }
  vector<pair<i64, i64>>w(m + 1);
  for (i64 i = 1; i <= m; i++)cin >> w[i].first >> w[i].second;
  vector<i64>pre(n + 1); i64 p = 0;
  for (i64 i = 1; i <= n; i++) {
    if (not vis[i]) {
      pre[i] = p;
    } else {
      p = i;
    }
  }
  vector<i64>dp(n + 1, 0);
  for (i64 i = 1; i <= n; i++) {
    if (vis[i]) {
      dp[i] = max(dp[i], dp[i - 1]); continue;
    }
    dp[i] = max(dp[i], dp[i - 1]); i64 d = i - pre[i];
    for (i64 j = 1; j <= m; j++) {
      auto [k, s] = w[j];
      if (d >= (1 << k))dp[i] = max(dp[i], dp[i - (1 << k)] + s);
    }
  }
  i64 ans = 0;
  cout << dp[n] << endl;
}
signed main() {
  solve();
}