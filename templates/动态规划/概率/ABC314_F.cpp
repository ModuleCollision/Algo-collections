#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 4e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll n; ll fa[maxn], sz[maxn]; vector<pair<ll, ll>>tr[maxn];
ll ksm(ll x, ll y) {
  ll ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret % mod;
}
ll inv(ll x) {
  return ksm(x, mod - 2) % mod;
}
ll find(ll x) {
  while (x != fa[x])x = fa[x] = fa[fa[x]];
  return x;
}
void merge(ll x, ll y) {
  ll a = find(x), b = find(y);
  fa[a] = b; sz[b] += sz[a];
}
void solve() {
  std::cin >> n;
  for (ll i = 1; i <= n; i++) {
    fa[i] = i; sz[i] = 1;
  }
  ll tot = n + 1;
  for (ll i = 1; i <= n - 1; i++) {
    ll p, q; std::cin >> p >> q; ll f1 = find(p), f2 = find(q);
    ll sz1 = sz[f1], sz2 = sz[f2];
    ++tot; fa[tot] = tot; sz[tot] = 0;
    merge(f1, tot), merge(f2, tot);
    ll k1 = sz1 % mod * inv((sz1 % mod + sz2) % mod) % mod;
    ll k2 = ((1 - k1) % mod + mod) % mod;
    tr[tot].push_back({f1, k1});
    tr[f1].push_back({tot, k1});
    tr[f2].push_back({tot, k2});
    tr[tot].push_back({f2, k2});
  }
  vector<ll>ans(tot + 5);
  function<void(ll, ll, ll)>dfs = [&](ll u, ll f, ll q) {
    for (auto [v, w] : tr[u]) {
      if (v == f)continue;
      ans[v] = (q % mod + w) % mod;
      dfs(v, u, ans[v]);
    }
  };
  dfs(tot, 0, 0);
  for (ll i = 1; i <= n; i++)cout << ans[i] % mod << " ";
  cout << endl;
}
signed main() {
  solve();
}