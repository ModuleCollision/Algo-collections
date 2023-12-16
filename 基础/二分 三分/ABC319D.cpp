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
  i64 n, m; std::cin >> n >> m; i64 l = 0, r = -1;
  vector<i64>A(n + 1, 0); for (i64 i = 1; i <= n; i++) {
    cin >> A[i]; A[i]++;
  }
  auto check = [&](i64 mid) {
    i64 cnt = 1; i64 cur = 0;
    for (i64 i = 1; i <= n; i++) {
      cur += A[i];
      if (cur - 1 > mid) {
        cnt++; cur = A[i]; continue;
      }//往下一排放
    }
    return cnt <= m;
  };
  r = accumulate(A.begin() + 1, A.begin() + 1 + n, 0) + n - 1;
  l = *max_element(A.begin() + 1, A.begin() + 1 + n);
  while (l < r) {
    i64 mid = (l + r) >> 1;
    if (check(mid))r = mid;
    else l = mid + 1;
  }
  cout << r << endl;
}
signed main() {
  solve();
}