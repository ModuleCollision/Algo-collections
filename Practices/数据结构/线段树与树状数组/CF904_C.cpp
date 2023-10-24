/*浮点二分模板*/
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
const ll mod = 998244353;
struct sq {
  ll l; ll r; ll add; ll mx; ll mn;
} tr[maxn];
void pushup(ll p) {
  tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
  tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
}
void build(ll p, ll l, ll r) {
  tr[p].l = l; tr[p].r = r;
  tr[p].mx = tr[p].mn = tr[p].add = 0;
  if (l == r)return;
  ll mid = (tr[p].l + tr[p].r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void pushdown(ll p) {
  if (tr[p].add) {
    ll ad = tr[p].add;
    tr[p].add = 0;
    tr[p << 1].add += ad; tr[p << 1].mx += ad; tr[p << 1].mn += ad;
    tr[p << 1 | 1].add += ad; tr[p << 1 | 1].mx += ad; tr[p << 1 | 1].mn += ad;
  }
}
void update(ll p, ll l, ll r, ll v) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].add += v; tr[p].mn += v; tr[p].mx += v;
    return;
  }
  pushdown(p);
  ll mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)update(p << 1, l, r, v);
  if (r > mid)update(p << 1 | 1, l, r, v);
  pushup(p);
}
ll querymax(ll p, ll l, ll r) {
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p].mx;
  }
  pushdown(p);
  ll mid = (tr[p].l + tr[p].r) >> 1;
  ll ret = -inf;
  if (l <= mid)ret = max(ret, querymax(p << 1, l, r));
  if (r > mid)ret = max(ret, querymax(p << 1 | 1, l, r));
  return ret;
}
ll querymin(ll p, ll l, ll r) {
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p].mn;
  }
  pushdown(p);
  ll mid = (tr[p].l + tr[p].r) >> 1;
  ll ret = inf;
  if (l <= mid)ret = min(ret, querymin(p << 1, l, r));
  if (r > mid)ret = min(ret, querymin(p << 1 | 1, l, r));
  return ret;
}
struct cmp {
  bool operator()(const pair<ll, ll>&x, const pair<ll, ll>&y)const {
    return x.se > y.se;
  }
};
void solve() {
  ll n, m; cin >> n >> m;
  vector<pair<ll, ll>>w(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> w[i].fi >> w[i].se;
  }
  sort(w.begin() + 1, w.begin() + 1 + n, [&](auto s, auto t)->bool{
    return s.fi < t.fi;
  });
  vector<ll>q;
  q.push_back(1); q.push_back(m);
  for (ll i = 1; i <= n; i++)q.push_back(w[i].fi), q.push_back(w[i].se);
  sort(q.begin(), q.end());
  ll sz = unique(q.begin(), q.end()) - q.begin() - 1;
  for (ll i = 1; i <= n; i++) {
    w[i].fi = lower_bound(q.begin(), q.begin() + 1 + sz, w[i].fi) - q.begin() + 1;
    w[i].se = lower_bound(q.begin(), q.begin() + 1 + sz, w[i].se) - q.begin() + 1;
  }
  m = lower_bound(q.begin(), q.begin() + 1 + sz, m) - q.begin() + 1;
  build(1, 1, m);
  //cout << "#" << m << endl;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp>pq;
  ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    auto [l, r] = w[i];
    while (pq.size() and pq.top().se < l) {
      update(1, pq.top().fi, pq.top().se, -1);
      pq.pop();
    }
    update(1, l, r, 1);
    pq.push({l, r});
    ans = max(ans, querymax(1, 1, m) - querymin(1, 1, m));
  }
  cout << ans << endl;
}
signed main() {
  ll T; cin >> T;
  while (T--)
    solve();
}