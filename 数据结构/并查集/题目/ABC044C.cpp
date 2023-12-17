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

i64 sz[maxn]; i64 fa1[maxn], fa2[maxn], fa3[maxn];
i64 find(i64 x, i64 fa[]) {
  while (x != fa[x])x = fa[x] = fa[fa[x]];
  return x;
}
void merge(i64 x, i64 y, i64 fa[], bool f) {
  i64 a = find(x, fa), b = find(y, fa);
  if (a == b)return;
  fa[a] = b;
  if (f)sz[b] += sz[a];
}
void solve() {
  i64 n, k, l; cin >> n >> k >> l;
  iota(fa1 + 1, fa1 + 1 + n, 1);
  iota(fa2 + 1, fa2 + 1 + n, 1);
  iota(fa3 + 1, fa3 + 1 + n, 1);
  fill(sz + 1, sz + 1 + n, 1);
  for (i64 i = 1; i <= k; i++) {
    i64 u, v; cin >> u >> v;
    merge(u, v, fa1, false);
  }
  for (i64 i = 1; i <= l; i++) {
    i64 u, v; std::cin >> u >> v;
    i64 a = find(u, fa1), b = find(v, fa1);
    if (a == b) {
      i64 q = find(u, fa3), t = find(v, fa3);
      merge(u, v, fa3, true);
    }
    merge(u, v, fa2, false);
  }
  for (i64 i = 1; i <= n; i++) {
    cout << sz[find(i, fa3)] << " \n"[i == n];
  }
}
signed main() {
  solve();
}