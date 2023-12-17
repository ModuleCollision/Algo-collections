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
  long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) {
    std::sort(robot.begin(), robot.end());
    std::sort(factory.begin(), factory.end());
    int n = factory.size(); int m = robot.size();
    vector dp(n + 5, vector<i64>(m + 5, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= m; j++) {
        i64 cost = 0;
        for (int k = 0; k <= min(j, factory[i - 1][1]); k++) {
          
          dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + cost);
          if(j > k)
          cost += abs(robot[j - k - 1] - factory[i - 1][0]);
        }
      }
    }
    return dp[n][m];
  }
};