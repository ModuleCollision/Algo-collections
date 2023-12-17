
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
  long long appealSum(string s) {
    int n = s.size(); s = " " + s;
    vector<int>pre(n + 1, 0), pos(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      pre[i] = pos[s[i] - 'a'];
      pos[s[i] - 'a'] = i;
    }
    vector<i64>dp(n + 1, 0);
    for (i64 i = 1; i <= n; i++) {
      dp[i] += dp[i - 1] + i - pre[i];
    }
    return accumulate(dp.begin(), dp.end(), 0ll);
  }
};