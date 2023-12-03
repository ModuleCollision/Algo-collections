#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n; std::cin >> n; vector<ll>A(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  auto ksm = [&](ll x, ll y) {
    ll ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod; y >>= 1;
    }
    return ret % mod;
  };
  auto inv = [&](ll x) {
    return ksm(x, mod - 2) % mod;
  };
  vector<ll>w; for (ll i = 1; i <= n; i++)w.push_back(A[i]);
  sort(w.begin(), w.end());
  w.erase(unique(w.begin(), w.end()), w.end());
  std::unordered_map<ll, ll>k; for (ll i = 0; i < w.size(); i++)k[w[i]] = i + 1;
  std::vector<ll>tr(n + 1, 0);
  auto add = [&](ll idx, ll v) {
    for (; idx <= n; idx += (idx & -idx))tr[idx] = (tr[idx] % mod + v) % mod;
  };
  auto query = [&](ll idx) {
    ll ret = 0;
    for (; idx >= 1; idx -= (idx & -idx))ret = (ret % mod + tr[idx]) % mod;
    return ret % mod;
  };
  ll ans = 0;
  for (ll i = n; i >= 1; i--) {
    ll q = ((query(n) - query(k[A[i]] - 1)) % mod + mod) % mod;
    ll re = inv(ksm(2, i + 1) % mod) % mod;
    ans = (ans % mod + q % mod * re) % mod;
    ll idx = k[A[i]];
    add(idx, ksm(2, i) % mod);
  }
  cout << ans << endl;
}
signed main() {
  solve();
}