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
  i64 n; std::cin >> n;
  i64 idx = 0;
  for (i64 i = 2; i <= 26; i++) {
    if (n % i != 0) {
      idx = i; break;
    }
  }
  string buf = "";
  for (i64 i = 0; i <= 25; i++) {
    buf += char('a' + i);
  }
  //cout << buf << endl;
  for (i64 i = 0; i < n; i++) {
    putchar(buf[i % idx]);
  }
  cout << endl;
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}