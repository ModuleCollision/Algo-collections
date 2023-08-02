#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct sq {
  std::set<ll>st;
  std::set<ll>add; ll l; ll r;
} tr[maxn * 4];
void pushdown(ll p) {
  if (tr[p].l == tr[p].r) {
    tr[p].add.clear();
    return;
  }
  for (auto c : tr[p].add) {
    tr[p << 1].add.insert(c);
    tr[p << 1 | 1].add.insert(c);
    tr[p << 1].st.insert(c);
    tr[p << 1 | 1].st.insert(c);
  }
  tr[p].add.clear();
}
void pushup(ll p) {
  if (tr[p].l == tr[p].r)return;
  for (auto c : tr[p << 1].st) {
    tr[p].st.insert(c);
  }
  for (auto c : tr[p << 1 | 1].st) {
    tr[p].st.insert(c);
  }
}
void build(ll p, ll l, ll r) {
  tr[p].l = l; tr[p].r = r;
  tr[p].add.clear(); tr[p].st.clear();
  if (l == r) {
    return;
  }
  ll mid = (l + r) >> 1;
  build(p << 1, l, mid);
  build(p << 1 | 1, mid + 1, r);
}
void modify(ll p, ll l, ll r, ll v) {
  if (tr[p].l >= l and tr[p].r <= r) {
    tr[p].st.insert(v);
    tr[p].add.insert(v);
    return;
  }
  pushdown(p);
  ll mid = (tr[p].l + tr[p].r) >> 1;
  if (r > mid) {
    modify(p << 1 | 1, l, r, v);
  }
  if (l <= mid) {
    modify(p << 1, l, r, v);
  }
  pushup(p);
}
std::set<ll> query(ll p, ll idx) {
  if (tr[p].l == tr[p].r) {
    return tr[p].st;
  }
  pushdown(p);
  ll mid = (tr[p].l + tr[p].r) >> 1;
  if (idx > mid) {
    return query(p << 1 | 1, idx);
  } else {
    return query(p << 1, idx);
  }
}
void solve() {
  ll n, m; std::cin >> n >> m;
  build(1, 1, n);
  map<ll, pair<ll, ll>>ks;
  vector<ll>cnt(m + 5);
  std::map<pair<ll, ll>, ll>sk;
  for (ll i = 1; i <= m; i++) {
    ll l, r; std::cin >> l >> r;
    ks[i] = {l, r};
    modify(1, l, r, i);
    sk[ {l, r}] = i;
  }
  ll q; std::cin >> q; vector<ll>xx(q + 5);
  for (ll i = 1; i <= q; i++) {
    std::cin >> xx[i];
  }
  for (ll i = 1; i <= q; i++) {
    ll x = xx[i];
    auto t = query(1, x);
    for (auto c : t) {
      cnt[c]++; ll l = ks[c].first, r = ks[c].second;
      if (cnt[c] >= (r - l + 1) / 2 + 1) {
        cout << i << endl; return;
      }
    }
  }
  puts("-1"); return;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)solve();
}