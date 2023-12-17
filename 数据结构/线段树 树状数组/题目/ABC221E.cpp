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

void solve() {
  i64 n; std::cin >> n; vector<i64>A(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  auto ksm = [&](i64 x, i64 y) {
    i64 ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod; y >>= 1;
    }
    return ret % mod;
  };
  auto inv = [&](i64 x) {
    return ksm(x, mod - 2) % mod;
  };
  vector<i64>w; for (i64 i = 1; i <= n; i++)w.push_back(A[i]);
  sort(w.begin(), w.end());
  w.erase(unique(w.begin(), w.end()), w.end());
  std::unordered_map<i64, i64>k; for (i64 i = 0; i < w.size(); i++)k[w[i]] = i + 1;
  std::vector<i64>tr(n + 1, 0);
  auto add = [&](i64 idx, i64 v) {
    for (; idx <= n; idx += (idx & -idx))tr[idx] = (tr[idx] % mod + v) % mod;
  };
  auto query = [&](i64 idx) {
    i64 ret = 0;
    for (; idx >= 1; idx -= (idx & -idx))ret = (ret % mod + tr[idx]) % mod;
    return ret % mod;
  };
  i64 ans = 0;
  for (i64 i = n; i >= 1; i--) {
    i64 q = ((query(n) - query(k[A[i]] - 1)) % mod + mod) % mod;
    i64 re = inv(ksm(2, i + 1) % mod) % mod;
    ans = (ans % mod + q % mod * re) % mod;
    i64 idx = k[A[i]];
    add(idx, ksm(2, i) % mod);
  }
  cout << ans << endl;
}
signed main() {
  solve();
}