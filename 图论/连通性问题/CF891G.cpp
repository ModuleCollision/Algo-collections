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
  i64 n, s; std::cin >> n >> s;
  vector<array<i64, 3>>e(n + 1);
  for (i64 i = 1; i <= n - 1; i++) {
    i64 u, v, w; std::cin >> u >> v >> w;
    e[i] = {u, v, w};
  }
  std::sort(e.begin() + 1, e.begin() + n, [&](array<i64, 3>x, array<i64, 3>y)->bool{
    return x[2] < y[2];
  });
  i64 ans = 1;
  vector<i64>sz(n + 5, 1);
  vector<i64>fa(n + 5, 0); for (i64 i = 1; i <= n; i++)fa[i] = i;
  auto find = [&](i64 x) {
    while (x != fa[x])x = fa[x] = fa[fa[x]];
    return x;
  };
  auto merge = [&](i64 x, i64 y) {
    i64 a = find(x), b = find(y);
    fa[a] = b; sz[b] += sz[a];
  };
  auto ksm = [&](i64 a, i64 b) {
    i64 ret = 1;
    while (b) {
      if (b & 1)ret = ret * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ret % mod;
  };
  for (i64 i = 1; i <= n - 1; i++) {
    auto [u, v, w] = e[i];
    i64 x = find(u), y = find(v);
    ans = (ans % mod * ksm(s - w + 1, sz[x] * sz[y] - 1) % mod) % mod;
    merge(u, v);
  }
  //保证在该树加边的过程中, 所加的边是两个连通块中权值最大的边
  cout << ans % mod << endl;
}
signed main() {
  i64 t; std::cin >> t;
  while (t--)
    solve();
}