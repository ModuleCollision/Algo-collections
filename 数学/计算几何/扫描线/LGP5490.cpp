/*离散化 + 朴素扫描线 + 线段树优化*/
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

struct sq {
  i64 len;
  i64 l; i64 r; i64 cnt;//维护该区间是否被覆盖
  //维护覆盖的长度
} tr[maxn * 4];
struct qq {
  i64 x, y1, y2;
  i64 f;
} p[maxn * 8];
i64 q[maxn];
void build(i64 p, i64 l, i64 r) {
  tr[p].l = l; tr[p].r = r;
  if (l == r) {
    return;
  }
  i64 mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
}
void pushup(i64 p) {
  if (tr[p].cnt) {
    tr[p].len = q[tr[p].r + 1] - q[tr[p].l];
  } else if (tr[p].l == tr[p].r) {
    tr[p].len = 0;
  } else {
    tr[p].len = tr[p << 1].len + tr[p << 1 | 1].len;
  }
}
void modify(i64 p, i64 l, i64 r, i64 x) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].cnt += x; pushup(p); return;
  }
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)modify(p << 1, l, r, x);
  if (r > mid)modify(p << 1 | 1, l, r, x);
  pushup(p);
}
i64 query() {
  return tr[1].len;
}
void solve() {
  i64 n; std::cin >> n;
  for (i64 i = 1; i <= n; i++) {
    i64 x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    p[i].x = x1; p[i].y1 = y1; p[i].y2 = y2;
    p[i].f = 1;
    q[i] = y1; q[i + n] = y2;
    p[i + n].x = x2; p[i + n].y1 = y1; p[i + n].y2 = y2;
    p[i + n].f = -1;
  }
  sort(p + 1, p + 2 * n + 1, [&](qq x, qq y)->bool{
    return x.x < y.x;
  });
  std::unordered_map<i64, i64>w;
  sort(q + 1, q + 2 * n + 1);
  i64 len = unique(q + 1, q + 1 + 2 * n) - q - 1;
  for (i64 i = 1; i <= len; i++) {
    w[q[i]] = i;
  }
  build(1, 1, len - 1);
  i64 ans = 0;
  for (i64 i = 1; i <= 2 * n; i++) {
    i64 x = p[i].x, y1 = p[i].y1, y2 = p[i].y2, k = p[i].f;
    if (i > 1) {
      ans += query() * (x - p[i - 1].x);
    }
    modify(1, w[y1], w[y2] - 1, k);
  }
  cout << ans << endl;
}
signed main() {
  solve();
}