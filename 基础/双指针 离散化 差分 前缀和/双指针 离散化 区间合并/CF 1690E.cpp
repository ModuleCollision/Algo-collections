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
  i64 n, k; cin >> n >> k;
  vector<i64>A(n + 1, 0); i64 ans = 0;
  for (i64 i = 1; i <= n; i++)cin >> A[i], ans += (A[i] / k), A[i] %= k;
  sort(A.begin() + 1, A.begin() + 1 + n);
  for (i64 l = 1, r = n; l < r; l++) {
    if (A[l] + A[r] < k) {
      continue;
    } else {
      ans += 1; r--;
    }
  }
  cout << ans << endl;
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}