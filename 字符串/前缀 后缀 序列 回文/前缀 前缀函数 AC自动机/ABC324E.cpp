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
  int n; string t;
  std::cin >> n >> t;
  vector<string> s(n + 1);
  for (i64 i = 1; i <= n; i++)cin >> s[i];
  vector<i64> st(n + 1), en(n + 1);
  for (int i = 1; i <= n; ++i) {
    int hoge = 0;
    for (int j = 0; j < s[i].size(); ++j) {
      if (s[i][j] == t[hoge]) {
        ++hoge;
        if (t.size() <= hoge) break;
      }
    }
    st[i] = hoge;
    hoge = 0;
    for (int j = s[i].size() - 1; j >= 0; j--) {
      if (s[i][j] == t[t.size() - 1 - hoge]) {
        ++hoge;
      }
    }
    en[i] = hoge;
  }
  sort(st.begin() + 1, st.end()); sort(en.begin() + 1, en.end());
  i64 ans = 0;

  for (int i = 1; i <= n; i++) {
    i64 cur = st[i];
    int kore = t.size() - cur;
    i64 num = en.end() - lower_bound(en.begin() + 1, en.end(), kore);

    ans += num;
  }

  std::cout << ans << "\n";
}
int main() {
  solve();
  return 0;
}
