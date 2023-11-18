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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
  string s; cin >> s;
  i64 Max = 0, Min = inf; i64 cur = 0;
  for (i64 i = 0; i < s.size(); i++) {
    if (s[i] == '+') {
      ++cur;
    } else if (s[i] == '-') {
      --cur; if (cur < Min) {
        Min = inf;
      }
      Max = min(Max, cur);
    } else if (s[i] == '1') {
      if (Min <= cur) {
        puts("No"); return;
      }
      Max = max(Max, cur);
    } else {
      if (Max >= cur or cur < 2) {
        puts("No"); return;
      }
      Min = min(Min, cur);
    }
  }
  puts("Yes");
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}