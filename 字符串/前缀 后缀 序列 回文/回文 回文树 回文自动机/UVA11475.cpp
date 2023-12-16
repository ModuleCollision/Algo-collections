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

/*Manacher板题*/
string s;
void solve() {
  i64 len = s.size();
  string st(len * 2 + 5, ' ');
  for (i64 i = 0; i < len; i++) {
    st[i * 2] = '#'; st[i * 2 + 1] = s[i];
  }
  st[len * 2] = '#';
  vector<i64>d(2 * len + 5);
  for (i64 i = 0, l = 0, r = -1; i < len * 2 + 1; i++) {
    i64 k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
    while (i - k >= 0 and i + k < 2 * len + 1 and st[i - k] == st[i + k])k++;
    d[i] = k--;
    if (i + k > r) {
      l = i - k; r = i + k;
    }
  }//维护的是st串的最长回文半径
  //st串'#'位对应s偶回文串 idx -> idx / 2 - 1
  //st串字母位对应s奇回文串 idx -> idx / 2
  //st回文半径对应s回文半径 d -> d / 2
  i64 idx = 0;
  for (i64 i = 1; i <= len * 2 - 1; i++) {
    if (i + d[i] - 1 == 2 * len) {
      idx = i; break;
    }
  }
  i64 r = idx - d[idx] + 1;
  for (i64 j = r - 1; j >= 1; j--) {
    if (isalpha(st[j]))s += st[j];
  }
  cout << s << endl;
}
signed main() {
  while (cin >> s) {
    solve();
  }
}