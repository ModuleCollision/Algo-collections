#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 305;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n; cin >> n;
  vector<vector<ll>>w(n + 1);
  for (ll i = 1; i <= n; i++) {
    for (ll j = i; j <= n; j += i) {
      w[j].push_back(i);
    }
  }
  vector<ll>pos(n + 1); std::iota(pos.begin() + 1, pos.begin() + 1 + n, 1);
  vector<ll>q(n + 1);
  for (ll i = 1; i <= n; i++)cin >> q[i];
  sort(pos.begin() + 1, pos.begin() + 1 + n, [&](ll x, ll y)->bool{
    return q[x] < q[y];
  });
  auto ksm = [&](ll x, ll y) {
    ll ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  };
  ll ans = 0;
  ll t = n; vector<bool>vis(n + 1, true);
  for (ll i = n; i >= 1; i--) {
    ll p = pos[i];
    ll cnt = 0; for (auto v : w[p])if (vis[v]) {
        cnt++;
      }
    t -= cnt;
    ans = (ans % mod + q[p] % mod * (ksm(2, cnt) - 1) % mod * ksm(2, t)) % mod;
    for (auto v : w[p])vis[v] = false;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}