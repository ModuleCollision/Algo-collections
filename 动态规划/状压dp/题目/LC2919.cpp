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
        vector dp(n + 5, vector<i64>(15, inf));
        for (int j = 1; j < 8; j++) {
            dp[2][j] = 0;
            for (i64 s = 0; s < 3; s++)if ((j >> s) & 1)dp[2][j] += max(0ll, (i64)k - nums[s]);
        }
        for (int i = 3; i < n; i++) {
            for (int j = 1; j < 8; j++) {
                for (int q = 1; q < 8; q++) {
                    i64 tmp = dp[i - 1][q];
                    for (int s = 0; s < 3; s++) {
                        if ((((j >> s) & 1) == 1) and (((q >> (s + 1)) & 1) == 0)) {
                            tmp += max(0ll, k - (i64)nums[i - 2 + s]);
                        }
                    }
                    dp[i][j] = min(dp[i][j], tmp);
                }
            }
        }
        i64 ans = inf;
        for (i64 j = 1; j < 8; j++)ans = min(ans, dp[n - 1][j]);
        return ans;
    }
};