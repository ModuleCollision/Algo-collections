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
  vector<string>s(n + 5);
  std::set<string>st1, st2;
  for (i64 i = 0; i < n; i++) {
    std::cin >> s[i];
    st1.insert(s[i]);
  }
  for (i64 i = 0; i < n; i++) {
    string k;
    for (i64 j = 0; j < n; j++) {
      k += s[j][i];
    }
    st2.insert(k);
  }
  i64 ans = inf;
  if (st1.size() == 1) {
    i64 cnt = 0;
    for (i64 j = 0; j < n; j++) {
      if (s[0][j] == '1')cnt++;
    }
    ans = min({ans, cnt, n - cnt});
  }
  if (st2.size() == 1) {
    i64 cnt = 0;
    for (i64 i = 0; i < n; i++) {
      if (s[i][0] == '1')cnt++;
    }
    ans = min({ans, cnt, n - cnt});
  }
  if (st1.size() == 2) {
    i64 cnt = 0;
    bool f = 1;
    string s1 = s[0], s2;
    for (i64 i = 1; i < n; i++) {
      if (s[i] != s1) {
        s2 = s[i]; break;
      }
    }
    for (i64 i = 0; i < n; i++) {
      i64 f1 = s1[i] - '0';
      i64 f2 = s2[i] - '0';
      if ((f1 ^ f2) == 0) {
        f = 0; break;
      }
    }
    i64 cnt1 = 0; i64 cnt2 = 0;
    if (f) {
      for (i64 i = 0; i < n; i++) {
        if (s[i] == s1)cnt1++;
      }
      for (i64 j = 0; j < n; j++) {
        if (s[0][j] == '1')cnt2++;
      }
      ans = min({ans, cnt1 + cnt2, cnt1 + n - cnt2});
      ans = min({ans, n - cnt1 + cnt2, n - cnt1 + n - cnt2});
    }
  }
  if (ans == inf) {
    puts("-1"); return;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}