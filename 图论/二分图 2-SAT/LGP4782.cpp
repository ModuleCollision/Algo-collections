/*浮点二分模板*/
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
ll dfn[maxn], low[maxn], dfncnt, in_stack[maxn], tp;
ll s[maxn];
ll scc[maxn], sc; ll sz[maxn], in[maxn];
void solve() {
  ll n; cin >> n;
  vector<vector<ll>>g(2 * n + 1);
  ll m; cin >> m;
  function<void(ll)>tarjan = [&](ll u) {
    low[u] = dfn[u] = ++dfncnt;
    s[++tp] = u, in_stack[u] = 1;
    for (auto v : g[u]) {
      if (not dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if (in_stack[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      ++sc;
      while (s[tp] != u) {
        scc[s[tp]] = sc; sz[sc]++;
        in_stack[s[tp]] = 0;
        tp--;
      }
      scc[s[tp]] = sc; sz[sc]++;
      in_stack[s[tp]] = 0; --tp;
    }
  };
  for (ll i = 1; i <= m; i++) {
    ll a1, a2, c1, c2;
    cin >> a1 >> a2 >> c1 >> c2;
    g[2 * a1 + c1].push_back(2 * a2 + 1 - c2);
    g[2 * a2 + c2].push_back(2 * a1 + 1 - c1);
  }
  for (ll i = 0; i < 2 * n; i++) {
    if (not dfn[i])tarjan(i);
  }
  for (ll i = 0; i < 2 * n; i += 2) {
    if (scc[i] == scc[i + 1]) {
      puts("NO"); return;
    }
  }
  puts("YES");
  for (ll i = 0; i < 2 * n; i++) {
    cout << (scc[i] < scc[i + 1]) << " \n"[i == 2 * n - 1];
  }
}
signed main() {
  solve();
}