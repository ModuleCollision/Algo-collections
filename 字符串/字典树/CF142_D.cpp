#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e7 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct sq {
  ll v[15];
};
void solve() {
  ll tot = 0; ll n, m; cin >> n >> m;
  vector p(n + 1, vector<ll>(m + 1, 0));
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++)cin >> p[i][j];
  }
  vector<sq>tr; tr.push_back(sq());
  auto add = [&](vector<ll>s) {
    ll u = 0;
    for (ll i = 1; i <= m; i++) {
      if (not tr[u].v[s[i]]) {
        tr[u].v[s[i]] = tr.size();
        tr.push_back(sq());
      }
      u = tr[u].v[s[i]];
    }
  };
  for (ll i = 1; i <= n; i++) {
    auto tmp = p[i];
    for (ll j = 1; j <= m; j++) {
      tmp[p[i][j]] = j;
    }
    add(tmp);
  }
  auto get = [&](vector<ll>s) {
    ll cnt = 0; ll u = 0;
    for (ll i = 1; i <= m; i++) {
      if (not tr[u].v[s[i]])return cnt;
      cnt++; u = tr[u].v[s[i]];
    }
    return cnt;
  };
  for (ll i = 1; i <= n; i++) {
    cout << get(p[i]) << " \n"[i == n];
  }
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}