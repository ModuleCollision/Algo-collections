//滚动哈希
// 利用线段树 + 哈希表动态的维护哈希值
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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
u64 b =  1e9 + 7; u64 pw[maxn];
struct sq {
  u64 h1, h2; int l, r; int len;
} tr[maxn * 4]; std::string s;
void pushup(int p) {
  int len1 = tr[p << 1].r - tr[p << 1].l + 1;
  int len2 = (tr[p << 1 | 1].r - tr[p << 1 | 1].l + 1);
  tr[p].h1 = tr[p << 1].h1 + tr[p << 1 | 1].h1 * pw[len1];
  tr[p].h2 = tr[p << 1 | 1].h2 + tr[p << 1].h2 * pw[len2];
  return;
}
void build(int p, int l, int r) {
  tr[p].l = l, tr[p].r = r;
  tr[p].len = tr[p].r - tr[p].l + 1;
  if (l == r) {
    tr[p].h1 = tr[p].h2 = s[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void modify(int p, int idx, char c) {
  if (tr[p].l == tr[p].r) {
    tr[p].h1 = tr[p].h2 = c;
    return;
  }
  int mid = (tr[p].l + tr[p].r) >> 1;
  if (idx <= mid)modify(p << 1, idx, c);
  else modify(p << 1 | 1, idx, c);
  pushup(p);
}
sq query(int p, int l, int r) {
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p];
  }
  int mid = (tr[p].l + tr[p].r) >> 1;
  sq a, b; a = {0, 0, 0, 0, 0};
  b = {0, 0, 0, 0, 0};
  if (r <= mid) {
    return query(p << 1, l, r);
  }
  if (l > mid) {
    return  query(p << 1 | 1, l, r);
  }
  sq ret; a = query(p << 1, l, r);
  b = query(p << 1 | 1, l, r);
  ret.len = a.len + b.len;
  ret.h1 = a.h1 + b.h1 * pw[a.len];
  ret.h2 = b.h2 + a.h2 * pw[b.len];
  return ret;
}
void solve() {
  int n, q; std::cin >> n >> q;
  pw[0] = 1;
  std::cin >> s; s = ' ' + s;
  for (int i = 1; i <= n; i++) {
    pw[i] = (pw[i - 1] * b);
  }
  build(1, 1, n);
  while (q--) {
    int opt; std::cin >> opt;
    if (opt == 1) {
      int x; std::string c;
      std::cin >> x >> c;
      modify(1, x, c[0]);
    } else {
      int l, r; std::cin >> l >> r;
      auto x = query(1, l, r);
      puts((x.h1 == x.h2 ? "Yes" : "No"));
    }
  }
}

int main() {
  solve();
  return 0;
}