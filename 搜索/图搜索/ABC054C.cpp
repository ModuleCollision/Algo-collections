/*300兆字节 1- 2 秒*/

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


bool vis[maxn]; i64 cnt = 0;
i64 prime[maxn];
void init() {
  for (i64 i = 2; i <= 1e6; i++) {
    if (not vis[i]) {
      prime[++cnt] = i;
    }
    for (i64 j = 1; j <= cnt and i * prime[j] <= 1e6; j++) {
      vis[i * prime[j]] = true;
      if (i % prime[j] == 0)break;
    }
  }
}
void solve() {
  i64 n, m; cin >> n >> m;
  vector<vector<i64>>g(n + 1);
  vector<bool>vis(n + 1);
  while (m--) {
    i64 u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  i64 ans = 0; vis[1] = true;
  function<void(i64, i64)>dfs = [&](i64 u, i64 cnt) {
    ans += (cnt == n);
    for (auto v : g[u]) {
      if (not vis[v]) {
        vis[v] = true;
        dfs(v, cnt + 1);
        vis[v] = false;
      }
    }
  };
  dfs(1, 1);
  cout << ans << endl;
}
signed main() {
  solve();
}