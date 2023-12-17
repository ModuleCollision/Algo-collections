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
  i64 l; i64 r; bool f; i64 add;
} st[4 * maxn];
i64 tr[30][maxn]; i64 cnt[30]; i64 n; string s;
void add(i64 idx, char c, i64 v) {
  i64 cur = c - 'a' + 1;
  for (; idx <= n; idx += (idx & -idx))tr[cur][idx] += v;
}
i64 query(i64 idx, char c) {
  i64 cur = c - 'a' + 1; i64 ret = 0;
  for (; idx >= 1; idx -= (idx & -idx))ret += tr[cur][idx];
  return ret;
}
void pushup(i64 p) {
  st[p].f = true;
  if (s[st[p << 1].r] <= s[st[p << 1 | 1].l]) {
    st[p].f &= st[p << 1].f; st[p].f &= st[p << 1 | 1].f;
  } else {
    st[p].f = false;
  }
  return;
}
/*第一次操作*/
void modify(i64 p, i64 idx, char c) {
  if (st[p].l == st[p].r) {
    s[idx] = c; return;
  }
  i64 mid = (st[p].l + st[p].r) >> 1;
  if (idx > mid)modify(p << 1 | 1, idx, c);
  else if (idx <= mid)modify(p << 1, idx, c);
  pushup(p);
}
void build(i64 p, i64 l, i64 r) {
  st[p].l = l; st[p].r = r; st[p].f = true;
  if (l == r) {
    return;
  }
  i64 mid = (l + r) >> 1;
  build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
bool query2(i64 p, i64 l, i64 r) {
  if (st[p].l >= l and st[p].r <= r) {
    return st[p].f;
  }
  bool ret = true;
  i64 mid = (st[p].l + st[p].r) >> 1;
  if (l <= mid)ret &= query2(p << 1, l, r);
  if (r > mid)ret &= query2(p << 1 | 1, l, r);
  return ret;
}
void solve() {
  cin >> n; cin >> s; s = " " + s;
  build(1, 1, n);
  for (i64 i = 1; i <= n; i++) {
    i64 cur = s[i] - 'a' + 1;
    add(i, s[i], 1); cnt[cur]++;
  }
  //cout << query(6, 'a') << endl;
  i64 q; cin >> q;
  while (q--) {
    i64 o; cin >> o; if (o == 1) {
      i64 idx; char c; scanf("%i64d %c", &idx, &c);
      cnt[s[idx] - 'a' + 1]--;
      add(idx, s[idx], -1);
      cnt[c - 'a' + 1]++;
      modify(1, idx, c);
      add(idx, c, 1);
    } else {
      i64 l, r; cin >> l >> r;
      bool f1 = query2(1, l, r);
      // cout << f1 << endl;
      char w = s[l]; char q = s[r]; bool f2 = true;
      for (char x = w + 1; x < q; x++) {
        i64 cur1 = query(r, x) - query(l - 1, x);
        i64 cur2 = cnt[x - 'a' + 1];
        if (cur1 != cur2)f2 = false;
      }
      if (f1 and f2) {
        puts("Yes");
      } else puts("No");
    }
  }
}
signed main() {
  solve();
}