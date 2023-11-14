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
using i64 = long long;
struct sq {
  ll mxsuf = 0, mnsuf = 0, mxans = 0, mnans = 0;
};

void solve() {
  ll n; cin >> n; ll tot = 0;
  vector<ll>pre(n + 1, 0);
  vector<sq>tr; tr.push_back(sq()); tot++;
  tr[0].mxsuf = tr[0].mxans = 1;
  string opt;
  while (n--) {
    cin >> opt;
    if (opt == "+") {
      ll v, x; cin >> v >> x;
      auto cur = sq(); v--;
      cur.mxsuf = max(0ll, tr[v].mxsuf + x);
      cur.mnsuf = min(0ll, tr[v].mnsuf + x);
      cur.mxans = max(tr[v].mxans, cur.mxsuf);
      cur.mnans = min(tr[v].mnans, cur.mnsuf);
      tr.push_back(cur);
    } else {
      ll u, v, x; cin >> u >> v >> x;
      v--;
      if (x >= tr[v].mnans and x <= tr[v].mxans) {
        puts("Yes");
      } else puts("No");
    }
  }
}
signed main() {
  ll T; cin >> T;
  while (T--)
    solve();
}