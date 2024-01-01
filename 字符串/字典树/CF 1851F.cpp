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
  i64 v[2]; i64 idx;
};
void solve() {
  i64 n, k; std::cin >> n >> k;
  vector<sq>tr; tr.push_back(sq());
  auto add = [&](i64 x, i64 idx) {
    i64 u = 0;
    for (i64 i = k - 1; i >= 0; i--) {
      i64 b = ((x >> i) & 1);
      if (not tr[u].v[b]) {
        tr[u].v[b] = tr.size();
        tr.push_back(sq());
      }
      u = tr[u].v[b];
    }
    tr[u].idx = idx;
  };
  i64 s = 0, y = 0, z = 0; i64 w = 0;
  auto get = [&](i64 x, i64 idx) {
    i64 f = 0; i64 u = 0; i64 q = 0;
    for (i64 i = k - 1; i >= 0; i--) {
      i64 b = (x >> i) & 1;
      if (tr[u].v[b]) {
        u = tr[u].v[b];
        q |= (1ll << i);
        if (not b)f |= (1ll << i);
      }
      else if (tr[u].v[b ^ 1])u = tr[u].v[b ^ 1];
      else return;
    }
    i64 p = tr[u].idx;
    //cout << "#" << p << endl;
    if (q >= w) {
      w = q; z = f; y = idx; s = p;
    }
  };
  vector<i64>A(n + 1, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  add(A[1], 1);
  for (i64 i = 2; i <= n; i++) {
    get(A[i], i);
    add(A[i], i);
  }
  cout << s << " " << y << " " << z << endl;
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}