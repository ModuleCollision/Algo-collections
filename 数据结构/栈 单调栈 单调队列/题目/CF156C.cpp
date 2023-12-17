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
  string s; i64 pos; std::cin >> s >> pos;
  int n = s.size();
  s = " " + s;
  i64 l = 1, r = n; i64 m = 0;
  while (l <= r) {
    i64 mid = (l + r) >> 1;
    if ((n + n - mid + 1) * (mid) / 2 < pos) {
      l = mid + 1, m = mid;
    } else r = mid - 1;
  }
  vector<char>st;
  pos -= (n + n - m + 1) * m / 2;
  for (i64 i = 1; i <= n; i++) {
    while (st.size() and m and st.back() > s[i]) {
      st.pop_back(); m--;
    }
    st.push_back(s[i]);
  }
  putchar(st[pos - 1]);
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}