/*离散化 + 朴素扫描线 + 线段树优化*/
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct sq {
  ll len;
  ll l; ll r; ll cnt;//维护该区间是否被覆盖
  //维护覆盖的长度
} tr[maxn * 4];
struct qq {
  ll x, y1, y2;
  ll f;
} p[maxn * 8];
ll q[maxn];
void build(ll p, ll l, ll r) {
  tr[p].l = l; tr[p].r = r;
  if (l == r) {
    return;
  }
  ll mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
}
void pushup(ll p) {
  if (tr[p].cnt) {
    tr[p].len = q[tr[p].r + 1] - q[tr[p].l];
  } else if (tr[p].l == tr[p].r) {
    tr[p].len = 0;
  } else {
    tr[p].len = tr[p << 1].len + tr[p << 1 | 1].len;
  }
}
void modify(ll p, ll l, ll r, ll x) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].cnt += x; pushup(p); return;
  }
  ll mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)modify(p << 1, l, r, x);
  if (r > mid)modify(p << 1 | 1, l, r, x);
  pushup(p);
}
ll query() {
  return tr[1].len;
}
void solve() {
  ll n; std::cin >> n;
  for (ll i = 1; i <= n; i++) {
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    p[i].x = x1; p[i].y1 = y1; p[i].y2 = y2;
    p[i].f = 1;
    q[i] = y1; q[i + n] = y2;
    p[i + n].x = x2; p[i + n].y1 = y1; p[i + n].y2 = y2;
    p[i + n].f = -1;
  }
  sort(p + 1, p + 2 * n + 1, [&](qq x, qq y)->bool{
    return x.x < y.x;
  });
  std::unordered_map<ll, ll>w;
  sort(q + 1, q + 2 * n + 1);
  ll len = unique(q + 1, q + 1 + 2 * n) - q - 1;
  for (ll i = 1; i <= len; i++) {
    w[q[i]] = i;
  }
  build(1, 1, len - 1);
  ll ans = 0;
  for (ll i = 1; i <= 2 * n; i++) {
    ll x = p[i].x, y1 = p[i].y1, y2 = p[i].y2, k = p[i].f;
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