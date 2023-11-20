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
const i64 mod = 998244353;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 p1[maxn], p2[maxn], dp[6730][6730], tot = 0;
i64 d[maxn];
void solve() {
  i64 n; cin >> n;
  tot = 0;
  i64 sq = (i64)sqrt(n);
  for (i64 i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      d[++tot] = i;
      if (n / i != i)d[++tot] = n / i;
    }
  }
  sort(d + 1, d + 1 + tot);
  for (i64 i = 1; i <= (tot + 1) / 2; i++) {
    p1[d[i]] = i;
    p2[d[i]] = tot - i + 1;
  }
  for (i64 i = 1; i <= tot; i++) {
    if (i == 1)dp[i][1] = 1;
    else dp[i][1] = 0;
    for (i64 j = 2; j <= tot; j++) {
      dp[i][j] = (dp[i][j - 1]);
      if (d[i] % d[j] == 0) {
        i64 tmp = d[i] / d[j];
        i64 pos = (tmp <= sq ? p1[tmp] : p2[n / tmp]);
        dp[i][j] = (dp[i][j] % mod + dp[pos][j - 1]) % mod;
      }
    }
  }
  cout << dp[tot][tot] - 1 << "\n";
}
signed main() {
  i64 T; cin >> T;
  while (T--)
    solve();
}