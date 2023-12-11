#include<bits/stdc++.h>
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
const i64 mod = 998244353;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
set<i64>s[maxn];
void solve() {
  i64 n, q; cin >> n >> q;
  for (i64 i = 1; i <= n; i++) {
    i64 x; cin >> x;
    s[i].insert(x);
  }
  while (q--) {
    i64 a, b; cin >> a >> b;
    if (s[a].size() <= s[b].size()) {
      for (auto x : s[a]) {
        s[b].insert(x);
      }
      s[a].clear();
    } else {
      for (auto x : s[b]) {
        s[a].insert(x);
      }
      s[b].clear();
      swap(s[a], s[b]);
    }
    cout << s[b].size() << "\n";
  }
}
signed main() {
  solve();
}