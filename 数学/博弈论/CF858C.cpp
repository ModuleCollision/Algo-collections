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


i64 prime[maxn]; bool vis[maxn]; i64 cnt = 0;
i64 buf[maxn];
void solve() {
  i64 n;
  std::cin >> n; vector<i64>A(2 * n + 5, 0);
  i64 ans = 0, sum = 0;
  for (i64 i = 1; i <= (n << 1); i++) {
    std::cin >> A[i]; ans += abs(A[i]);
    sum += abs(A[i] + 1);
  }
  if (n == 1) {
    ans = min(ans, A[1] - A[2]);
  } else if (n == 2) {
    ans = min(ans, abs(A[1] - 2) + abs(A[2] - 2) + abs(A[3] - 2) + abs(A[4] - 2));
  }
  if (not(n & 1)) {
    for (i64 i = 1; i <= (n << 1); i++) {
      ans = min(ans, sum - abs(A[i] + 1) + abs(A[i] - n));
    }
  }
  cout << abs(ans) << endl;
}
signed main() {

  i64 T; std::cin >> T;
  while (T--)
    solve();
}