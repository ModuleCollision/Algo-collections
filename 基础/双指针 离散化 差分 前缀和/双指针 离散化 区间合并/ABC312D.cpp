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
  i64 n, m, p; std::cin >> n >> m >> p;
  vector<i64>A(n + 5);
  vector<i64>B(m + 5);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  for (i64 i = 1; i <= m; i++)cin >> B[i];
  sort(A.begin() + 1, A.begin() + 1 + n);
  sort(B.begin() + 1, B.begin() + 1 + m);
  vector<i64>pre(m + 1);
  for (i64 i = 1; i <= m; i++)pre[i] = (pre[i - 1] + B[i]);
  i64 ans = 0;
  for (i64 i = 1, j = m; i <= n; i++) {
    while (A[i] + B[j] >= p and j >= 1)j--;
    ans += (m - j) * p;
    ans += (j) * A[i] + (pre[j]);
  }
  cout << ans << endl;
}
signed main() {
  solve();
}