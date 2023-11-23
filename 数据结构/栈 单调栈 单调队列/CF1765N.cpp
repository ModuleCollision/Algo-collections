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
i64 k; string s;
signed main() {
  i64 T; cin >> T;
  while (T--) {
    cin >> s >> k;
    i64 j = 0;
    for (int i = 0; i <= k; i++) {
      if (s[i] > '0' and s[i] < s[j]) {
        j = i;
      }
    }
    k -= j;
    string ans; ans.push_back(s[j]);
    for (i64 i = j + 1; i < s.size(); i++) {
      while (ans.size() > 1 and ans.back() > s[i] and k) {
        k--; ans.pop_back();
      }
      ans.push_back(s[i]);
    }
    while (k)ans.pop_back(), k--;
    cout << ans << "\n";
  }
}