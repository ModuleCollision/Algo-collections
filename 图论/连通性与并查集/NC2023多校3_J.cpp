#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, m; std::cin >> n >> m;
  vector<pair<ll, ll>>edge(m + 5);
  for (ll i = 1; i <= m; i++) {
    ll u, v; std::cin >> u >> v;
    edge[i] = {u, v};
  }
  std::vector<ll>fa(n + 5);
  vector<ll>len(n + 5, 0);
  for (ll i = 1; i <= n; i++)fa[i] = i;
  auto find = [&](ll x) {
    while (x != fa[x])x = fa[x] = fa[fa[x]];
    return x;
  };
  /*function<ll(ll)>find = [&](ll x) {
    if (fa[x] != x) {
      ll las = fa[x];
      fa[x] = find(fa[x]);
      len[x] += len[las];
    }
    return fa[x];
  };*/
  //维护环长与判环 : 并查集与有向图
  ll k = 1;
  bool f = 0;
  for (ll i = 1; i <= m; i++) {
    auto [u, v] = edge[i];
    auto x = find(u), y = find(v);
    if (x == y) {
      f = 1;
      //len[x] + len[y] + 1
      //环长
    } else {
      fa[y] = x; len[v] = len[u] + 1;//维护环长
    }
  }
  vector<ll>d(n + 5, 0);
  vector<vector<ll>>tr(n + 1);
  ll cur; if (not f)cur = 1;
  else cur = 2;
  cout << cur << endl;
  if (cur == 2) {
    for (ll i = 1; i <= n; i++)cout << i << " ";
    cout << endl;
    for (ll i = n; i >= 1; i--) {
      cout << i << " ";
    }
    cout << endl;
  } else {
    queue<ll>q;
    for (ll i = 1; i <= m; i++) {
      auto [u, v] = edge[i];
      d[v]++;
      tr[u].push_back(v);
    }
    vector<ll>ans;
    for (ll i = 1; i <= n; i++) {
      if (not d[i]) {
        q.push(i);
      }
    }
    while (q.size()) {
      auto u = q.front(); q.pop();
      ans.push_back(u);
      for (auto v : tr[u]) {
        d[v]--;
        if (not d[v]) {
          q.push(v);
        }
      }
    }
    for (auto c : ans) {
      cout << c << " ";
    }
    cout << endl;
  }
}
signed main() {
  solve();
}