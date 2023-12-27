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

i64 fa[maxn], v[maxn];//带权并查集模板
i64 find(i64 x) {
  if (x != fa[x]) {
    i64 tmp = find(fa[x]);
    v[x] += v[fa[x]];
    fa[x] = tmp;
    return fa[x];
  }
  return x;
}
void solve() {
  i64 n, m; std::cin >> n >> m;
  for (i64 i = 1; i <= n; i++) {
    fa[i] = i; v[i] = 0;
  }
  bool f = true;
  for (i64 i = 1; i <= m; i++) {
    i64 a, b, s;
    cin >> a >> b >> s;
    i64 ta = find(a), tb = find(b);
    if (ta != tb) {
      fa[ta] = tb;
      v[ta] = v[b] - v[a] + s;
    } else if (f and v[a] - s != v[b]) {
      f = false; puts("NO");
    }
  }
  if (f)puts("YES");
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}
/*带权并查集*/