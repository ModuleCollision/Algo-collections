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
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
struct sq {
  int l; int r; int mx; int add;
} tr[maxn * 4];
void pushup(int p) {
  tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
  return;
}
void build(int p, int l, int r) {
  tr[p].l = l; tr[p].r = r;
  tr[p].mx = tr[p].add = 0;
  if (l == r) {
    return;
  }
  int mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void pushdown(int p) {
  if (tr[p].add) {
    int ad = tr[p].add; tr[p].add = 0;
    tr[p << 1].add += ad; tr[p << 1 | 1].add += ad;
    tr[p << 1].mx += ad; tr[p << 1 | 1].mx += ad;
    return;
  }
}
void modify(int p, int l, int r, int v) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].add += v; tr[p].mx += v;
    return;
  }
  pushdown(p);
  int mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)modify(p << 1, l, r, v);
  if (r > mid)modify(p << 1 | 1, l, r, v);
  pushup(p);
}
int query(int p, int l, int r) {
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p].mx;
  }
  pushdown(p);
  int mid = (tr[p].l + tr[p].r) >> 1;
  int ret = 0;
  if (l <= mid)ret = max(ret, query(p << 1, l, r));
  if (r > mid)ret = max(ret, query(p << 1 | 1, l, r));
  return ret;
}
void solve() {
  int n, d, w; cin >> n >> d >> w;
  int p = 0;
  vector<pair<int, int>>e(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> e[i].first >> e[i].second;
  }
  sort(e.begin() + 1, e.begin() + 1 + n, [&](auto x, auto y)->bool{
    return x.first < y.first;
  });
  build(1, 1, 200005);
  int ans = 0;
  for (int r = 1, l = 1; r <= n; r++) {
    modify(1, max(1, e[r].second - w + 1), e[r].second, 1);
    while (e[r].first - e[l].first + 1 > d) {
      modify(1, max(1, e[l].second - w + 1), e[l].second, -1);
      l++;
    }
    if (e[r].first - e[l].first + 1 <= d)
      ans = max(ans, query(1, 1, 200005));
  }
  cout << ans << "\n";
}
signed main() {
  solve();
}