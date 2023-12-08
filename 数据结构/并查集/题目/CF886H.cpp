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
ll fa[maxn], v[maxn];//带权并查集模板
ll find(ll x) {
  if (x != fa[x]) {
    ll tmp = find(fa[x]);
    v[x] += v[fa[x]];
    fa[x] = tmp;
    return fa[x];
  }
  return x;
}
void solve() {
  ll n, m; std::cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    fa[i] = i; v[i] = 0;
  }
  bool f = true;
  for (ll i = 1; i <= m; i++) {
    ll a, b, s;
    cin >> a >> b >> s;
    ll ta = find(a), tb = find(b);
    if (ta != tb) {
      fa[ta] = tb;
      v[ta] = v[b] - v[a] + s;
    } else if (f and v[a] - s != v[b]) {
      f = false; puts("NO");
    }
  }
  if (f)puts("YES");
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}
/*带权并查集*/