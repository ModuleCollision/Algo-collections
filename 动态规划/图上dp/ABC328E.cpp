#include<bits/stdc++.h>
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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
  i64 n, m, k; cin >> n >> m >> k;
  vector<vector<pair<i64, i64>>>g(n);
  for (int i = 1; i <= m; i++) {
    i64 x, y, z; cin >> x >> y >> z;
    x--; y--;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  /*枚举点和出边dp*/
  vector<set<i64>>dp(1 << n);
  dp[1].insert(0);
  for (int i = 0; i < (1 << n); i++) {
    if (not (i & 1))continue;
    for (int j = 0; j < n; j++) {
      if (not ((i >> j) & 1))continue;
      for (auto [x, y] : g[j]) {
        if ((i >> x) & 1)continue;
        for (auto z : dp[i]) {
          dp[i | (1 << x)].insert((z + y) % k);
        }
      }
    }
  }
  cout << (*dp.back().begin()) << "\n";
}
signed main() {
  solve();
}