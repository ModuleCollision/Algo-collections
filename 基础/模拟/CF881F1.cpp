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
  i64 mxsuf = 0, mnsuf = 0, mxans = 0, mnans = 0;
};

void solve() {
  i64 n; cin >> n;  i64 tot = 0;
  vector< i64>pre(n + 1, 0);
  vector<sq>tr; tr.push_back(sq()); tot++;
  tr[0].mxsuf = tr[0].mxans = 1;
  string opt;
  while (n--) {
    cin >> opt;
    if (opt == "+") {
      i64 v, x; cin >> v >> x;
      auto cur = sq(); v--;
      cur.mxsuf = max(0 i64, tr[v].mxsuf + x);
      cur.mnsuf = min(0 i64, tr[v].mnsuf + x);
      cur.mxans = max(tr[v].mxans, cur.mxsuf);
      cur.mnans = min(tr[v].mnans, cur.mnsuf);
      tr.push_back(cur);
    } else {
      i64 u, v, x; cin >> u >> v >> x;
      v--;
      if (x >= tr[v].mnans and x <= tr[v].mxans) {
        puts("Yes");
      } else puts("No");
    }
  }
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}