/*300兆字节 1- 2 秒*/

#include<bits/extc++.h>

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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


i64 cnt[maxn]; i64 tr1[maxn]; i64 tr2[maxn];
void add(i64 idx, i64 v, i64 tr[]) {
  for (; idx <= (2e5); idx += (idx & -idx))tr[idx] = (tr[idx] % mod + v) % mod;
}
i64 query(i64 idx, i64 tr[]) {
  i64 ret = 0;
  for (; idx >= 1; idx -= (idx & -idx))ret = (ret % mod + tr[idx]) % mod;
  return ret;
}
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
  i64 n; cin >> n;
  vector<i64>A(n + 1, 0), ans(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  for (i64 i = 1; i <= n; i++) {
    i64 f1 = cnt[A[i]] % mod;
    i64 f2 = query(A[i] - 1, tr1);
    i64 f3 = ((query(2e5, tr2) - query(A[i], tr2)) % mod + mod) % mod;
    ans[i] = ans[i - 1] % mod;
    i64 v1 = (2 % mod * f3) % mod;
    i64 v2 = ((2 * f1 % mod + 2 * f2 % mod + 1) % mod + mod) % mod;
    ans[i] = (ans[i] % mod + v1) % mod;
    ans[i] = (ans[i] % mod + v2 % mod * A[i]) % mod;
    cnt[A[i]]++; add(A[i], 1, tr1); add(A[i], A[i], tr2);
  }
  for (i64 i = 1; i <= n; i++) {
    cout << ans[i] % mod*inv(i * i) % mod << endl;
  }
}
signed main() {
  solve();
}