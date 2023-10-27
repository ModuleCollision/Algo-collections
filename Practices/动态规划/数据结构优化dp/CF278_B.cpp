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
  ll l; ll r; ll mn;
} tr[maxn * 4]; ll a[maxn]; ll dp[maxn];
void pushup(ll p) {
  tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
}
void build(ll p, ll l, ll r) {
  tr[p].l = l; tr[p].r = r;
  if (l == r) {
    tr[p].mn = dp[l]; return;
  }
  ll mid = (tr[p].l + tr[p].r) >> 1;
  build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void update(ll p, ll idx, ll v) {
  if (tr[p].l == tr[p].r) {
    tr[p].mn = v; return;
  }
  ll mid = (tr[p].l + tr[p].r) >> 1;
  if (idx <= mid)update(p << 1, idx, v);
  if (idx > mid)update(p << 1 | 1, idx, v);
  pushup(p);
}
ll query_min(ll p, ll l, ll r) {
  if (l > r)return inf;
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p].mn;
  }
  ll ret = inf; ll mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)
    ret = min(ret, query_min(p << 1, l, r));
  if (r > mid)ret = min(ret, query_min(p << 1 | 1, l, r));
  return ret;
}
void solve() {
  ll n, s, l; cin >> n >> s >> l;
  for (ll i = 1; i <= n; i++)cin >> a[i];
  std::multiset<ll>st1;
  std::fill(dp + 1, dp + 1 + n, inf);
  build(1, 1, n);
  auto check = [&]() {
    return (*(--st1.end())) - (*st1.begin()) > s;
  };
  for (ll q = 1, x = 1; x <= n; x++) {
    st1.insert(a[x]);
    while (check()) {
      st1.erase(st1.find(a[q]));
      q++;
    }
    if (x - q + 1 < l) {
      dp[x] = n + 1;
    } else {
      //s - 1 到 t - l
      if (q - 1 == 0)dp[x] = 1;
      else {
        ll cur = query_min(1, q - 1, x - l);
        dp[x] = cur + 1;
      }
    }
    update(1, x, dp[x]);
  }
  if (dp[n] >= n + 1) {
    puts("-1");
  } else cout << dp[n] << "\n";
}
signed main() {
  solve();
}