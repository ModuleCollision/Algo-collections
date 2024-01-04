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

std::vector<i64> Prefix(string s) {
  i64 len = s.size();
  std::vector<i64>p(len + 5, 0);
  for (i64 i = 1; i < len; i++) {
    i64 j = p[i - 1];
    while (j > 0 and s[i] != s[j])j = p[j - 1];
    if (s[i] == s[j])j++;
    p[i] = j;
  }//KMP函数板题
  return p;
}


void solve() {
  string s; std::cin >> s;
  i64 len = s.size();
  auto p = Prefix(s);
  std::cout << len - p[len - 1] << "\n" << "\n";
}
int main() {
  i64 T; std::cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}