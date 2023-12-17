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

i64 n, k;
i64 p = 0;
vector<i64>st[maxn];
pair<i64, i64>c[maxn]; //记录编号的状压与个数
i64 dp[15][1005][1005];
void solve() {
  cin >> n >> k;
  function<void(i64, i64, i64, i64)>dfs = [&](i64 idx, i64 r, i64 val, i64 cnt) {
    if (idx >= n) {
      auto &[x, y] = c[++p];
      st[r].push_back(p);
      x = val, y = cnt;
      return;
    }
    bool f = true;
    if (idx > 0 and ((val >> (idx - 1)) & 1)) {
      f = false;
    }
    if (f) {
      dfs(idx + 2, r, val + (1 << idx), cnt + 1);
    }
    dfs(idx + 1, r, val, cnt);
  };
  for (i64 i = 1; i <= n; i++) {
    dfs(0, i, 0, 0);
  }
  for (auto s : st[1]) {
    dp[1][s][c[s].second] = 1;
  }
  auto check = [&](i64 v1, i64 v2)->bool{
    if ((v1 >> 1)&v2) {
      return false;
    }
    if ((v1 << 1)&v2) {
      return false;
    }
    if (v1 & v2) {
      return false;
    }
    return true;
  };
  for (i64 cnt = 0; cnt <= k; cnt++) {
    for (i64 i = 2; i <= n; i++) {
      for (auto s : st[i]) {
        for (auto d : st[i - 1]) {
          if (cnt >= c[s].second) {
            if (check(c[s].first, c[d].first)) {
              dp[i][s][cnt] += dp[i - 1][d][cnt - c[s].second];
            }
          }
        }
      }
    }
  }
  i64 ans = 0;
  for (auto s : st[n]) {
    ans += dp[n][s][k];
  }
  cout << ans << endl;
}
signed main() {
  solve();
}