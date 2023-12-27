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
  i64 l; i64 r; i64 add; i64 mx; i64 mn;
} tr[maxn];
void pushup(i64 p) {
  tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
  tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
}
void build(i64 p, i64 l, i64 r) {
  tr[p].l = l; tr[p].r = r;
  tr[p].mx = tr[p].mn = tr[p].add = 0;
  if (l == r)return;
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void pushdown(i64 p) {
  if (tr[p].add) {
    i64 ad = tr[p].add;
    tr[p].add = 0;
    tr[p << 1].add += ad; tr[p << 1].mx += ad; tr[p << 1].mn += ad;
    tr[p << 1 | 1].add += ad; tr[p << 1 | 1].mx += ad; tr[p << 1 | 1].mn += ad;
  }
}
void update(i64 p, i64 l, i64 r, i64 v) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].add += v; tr[p].mn += v; tr[p].mx += v;
    return;
  }
  pushdown(p);
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)update(p << 1, l, r, v);
  if (r > mid)update(p << 1 | 1, l, r, v);
  pushup(p);
}
i64 querymax(i64 p, i64 l, i64 r) {
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p].mx;
  }
  pushdown(p);
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  i64 ret = -inf;
  if (l <= mid)ret = max(ret, querymax(p << 1, l, r));
  if (r > mid)ret = max(ret, querymax(p << 1 | 1, l, r));
  return ret;
}
i64 querymin(i64 p, i64 l, i64 r) {
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p].mn;
  }
  pushdown(p);
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  i64 ret = inf;
  if (l <= mid)ret = min(ret, querymin(p << 1, l, r));
  if (r > mid)ret = min(ret, querymin(p << 1 | 1, l, r));
  return ret;
}
struct cmp {
  bool operator()(const pair<i64, i64>&x, const pair<i64, i64>&y)const {
    return x.second > y.second;
  }
};
void solve() {
  i64 n, m; cin >> n >> m;
  vector<pair<i64, i64>>w(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> w[i].first >> w[i].second;
  }
  sort(w.begin() + 1, w.begin() + 1 + n, [&](auto s, auto t)->bool{
    return s.first < t.first;
  });
  vector<i64>q;
  q.push_back(1); q.push_back(m);
  for (i64 i = 1; i <= n; i++)q.push_back(w[i].first), q.push_back(w[i].second);
  sort(q.begin(), q.end());
  i64 sz = unique(q.begin(), q.end()) - q.begin() - 1;
  for (i64 i = 1; i <= n; i++) {
    w[i].first = lower_bound(q.begin(), q.begin() + 1 + sz, w[i].first) - q.begin() + 1;
    w[i].second = lower_bound(q.begin(), q.begin() + 1 + sz, w[i].second) - q.begin() + 1;
  }
  m = lower_bound(q.begin(), q.begin() + 1 + sz, m) - q.begin() + 1;
  build(1, 1, m);
  //cout << "#" << m << endl;
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, cmp>pq;
  i64 ans = 0;
  for (i64 i = 1; i <= n; i++) {
    auto [l, r] = w[i];
    while (pq.size() and pq.top().second < l) {
      update(1, pq.top().first, pq.top().second, -1);
      pq.pop();
    }
    update(1, l, r, 1);
    pq.push({l, r});
    ans = max(ans, querymax(1, 1, m) - querymin(1, 1, m));
  }
  cout << ans << endl;
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}