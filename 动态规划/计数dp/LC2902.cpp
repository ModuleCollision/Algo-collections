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

  int countSubMultisets(vector<int>& nums, int l, int r) {
    int n = nums.size(); i64 tot = accumulate(nums.begin(), nums.end(), 0ll);
    vector<i64>dp(tot + 5, 0);
    std::unordered_map<i64, i64>cnt;
    for (auto x : nums)cnt[x]++;
    dp[0] = cnt[0] + 1;/*多重背包问题求方案数*/
    cnt.erase(0);
    for (auto [x, y] : cnt) {
      for (i64 j = tot; j >= 0; j--) {
        for (int k = 1; k <= y and k * x <= j; k++) {
          dp[j] = (dp[j] % mod + dp[j - k * x]) % mod;
        }
      }
    }
    i64 ans = 0;
    for (int i = l; i <= r; i++) {
      ans = (ans % mod + dp[i]) % mod;
    }
    return ans % mod;
  }
};


/*多重背包O(1)优化*/
class Solution {
public:
  int countSubMultisets(vector<int>& nums, int l, int r) {
    int n = nums.size(); i64 tot = accumulate(nums.begin(), nums.end(), 0ll);
    vector<i64>dp(tot + 5, 0);
    std::unordered_map<i64, i64>cnt;
    for (auto x : nums)cnt[x]++;
    dp[0] = cnt[0] + 1;/*多重背包问题求方案数*/
    cnt.erase(0); r = min(r, (int)tot); i64 sum = 0;
    for (auto [x, y] : cnt) {
      auto ndp = dp;
      sum = min(sum + x * y, (i64)r);
      for (i64 j = x; j <= sum; j++) {
        ndp[j] = (ndp[j] + ndp[j - x]) % mod;
        if (j >= (y + 1)*x) {
          ndp[j] = ((ndp[j] - dp[j - (y + 1) * x]) % mod + mod) % mod;
        }
      }
      dp = ndp;
    }
    i64 ans = 0;
    for (int i = l; i <= r; i++) {
      ans = (ans % mod + dp[i]) % mod;
    }
    return ans % mod;
  }
};