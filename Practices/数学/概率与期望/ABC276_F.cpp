#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll cnt[maxn]; ll tr1[maxn]; ll tr2[maxn];
void add(ll idx, ll v, ll tr[]) {
  for (; idx <= (2e5); idx += (idx & -idx))tr[idx] = (tr[idx] % mod + v) % mod;
}
ll query(ll idx, ll tr[]) {
  ll ret = 0;
  for (; idx >= 1; idx -= (idx & -idx))ret = (ret % mod + tr[idx]) % mod;
  return ret;
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
void solve() {
  ll n; cin >> n;
  vector<ll>A(n + 1, 0), ans(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  for (ll i = 1; i <= n; i++) {
    ll f1 = cnt[A[i]] % mod;
    ll f2 = query(A[i] - 1, tr1);
    ll f3 = ((query(2e5, tr2) - query(A[i], tr2)) % mod + mod) % mod;
    ans[i] = ans[i - 1] % mod;
    ll v1 = (2 % mod * f3) % mod;
    ll v2 = ((2 * f1 % mod + 2 * f2 % mod + 1) % mod + mod) % mod;
    ans[i] = (ans[i] % mod + v1) % mod;
    ans[i] = (ans[i] % mod + v2 % mod * A[i]) % mod;
    cnt[A[i]]++; add(A[i], 1, tr1); add(A[i], A[i], tr2);
  }
  for (ll i = 1; i <= n; i++) {
    cout << ans[i] % mod*inv(i * i) % mod << endl;
  }
}
signed main() {
  solve();
}