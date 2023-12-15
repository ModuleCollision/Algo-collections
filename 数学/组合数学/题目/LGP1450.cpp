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
void solve() {
  vector<i64>w(5); i64 n;
  for (i64 i = 1; i <= 4; i++)cin >> w[i]; cin >> n;
  dp[0] = 1;
  for (i64 i = 1; i <= 4; i++) {
    for (i64 j = w[i]; j <= 1e6; j++)dp[j] += dp[j - w[i]];
  }
  vector<i64>d(5);
  while (n--) {
    for (i64 i = 1; i <= 4; i++)cin >> d[i];
    i64 s; cin >> s;
    i64 res = dp[s]; // 1代表超额的

    i64 ps = 0;
    for (i64 j = 1; j < (1 << 4); j++) {
      i64 t = s; i64 cnt = 0;
      for (i64 k = 0; k < 4; k++) {
        if ((j >> k) & 1)t -= (w[k + 1] * (d[k + 1] + 1)), cnt++;
      }
      if (t < 0)continue;
      if (cnt & 1)ps += dp[t];
      else ps -= dp[t];
    }
    cout << dp[s] - ps << "\n";
  }
}
signed main() {
  solve();
}