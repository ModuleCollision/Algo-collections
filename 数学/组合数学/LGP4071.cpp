#include<bits/stdc++.h>
using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 fac[maxn]; i64 dp[maxn];
void init() {
  fac[0] = 1; dp[2] = 1;
  for (i64 i = 3; i <= 1e6; i++)dp[i] = (i - 1) % mod * (dp[i - 1] % mod + dp[i - 2]) % mod;
  for (i64 i = 1; i <= 1e6; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
}
i64 ksm(i64 x, i64 y) {
  i64 ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % mod;
    x = x % mod * x % mod; y >>= 1;
  }
  return ret % mod;
}
i64 inv(i64 x) {
  return ksm(x, mod - 2) % mod;
}
i64 comb(i64 n, i64 m) {
  if (m > n)return 0ll;
  if (m < 0)return 0ll;
  return (fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod)) % mod;
}

void solve() {
  init();
  i64 T; cin >> T; i64 f = T;
  vector<i64>w;
  while (f--) {
    i64 n, m; cin >> n >> m;
    if (n == m) {
      puts("1"); continue;
    }
    i64 ans = comb(n, m) % mod;
    ans = (ans % mod * dp[max(0ll, n - m)]) % mod;
    cout << ans << "\n";
  }
}
signed main() {
  solve();
}