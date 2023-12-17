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
    
    long long minIncrementOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<i64>dp(n + 1, inf);
        for (int  i = 1; i <= n; i++) {
            if (i <= 3)dp[i] = max(0i64, k - (i64)nums[i - 1]);
            else {
                dp[i] = min({dp[i - 3], dp[i - 2], dp[i - 1]}) + max(0i64, k - (i64)nums[i - 1]);
            }
        }
        return min({dp[n - 1], dp[n], dp[n - 2]});
    }
};