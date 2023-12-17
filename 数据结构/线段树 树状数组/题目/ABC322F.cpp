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
  i64 zmx, omx, lzmx, rzmx, lomx, romx, l, r;
  i64 add;
} tr[maxn * 4 + 5];
i64 n, q; string s;
void pushup(i64 u) {
  tr[u].lzmx = tr[u << 1].lzmx;
  tr[u].rzmx = tr[u << 1 | 1].rzmx;
  tr[u].zmx = max(tr[u << 1].zmx, tr[u << 1 | 1].zmx);
  if (tr[u << 1].r - tr[u << 1].l + 1 == tr[u << 1].lzmx) {
    tr[u].lzmx += tr[u << 1 | 1].lzmx;
  }
  if (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1 == tr[u << 1 | 1].rzmx) {
    tr[u].rzmx += tr[u << 1].rzmx;
  }
  tr[u].zmx = max(tr[u].zmx, tr[u << 1].rzmx + tr[u << 1 | 1].lzmx);


  tr[u].lomx = tr[u << 1].lomx;
  tr[u].romx = tr[u << 1 | 1].romx;
  tr[u].omx = max(tr[u << 1].omx, tr[u << 1 | 1].omx);
  if (tr[u << 1].r - tr[u << 1].l + 1 == tr[u << 1].lomx) {
    tr[u].lomx += tr[u << 1 | 1].lomx;
  }
  if (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1 == tr[u << 1 | 1].romx) {
    tr[u].romx += tr[u << 1].romx;
  }
  tr[u].omx = max(tr[u].omx, tr[u << 1].romx + tr[u << 1 | 1].lomx);
}
void build(i64 u, i64 l, i64 r) {
  tr[u].l = l; tr[u].r = r; tr[u].add = 0;
  if (l == r) {
    if (s[l] == '1') {
      tr[u].lomx = tr[u].romx = tr[u].omx = 1;
    } else {
      tr[u].lzmx = tr[u].rzmx = tr[u].zmx = 1;
    }
    return;
  }
  i64 mid = (l + r) >> 1;
  build(u << 1, l, mid);
  build(u << 1 | 1, mid + 1, r);
  pushup(u);
}
void pushdown(i64 p) {
  if (tr[p].add) {
    tr[p].add = 0;
    tr[p << 1].add ^= 1;
    tr[p << 1 | 1].add ^= 1;
    swap(tr[p << 1].zmx, tr[p << 1].omx);
    swap(tr[p << 1].lzmx, tr[p << 1].lomx);
    swap(tr[p << 1].rzmx, tr[p << 1].romx);
    swap(tr[p << 1 | 1].zmx, tr[p << 1 | 1].omx);
    swap(tr[p << 1 | 1].lzmx, tr[p << 1 | 1].lomx);
    swap(tr[p << 1 | 1].rzmx, tr[p << 1 | 1].romx);
  }
}
void modify(i64 p, i64 l, i64 r) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].add ^= 1;
    swap(tr[p].zmx, tr[p].omx);
    swap(tr[p].lzmx, tr[p].lomx);
    swap(tr[p].rzmx, tr[p].romx);
    return;
  }
  pushdown(p);
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)modify(p << 1, l, r);
  if (r > mid)modify(p << 1 | 1, l, r);
  pushup(p);
}
sq query(i64 p, i64 l, i64 r) {
  if (tr[p].l >= l and tr[p].r <= r)return tr[p];
  pushdown(p);
  sq ans, lans, rans;
  lans.omx = lans.lomx = lans.romx = rans.omx = rans.lomx = rans.romx = 0;
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)lans = query(p << 1, l, r);
  if (r > mid)rans = query(p << 1 | 1, l, r);
  ans.lomx = lans.lomx;
  ans.romx = rans.romx;
  ans.omx = max(lans.omx, rans.omx);
  if (lans.r - lans.l + 1 == lans.lomx) {
    ans.lomx += rans.lomx;
  }
  if (rans.r - rans.l + 1 == rans.romx) {
    ans.romx += lans.romx;
  }
  ans.omx = max(ans.omx, lans.romx + rans.lomx);
  return ans;
}
void solve() {
  cin >> n >> q >> s; s = " " + s;
  build(1, 1, n);
  while (q--) {
    i64 c, l, r;
    cin >> c >> l >> r;
    if (c == 1) {
      modify(1, l, r);
    } else {
      auto w = query(1, l, r);
      cout << w.omx << endl;
    }
  }
}
signed main() {
  solve();
}