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
  vector<ll>a(n + 1); for (ll i = 1; i <= n; i++)cin >> a[i];
  vector<ll>dp(n + 1, 0);
  ll w = inv(n) % mod;
  dp[0] = 1 % mod;
  vector<ll>pre(n + 1); pre[0] = dp[0] % mod; ll ans = 0;
  for (ll i = 1; i <= n; i++) {
    dp[i] = (pre[i - 1] % mod * w % mod * a[i]) % mod;
    pre[i] = (pre[i - 1] % mod + pre[i - 1] % mod * w % mod) % mod;
    ans = (ans % mod + dp[i]) % mod;
  }
  cout << ans % mod << endl;
}
signed main() {
  solve();
}


#include<bits/stdc++.h>
using i8 = char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned int;
using f32 = float;
using i64 = long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;
const i64 mod = 998244353;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 ksm(i64 x, i64 y) {
  i64 ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret % mod;
}
i64 inv(i64 x) {
  return ksm(x, mod - 2) % mod;
}
void solve() {
  int n; cin >> n;
  vector<i64>a(n + 1, 0); for (int i = 1; i <= n; i++)cin >> a[i];
  vector<i64>dp(n + 5, 0);
  i64 w = inv(n) % mod;
  vector<i64>pre(n + 5, 0);
  for (int i = n; i >= 1; i--) {
    i64 cur = pre[i + 1] % mod * w % mod;
    dp[i] = cur % mod; dp[i] = (dp[i] % mod + a[i]) % mod;
    pre[i] = (dp[i] % mod + pre[i + 1]) % mod;
  }
  i64 ans = (pre[1] % mod * w) % mod;
  cout << ans << "\n";
}
signed main() {
  solve();
}