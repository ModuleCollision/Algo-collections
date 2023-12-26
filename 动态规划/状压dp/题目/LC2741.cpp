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

class Solution {
public:
  int specialPerm(vector<int>& nums) {
    int n = nums.size();
    vector dp((1 << n) + 5, vector<i64>(n + 1, 0));
    for (int  i = 0; i < n; i++)dp[(1 << i)][i] = 1;
    for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1) {
          int w = i - (1 << j);
          for (int k = 0; k < n; k++) {
            if (nums[k] % nums[j] == 0 or nums[j] % nums[k] == 0) {
              dp[i][j] = (dp[i][j] + dp[w][k]) % mod;
            }
          }
        }
      }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
      res = (res % mod + dp[(1 << n) - 1][i]) % mod;
    }
    return res;
  }
};