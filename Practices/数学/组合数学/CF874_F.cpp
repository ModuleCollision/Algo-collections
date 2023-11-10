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
//using u128 = __uint128_t;
using f128 = long double;
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 fac[maxn];
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 1e6; i++) {
    fac[i] = (fac[i - 1] % mod * i) % mod;
  }
}
i64 ksm(i64 x, i64 y) {
  i64 ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % mod;
    x = x % mod * x % mod;
    y >>= 1;
  }
  return ret % mod;
}
i64 inv(i64 x) {
  return ksm(x, mod - 2) % mod;
}
i64 comb(i64 n, i64 m) {
  if (m > n)return 0ll;
  return fac[n] % mod * inv(fac[m] % mod * fac[n - m] % mod) % mod;
}
void solve() {
  int n, m; cin >> n >> m; vector<i64>a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  map<i64, i64>cnt; i64 idx = 0;
  for (int i = 1; i <= n; i++) {
    cnt[a[i]]++;
  }
  vector<pair<i64, i64>>w(n + 5);
  for (auto [x, y] : cnt) {
    w[++idx] = {x, y};
  }
  vector<i64>pre(idx + 1); pre[0] = 1;
  for (int i = 1; i <= idx; i++) {
    pre[i] = (pre[i - 1] % mod * w[i].second) % mod;
  }
  i64 ans = 0;
  int l = 1; for (int r = 1; r <= idx; r++) {
    while (w[r].first - w[l].first >= m)l++;
    if (r - l + 1 == m) {
      i64 cur = pre[r] % mod * inv(pre[l - 1]) % mod;
      ans = (ans % mod + cur) % mod;
    }
  }
  cout << ans % mod << "\n";
}
signed main() {
  init();
  i32 T; cin >> T;
  while (T--)
    solve();
}