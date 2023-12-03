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
i64 dp[maxn];
/*求解十进制sosdp和*/
void solve() {
  i64 n; cin >> n;
  vector<i64>a(n + 5);
  for (i64 i = 1; i <= n; i++) {
    cin >> a[i]; dp[a[i]]++;
  }
  for (i64 j = 1; j < 1e6; j *= 10) {
    for (i64 i = 0; i < 1e6; i++) {
      if ((i / j) % 10 > 0) {
        dp[i] += dp[i - j];
      }
    }
  }
  i64 ans = 0;
  for (i64 i = 1; i <= n; i++) {
    ans += dp[999999 - a[i]];
    bool f = false;
    for (; a[i] > 0; a[i] /= 10) {
      if (a[i] % 10 > 4) {
        f = true; break;
      }
    }
    if (not f)ans--;
  }
  cout << ans / 2 << "\n";
}
signed main() {
  solve();
}