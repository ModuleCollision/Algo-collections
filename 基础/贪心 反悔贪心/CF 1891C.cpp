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
  i64 n; cin >> n;
  vector<i64>a(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> a[i];
  sort(a.begin() + 1, a.begin() + 1 + n);
  i64 x = 0, ans = 0, i = 1, j = n;
  while (i < j) {
    if (x + a[i] >= a[j]) {
      i64 t = a[j] - x;
      ans += t + 1;
      j--; a[i] -= t; x = 0;
    } else {
      x += a[i]; ans += a[i++];
    }
  }
  if (a[i] == 0) {
    cout << ans << "\n";
    return;
  }
  i64 k = a[j] - x;
  ans += (k % 2 ? (a[j] == 1 ? 1 : k / 2 + 2) : k / 2 + 1);
  cout << ans << "\n";
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}