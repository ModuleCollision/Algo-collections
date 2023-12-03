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
void solve() {
  ll n, k; std::cin >> n >> k;
  vector<ll>b(n + 1, 0);
  for (ll i = 1; i <= n; i++) {
    cin >> b[i];
  }
  if (k == 1) {
    for (ll i = 1; i <= n; i++) {
      if (b[i] != i) {
        puts("NO"); return;
      }
    }
  }
  vector<bool>vis(n + 1, false);
  queue<ll>q; vector<ll>d(n + 1);
  for (ll i = 1; i <= n; i++) {
    d[b[i]]++;
  }
  for (ll i = 1; i <= n; i++) {
    if (not d[i])q.push(i), vis[i] = 1;
  }
  while (q.size()) {
    auto u = q.front(); q.pop();
    d[b[u]]--; if (not d[b[u]]) {
      q.push(b[u]); vis[b[u]] = 1;
    }
  }
  for (ll i = 1; i <= n; i++) {
    if (not vis[i]) {
      int cur = i; vis[cur] = 1; int cnt = 1;
      while (1) {
        cur = b[cur];
        if (cur == i)break;
        vis[cur] = 1; cnt++;
      }
      if (cnt != k) {
        puts("NO"); return;
      }

    }
  }
  puts("YES");
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}