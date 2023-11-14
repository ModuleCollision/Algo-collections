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
ll fac[maxn];
void init(ll n) {
  fac[0] = 1;
  for (ll i = 1; i <= n; i++) {
    fac[i] = (fac[i - 1] % mod * i) % mod;
  }
}
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
ll comb(ll n, ll m) {
  if (m > n)return 0ll;
  return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
  ll n, k; cin >> n >> k; init(n);
  vector<vector<ll>>tr(n + 1);
  for (ll i = 1; i <= n; i++) {
    ll u, v; cin >> u >> v;
    tr[u].push_back(v); tr[v].push_back(u);
  }
  vector<ll>dp(n + 1);
  if (k % 2 == 1) {
    puts("1"); return;
  }
  ll ans = 0;
  function<void(ll, ll)>dfs = [&](ll u, ll f) {
    dp[u] = 1;
    for (auto v : tr[u]) {
      if (v == f)continue;
      dfs(v, u);
      dp[u] += dp[v];
    }
    ans = (ans % mod + comb(dp[u], k / 2) % mod * comb(n - dp[u], k / 2) % mod) % mod;
  };
  dfs(1, 0);
  cout << (ans % mod * inv(comb(n, k)) % mod + 1) % mod << endl;
}
signed main() {
  solve();
}