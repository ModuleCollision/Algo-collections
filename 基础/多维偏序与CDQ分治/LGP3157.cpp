#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 3e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct sq {
  ll idx; ll v; ll del; ll ans;
} st[maxn]; ll rev[maxn];
void solve() {
  auto cmp = [&](sq x, sq y) {
    if (x.idx != y.idx)return x.idx < y.idx;
    if (x.v != y.v)return x.v > y.v;
    return x.del < y.del;
  };
  ll n, m; std::cin >> n >> m;
  for (ll i = 1; i <= n; i++) {
    cin >> st[i].v; st[i].idx = i;
    rev[st[i].v] = i;
  }
  for (ll i = 1; i <= m; i++) {
    ll q; std::cin >> q;
    st[rev[q]].del = i;
  }
}
signed main() {
  solve();
}