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


i64 fac[maxn];
void init(i64 n) {
  fac[0] = 1;
  for (i64 i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] % mod * i) % mod;
  }
}
i64 ksm(i64 x, i64 y) {
  i64 ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret % mod;
}
i64 inv(i64 x) {
  return ksm(x, mod - 2) % mod;
}
i64 comb(i64 n, i64 m) {
  if (m > n)return 0i64;
  return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
  i64 n, k; cin >> n >> k; init(n);
  vector<vector<i64>>tr(n + 1);
  for (i64 i = 1; i <= n; i++) {
    i64 u, v; cin >> u >> v;
    tr[u].push_back(v); tr[v].push_back(u);
  }
  vector<i64>dp(n + 1);
  if (k % 2 == 1) {
    puts("1"); return;
  }
  i64 ans = 0;
  function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
    dp[u] = 1;
    for (auto v : tr[u]) {
      if (v == f)continue;
      dfs(v, u);
      dp[u] += dp[v];
    }
    ans = (ans % mod + comb(dp[u], k / 2) % mod * comb(n - dp[u], k / 2) % mod) % mod;
  };
  dfs(1, 0);
  cout << (ans % mod * inv(comb(n, k)) % mod + 1) % mod << endl;
}
signed main() {
  solve();
}