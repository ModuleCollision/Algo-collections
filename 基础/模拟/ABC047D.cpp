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
   i64 n, t; std::cin >> n >> t;
  vector< i64>A(n + 1, 0); for ( i64 i = 1; i <= n; i++)cin >> A[i];
  vector< i64>suf(n + 1, 0);
  suf[n] = A[n];
  for ( i64 i = n - 1; i >= 1; i--) {
    suf[i] = max(A[i], suf[i + 1]);
  }
   i64 d = 0;
  for ( i64 i = 1; i <= n - 1; i++) {
    d = max(suf[i + 1] - A[i], d);
  }
  std::map< i64,  i64>cnt;  i64 ans = 0;
  for ( i64 i = 1; i <= n; i++)cnt[A[i]]++;
  for ( i64 i = 1; i <= n; i++) {
    cnt[A[i]]--; if (cnt[A[i]] == 0)cnt.erase(A[i]);
    ans += cnt[A[i] + d];
  }
  cout << ans << endl;
}
signed main() {
  solve();
}