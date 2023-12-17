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

string s;
void solve() {
  i64 n, m; std::cin >> n >> m;
  vector<i64>w(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> s;
    for (i64 j = 0; j < s.size(); j++) {
      if (s[j] == '1')w[i] += (1 << j);
    }
  }
  vector<i64>dp1(n + 1, inf); dp1[n] = 0;
  for (i64 i = n - 1; i >= 1; i--) {
    for (i64 j = 0; j < m; j++) {
      if ((w[i] >> j) & 1) {
        dp1[i] = min(dp1[i], dp1[i + j + 1] + 1);
      }
    }
  }
  vector<i64>dp2(n + 1, inf); dp2[1] = 0;
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 0; j < m; j++) {
      if ((w[i] >> j) & 1)dp2[i + j + 1] = min(dp2[i + j + 1], dp2[i] + 1);
    }
  }
  vector<i64>ans(n + 1, inf);
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 0; j < m; j++) {
      if ((w[i] >> j) & 1) {
        for (i64 k = i + 1; k < i + j + 1; k++)ans[k] = min(ans[k], dp2[i] + dp1[i + j + 1] + 1);
      }
    }
  }
  for (i64 i = 2; i <= n - 1; i++) {
    if (ans[i] >= inf) {
      cout << -1 << " ";
    } else cout << ans[i] << " ";
  }
  cout << endl;
}
signed main() {
  solve();
}