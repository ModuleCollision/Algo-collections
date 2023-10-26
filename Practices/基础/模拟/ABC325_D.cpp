#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 999911659;
void solve() {
  ll n; cin >> n;
  vector<pair<ll, ll>>q(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> q[i].fi >> q[i].se;
    q[i].se += q[i].fi;
  }
  sort(q.begin() + 1, q.begin() + 1 + n, [&](auto s, auto t)->bool{
    return s.fi < t.fi;
  });
  ll ptr = 1, now = 0; ll ans = 0;
  priority_queue<ll, vector<ll>, greater<>>pq;
  while (1) {
    if (not pq.size()) {
      if (ptr > n)break;
      now = q[ptr].fi;
    }
    while (ptr <= n and q[ptr].fi == now) {
      pq.push(q[ptr].se);
      ptr++;
    }
    while ((pq.size()) and pq.top() < now) {
      pq.pop();
    }
    if (pq.size()) {
      pq.pop(); ans++;
    }
    now++;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}