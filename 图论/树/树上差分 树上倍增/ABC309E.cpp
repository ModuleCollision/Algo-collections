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
   i64 N, M; std::cin >> N >> M;
  vector<vector< i64>>tr(N + 5);
  for ( i64 i = 2; i <= N; i++) {
     i64 p; std::cin >> p; tr[p].push_back(i);
    tr[i].push_back(p);
  }
  vector< i64>w(N + 5, 0);
  for ( i64 i = 1; i <= M; i++) {
     i64 x, y; std::cin >> x >> y;
    w[x] = y;
  }
  vector<bool>vis(N + 5, false);
  function<void( i64,  i64,  i64)>dfs = [&]( i64 u,  i64 f,  i64 dep) {
     i64 des = dep;
    if (w[u]) {
      des = max(des, w[u] + 1);
    }
    if (des) {
      vis[u] = 1;
    }
    for (auto v : tr[u]) {
      if (v == f)continue;
      dfs(v, u, max(des - 1, 0 i64));
    }
  };
  dfs(1, 0, w[1] + 1);
   i64 ans = 0;
  for ( i64 i = 1; i <= N; i++) {
    if (vis[i])ans++;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}