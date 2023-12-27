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
  i64 n, k, a, b; std::cin >> n >> k >> a >> b;
  vector<char>t = {'G', 'B'};
  vector<i64>cnt = {a, b};
  if (a < b) {
    swap(cnt[0], cnt[1]);
    swap(t[0], t[1]);
  }
  string ans = ""; bool f = 1;
  i64 cur = 0, pre = 0;
  for (i64 i = 0; i < n; i++) {
    if (pre == k) {
      cur ^= 1;
      if (cnt[cur] == 0) {
        puts("NO"); return;
      }
      cnt[cur]--;
      ans += t[cur];
      pre = 1;
    } else {
      if (n - i > k) {
        if (cnt[cur ^ 1] > cnt[cur]) {
          cur ^= 1;
          pre = 0;
        }
      }
      if (cnt[cur] == 0) {
        cur ^= 1; pre = 0;
        if (cnt[cur] == 0) {
          puts("NO"); return;
        }
      }
      ans += t[cur];
      pre++;
      cnt[cur]--;
    }
  }
  cout << ans << endl;
}
signed main() {
  //i64 T; std::cin >> T;
  //while (T--)
  solve();
}