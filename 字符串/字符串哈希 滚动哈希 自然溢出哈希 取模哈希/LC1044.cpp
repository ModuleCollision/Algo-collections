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
class Solution {
public:
  u64 p = 13331;
  string longestDupSubstring(string s) {
    u64 n = s.size();
    s = " " + s;
    vector<u64>hash(n + 1);
    vector<u64>f(n + 1); f[0] = 1;
    for (u64 i = 1; i <= n; i++) {
      hash[i] = ((hash[i - 1]) * p + s[i]);
      f[i] = f[i - 1] * p;
    }
    auto get = [&](u64 l, u64 r) {
      return ((hash[r] - hash[l - 1] * f[r - l + 1]));
    };
    std::set<u64>st;
    auto check = [&](u64 len) {
      st.clear();
      for (u64 i = 1; i + len - 1 <= n; i++) {
        auto cur = get(i, i + len - 1);
        if (st.count(cur)) {
          return true;
        }
        st.insert(cur);
      }
      return false;
    };
    u64 l = 1, r = n; u64 ans = 0;
    while (l <= r) {
      u64 mid = (l + r) >> 1;
      if (check(mid)) {
        ans = mid, l = mid + 1;
      } else r = mid - 1;
    }
    if (not ans) return ""; st.clear();
    for (u64 i = 1; i + ans - 1 <= n; i ++) {
      u64 cur = get(i, i + ans - 1);
      if (st.count(cur)) {
        return s.substr(i, ans);
      }
      st.insert(cur);
    }
    return "";
  }
};