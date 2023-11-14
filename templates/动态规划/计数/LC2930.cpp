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
  int stringCount(int n) {
    i64 dp[n + 1][3][2][2];
    memset(dp, 0 , sizeof(dp));
    dp[0][0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= 2; j++) { // e的数量
        for (int k = 0; k <= 1; k++) { // l的数量
          for (int w = 0; w <= 1; w++) { // t的数量
            for (i8 s = 'a'; s <= 'z'; s++) {
              if (s == 'e') {
                dp[i][min(2, j + 1)][k][w] = (dp[i][min(2, j + 1)][k][w] % mod + dp[i - 1][j][k][w]) % mod;
              } else if (s == 'l') {
                dp[i][j][min(1, k + 1)][w] = (dp[i][j][min(1, k + 1)][w] % mod + dp[i - 1][j][k][w]) % mod;
              } else if (s == 't') {
                dp[i][j][k][min(1, w + 1)] = (dp[i][j][k][min(1, w + 1)] % mod + dp[i - 1][j][k][w]) % mod;
              } else {
                dp[i][j][k][w] = (dp[i][j][k][w] % mod + dp[i - 1][j][k][w]) % mod;
              }
            }
          }
        }
      }
    }
    i64 ans = 0;
    ans = (ans % mod + dp[n][2][1][1]) % mod;
    return ans % mod;
  }
};