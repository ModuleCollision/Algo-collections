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
  i64 n, m, k; cin >> n >> m >> k;
  string A, B; cin >> A >> B;
  A = ' ' + A, B = ' ' + B;
  vector dp(m + 1, vector<i64>(k + 1, 0));
  vector pre(n + 1, vector(m + 1, vector<i64>(k + 1, 0)));
  int lcp[n + 1][m + 1];
  memset(lcp, 0, sizeof(lcp));
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = 1; j <= m; j++) {
      if (A[i] == B[j]) {
        lcp[i][j] = lcp[i - 1][j - 1] + 1;
      } else {
        lcp[i][j] = 0;
      }
    }
  }
  // 滚动数组优化一维
  dp[0][0] = 1;
  pre[0][0][0] = 1;// 0 --- i 0 -- j s位的前缀和
  for (i64 i = 1; i <= n; i++) {
    vector ndp(m + 1, vector<i64>(k + 1, 0));
    for (i64 j = 0; j <= m; j++) {
      for (i64 s = 0; s <= k; s++) {
        if (lcp[i][j] and s >= 1) {
          ndp[j][s] = (ndp[j][s] % mod + pre[i - 1][j - 1][s - 1]) % mod;
          if (i - lcp[i][j] >= 1 and j - lcp[i][j] >= 1) {
            ndp[j][s] = ((ndp[j][s] - pre[i - lcp[i][j] - 1][j - lcp[i][j] - 1][s - 1]) % mod + mod) % mod;
          }
        }
        ndp[j][s] = (ndp[j][s] % mod + dp[j][s]) % mod;
        pre[i][j][s] = (((i >= 1 and j >= 1) ? pre[i - 1][j - 1][s] : 0ll) % mod + ndp[j][s]) % mod;
      }
    }
    dp = ndp;
  }
  cout << dp[m][k] << "\n";
}
signed main() {
  solve();
}