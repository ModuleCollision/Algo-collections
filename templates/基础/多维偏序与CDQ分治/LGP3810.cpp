#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll tr[maxn];
void solve() {
  ll n, k; std::cin >> n >> k;
  vector<array<ll, 3>>w(n + 1);
  ll cnt = 0; vector<array<ll, 5>>A(n + 1);
  for (ll i = 1; i <= n; i++)cin >> w[i][0] >> w[i][1] >> w[i][2];
  std::sort(w.begin() + 1, w.begin() + 1 + n, [&](auto w, auto t)->bool{
    if (w[0] != t[0])return w[0] < t[0];
    if (w[1] != t[1])return w[1] < t[1];
    return w[2] < t[2];
  });
  for (ll i = 1; i <= n; i++) {
    ll l = i;
    while (i + 1 <= n and w[i + 1] == w[i])i++;
    array<ll, 5>tmp = {w[i][0], w[i][1], w[i][2], i - l + 1, 0};
    A[++cnt] = tmp;
  }
  auto add = [&](ll x, ll v) {
    for (; x <= k; x += (x & -x))tr[x] += v;
  };
  auto query = [&](ll idx) {
    ll ret = 0;
    for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
    return ret;
  };
  function<void(ll, ll)>cdq = [&](ll l, ll r) {
    if (l == r)return;
    ll mid = (l + r) >> 1;
    cdq(l, mid); cdq(mid + 1, r);
    auto f = [&](array<ll, 5>x, array<ll, 5>y)->bool{
      if (x[1] != y[1])return x[1] < y[1];
      return x[2] < y[2];
    };
    std::sort(A.begin() + l, A.begin() + mid + 1, f);
    std::sort(A.begin() + mid + 1, A.begin() + r + 1, f);
    ll i = l, j = mid + 1;
    while (j <= r) {
      while (i <= mid and A[i][1] <= A[j][1]) {
        add(A[i][2], A[i][3]);
        i++;
      }
      A[j][4] += query(A[j][2]);
      j++;
    }
    for (ll k = l; k < i; k++)add(A[k][2], -A[k][3]);
    return;
  };
  vector<ll>ans(n + 1, 0);
  cdq(1, cnt);
  for (ll i = 1; i <= cnt; i++)ans[A[i][4] + A[i][3] - 1] += A[i][3];
  for (ll i = 0; i < n; i++)cout << ans[i] << endl;
}
signed main() {
  solve();
}