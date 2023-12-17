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

struct sq {
  i64 a; i64 idx;
};
void solve() {
  i64 n, m; std::cin >> n >> m;
  vector<sq>p(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> p[i].a; p[i].idx = i;
  }
  sort(p.begin() + 1, p.end(), [&](auto x, auto y)->bool{
    return x.a > y.a;
  });
  vector<i64>b(m + 1); vector f(m + 1, vector<i64>(n + 1, 0));
  for (i64 i = 0; i < m; i++)cin >> b[i];
  for (i64 i = 0; i < m; i++) {
    i64 l = 0, r = 0;
    for (l = 0, r = 0; l <= n; l++) {
      while ((r - l)*p[r].a < b[i] and r <= n)r++;
      f[i][l] = r;
    }
  }
  vector<i64>dp((1 << m) + 5, 0); auto pre = dp;
  for (i64 i = 1; i < (1 << m); i++)dp[i] = n + 1;
  for (i64 i = 0; i < (1 << m); i++) {
    if (dp[i] != n + 1) {
      for (i64 j = 0; j < m; j++) {
        if (((i >> j) & 1) == 0) {
          if (dp[i | (1 << j)] > f[j][dp[i]]) {
            dp[i | (1 << j)] = f[j][dp[i]];
            pre[i | (1 << j)] = j;
          }
        }
      }
    }
  }
  if (dp[(1 << m) - 1] != n + 1) {
    puts("YES");
  } else {
    puts("NO"); return;
  }
  vector<i64>num(m + 5, 0);
  for (i64 i = (1 << m) - 1; i; i -= (1 << pre[i])) {
    num[pre[i]] = dp[i - (1 << pre[i])];
  }
  for (i64 i = 0; i < m; i++) {
    cout << f[i][num[i]] - num[i] << " ";
    for (i64 j = num[i] + 1; j <= f[i][num[i]]; j++) {
      cout << p[j].idx << " ";
    }
    cout << endl;
  }
}
signed main() {
  solve();
}