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
  i64 n, k; std::cin >> n >> k;
  vector<i64>A(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  i64 l = 0, r = *max_element(A.begin() + 1, A.begin() + 1 + n);
  auto check = [&](i64 x) {
    i64 res = 0;
    for (i64 i = 1; i <= n; i++) {
      res += min(A[i], x);
    }
    return res <= k;
  };
  i64 d = 0;
  while (l < r) {
    i64 mid = (l + r + 1) >> 1;
    if (check(mid))l = mid;
    else r = mid - 1;
  }
  for (i64 i = 1; i <= n; i++) {
    i64 t = min(l, A[i]);
    A[i] -= t; k -= t;
  }
  for (i64 i = 1; i <= n; i++) {
    if (A[i] and k)A[i]--, k--;
  }
  for (i64 i = 1; i <= n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
signed main() {
  solve();
}