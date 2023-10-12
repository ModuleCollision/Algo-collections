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
  ll v[2]; ll idx;
};
void solve() {
  ll n, k; std::cin >> n >> k;
  vector<sq>tr; tr.push_back(sq());
  auto add = [&](ll x, ll idx) {
    ll u = 0;
    for (ll i = k - 1; i >= 0; i--) {
      ll b = ((x >> i) & 1);
      if (not tr[u].v[b]) {
        tr[u].v[b] = tr.size();
        tr.push_back(sq());
      }
      u = tr[u].v[b];
    }
    tr[u].idx = idx;
  };
  ll s = 0, y = 0, z = 0; ll w = 0;
  auto get = [&](ll x, ll idx) {
    ll f = 0; ll u = 0; ll q = 0;
    for (ll i = k - 1; i >= 0; i--) {
      ll b = (x >> i) & 1;
      if (tr[u].v[b]) {
        u = tr[u].v[b];
        q |= (1ll << i);
        if (not b)f |= (1ll << i);
      }
      else if (tr[u].v[b ^ 1])u = tr[u].v[b ^ 1];
      else return;
    }
    ll p = tr[u].idx;
    //cout << "#" << p << endl;
    if (q >= w) {
      w = q; z = f; y = idx; s = p;
    }
  };
  vector<ll>A(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  add(A[1], 1);
  for (ll i = 2; i <= n; i++) {
    get(A[i], i);
    add(A[i], i);
  }
  cout << s << " " << y << " " << z << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}