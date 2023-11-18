#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll sz[maxn]; ll fa1[maxn], fa2[maxn], fa3[maxn];
ll find(ll x, ll fa[]) {
  while (x != fa[x])x = fa[x] = fa[fa[x]];
  return x;
}
void merge(ll x, ll y, ll fa[], bool f) {
  ll a = find(x, fa), b = find(y, fa);
  if (a == b)return;
  fa[a] = b;
  if (f)sz[b] += sz[a];
}
void solve() {
  ll n, k, l; cin >> n >> k >> l;
  iota(fa1 + 1, fa1 + 1 + n, 1);
  iota(fa2 + 1, fa2 + 1 + n, 1);
  iota(fa3 + 1, fa3 + 1 + n, 1);
  fill(sz + 1, sz + 1 + n, 1);
  for (ll i = 1; i <= k; i++) {
    ll u, v; cin >> u >> v;
    merge(u, v, fa1, false);
  }
  for (ll i = 1; i <= l; i++) {
    ll u, v; std::cin >> u >> v;
    ll a = find(u, fa1), b = find(v, fa1);
    if (a == b) {
      ll q = find(u, fa3), t = find(v, fa3);
      merge(u, v, fa3, true);
    }
    merge(u, v, fa2, false);
  }
  for (ll i = 1; i <= n; i++) {
    cout << sz[find(i, fa3)] << " \n"[i == n];
  }
}
signed main() {
  solve();
}