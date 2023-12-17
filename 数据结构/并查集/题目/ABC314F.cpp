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

i64 n; i64 fa[maxn], sz[maxn]; vector<pair<i64, i64>>tr[maxn];
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
i64 find(i64 x) {
  while (x != fa[x])x = fa[x] = fa[fa[x]];
  return x;
}
void merge(i64 x, i64 y) {
  i64 a = find(x), b = find(y);
  fa[a] = b; sz[b] += sz[a];
}
void solve() {
  std::cin >> n;
  for (i64 i = 1; i <= n; i++) {
    fa[i] = i; sz[i] = 1;
  }
  i64 tot = n + 1;
  for (i64 i = 1; i <= n - 1; i++) {
    i64 p, q; std::cin >> p >> q; i64 f1 = find(p), f2 = find(q);
    i64 sz1 = sz[f1], sz2 = sz[f2];
    ++tot; fa[tot] = tot; sz[tot] = 0;
    merge(f1, tot), merge(f2, tot);
    i64 k1 = sz1 % mod * inv((sz1 % mod + sz2) % mod) % mod;
    i64 k2 = ((1 - k1) % mod + mod) % mod;
    tr[tot].push_back({f1, k1});
    tr[f1].push_back({tot, k1});
    tr[f2].push_back({tot, k2});
    tr[tot].push_back({f2, k2});
  }
  vector<i64>ans(tot + 5);
  function<void(i64, i64, i64)>dfs = [&](i64 u, i64 f, i64 q) {
    for (auto [v, w] : tr[u]) {
      if (v == f)continue;
      ans[v] = (q % mod + w) % mod;
      dfs(v, u, ans[v]);
    }
  };
  dfs(tot, 0, 0);
  for (i64 i = 1; i <= n; i++)cout << ans[i] % mod << " ";
  cout << endl;
}
signed main() {
  solve();
}