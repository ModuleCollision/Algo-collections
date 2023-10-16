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
  ll l; ll r; bool f; ll add;
} st[4 * maxn];
ll tr[30][maxn]; ll cnt[30]; ll n; string s;
void add(ll idx, char c, ll v) {
  ll cur = c - 'a' + 1;
  for (; idx <= n; idx += (idx & -idx))tr[cur][idx] += v;
}
ll query(ll idx, char c) {
  ll cur = c - 'a' + 1; ll ret = 0;
  for (; idx >= 1; idx -= (idx & -idx))ret += tr[cur][idx];
  return ret;
}
void pushup(ll p) {
  st[p].f = true;
  if (s[st[p << 1].r] <= s[st[p << 1 | 1].l]) {
    st[p].f &= st[p << 1].f; st[p].f &= st[p << 1 | 1].f;
  } else {
    st[p].f = false;
  }
  return;
}
/*第一次操作*/
void modify(ll p, ll idx, char c) {
  if (st[p].l == st[p].r) {
    s[idx] = c; return;
  }
  ll mid = (st[p].l + st[p].r) >> 1;
  if (idx > mid)modify(p << 1 | 1, idx, c);
  else if (idx <= mid)modify(p << 1, idx, c);
  pushup(p);
}
void build(ll p, ll l, ll r) {
  st[p].l = l; st[p].r = r; st[p].f = true;
  if (l == r) {
    return;
  }
  ll mid = (l + r) >> 1;
  build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
bool query2(ll p, ll l, ll r) {
  if (st[p].l >= l and st[p].r <= r) {
    return st[p].f;
  }
  bool ret = true;
  ll mid = (st[p].l + st[p].r) >> 1;
  if (l <= mid)ret &= query2(p << 1, l, r);
  if (r > mid)ret &= query2(p << 1 | 1, l, r);
  return ret;
}
void solve() {
  cin >> n; cin >> s; s = " " + s;
  build(1, 1, n);
  for (ll i = 1; i <= n; i++) {
    ll cur = s[i] - 'a' + 1;
    add(i, s[i], 1); cnt[cur]++;
  }
  //cout << query(6, 'a') << endl;
  ll q; cin >> q;
  while (q--) {
    ll o; cin >> o; if (o == 1) {
      ll idx; char c; scanf("%lld %c", &idx, &c);
      cnt[s[idx] - 'a' + 1]--;
      add(idx, s[idx], -1);
      cnt[c - 'a' + 1]++;
      modify(1, idx, c);
      add(idx, c, 1);
    } else {
      ll l, r; cin >> l >> r;
      bool f1 = query2(1, l, r);
      // cout << f1 << endl;
      char w = s[l]; char q = s[r]; bool f2 = true;
      for (char x = w + 1; x < q; x++) {
        ll cur1 = query(r, x) - query(l - 1, x);
        ll cur2 = cnt[x - 'a' + 1];
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