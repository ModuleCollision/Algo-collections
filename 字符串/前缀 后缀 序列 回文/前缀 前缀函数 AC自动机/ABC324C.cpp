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
  i64 n; string f; std::cin >> n >> f;
  vector<string>ss(n + 1);
  vector<bool>vis(n + 1, false);
  for (i64 i = 1; i <= n; i++) {
    cin >> ss[i];
  }
  auto check = [&](string s, string t) {
    if (abs((i64)s.size() - (i64)t.size()) > 1)return false;
    i64 cnt = 0;
    if (s.size() == t.size()) {
      for (i64 i = 0; i < t.size(); i++)if (s[i] != t[i])cnt++;
      return cnt <= 1;
    }
    i64 l = 0;
    for (i64 i = 0; i < t.size(); i++) {
      if (l < s.size() and s[l] == t[i])l++;
    }
    if (l == s.size())return true;
    l = 0;
    for (i64 i = 0; i < s.size(); i++) {
      if (l < t.size() and t[l] == s[i])l++;
    }
    if (l == t.size())return true;
    return false;
  }; i64 cnt = 0;
  for (i64 i = 1; i <= n; i++) {
    if (check(ss[i], f))cnt++, vis[i] = 1;
  }
  cout << cnt << endl;
  for (i64 i = 1; i <= n; i++)if (vis[i])cout << i << " ";
}
int main() {
  solve();
  return 0;
}