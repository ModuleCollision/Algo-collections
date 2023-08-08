#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n, s; std::cin >> n >> s;
  vector<array<ll, 3>>e(n + 1);
  for (ll i = 1; i <= n - 1; i++) {
    ll u, v, w; std::cin >> u >> v >> w;
    e[i] = {u, v, w};
  }
  std::sort(e.begin() + 1, e.begin() + n, [&](array<ll, 3>x, array<ll, 3>y)->bool{
    return x[2] < y[2];
  });
  ll ans = 1;
  vector<ll>sz(n + 5, 1);
  vector<ll>fa(n + 5, 0); for (ll i = 1; i <= n; i++)fa[i] = i;
  auto find = [&](ll x) {
    while (x != fa[x])x = fa[x] = fa[fa[x]];
    return x;
  };
  auto merge = [&](ll x, ll y) {
    ll a = find(x), b = find(y);
    fa[a] = b; sz[b] += sz[a];
  };
  auto ksm = [&](ll a, ll b) {
    ll ret = 1;
    while (b) {
      if (b & 1)ret = ret * a % mod;
      a = a * a % mod;
      b >>= 1;
    }
    return ret % mod;
  };
  for (ll i = 1; i <= n - 1; i++) {
    auto [u, v, w] = e[i];
    ll x = find(u), y = find(v);
    ans = (ans % mod * ksm(s - w + 1, sz[x] * sz[y] - 1) % mod) % mod;
    merge(u, v);
  }
  cout << ans % mod << endl;
}
signed main() {
  ll t; std::cin >> t;
  while (t--)
    solve();
}