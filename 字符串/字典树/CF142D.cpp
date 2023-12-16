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

struct sq {
  i64 v[15];
};
void solve() {
  i64 tot = 0; i64 n, m; cin >> n >> m;
  vector p(n + 1, vector<i64>(m + 1, 0));
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= m; j++)cin >> p[i][j];
  }
  vector<sq>tr; tr.push_back(sq());
  auto add = [&](vector<i64>s) {
    i64 u = 0;
    for (i64 i = 1; i <= m; i++) {
      if (not tr[u].v[s[i]]) {
        tr[u].v[s[i]] = tr.size();
        tr.push_back(sq());
      }
      u = tr[u].v[s[i]];
    }
  };
  for (i64 i = 1; i <= n; i++) {
    auto tmp = p[i];
    for (i64 j = 1; j <= m; j++) {
      tmp[p[i][j]] = j;
    }
    add(tmp);
  }
  auto get = [&](vector<i64>s) {
    i64 cnt = 0; i64 u = 0;
    for (i64 i = 1; i <= m; i++) {
      if (not tr[u].v[s[i]])return cnt;
      cnt++; u = tr[u].v[s[i]];
    }
    return cnt;
  };
  for (i64 i = 1; i <= n; i++) {
    cout << get(p[i]) << " \n"[i == n];
  }
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}