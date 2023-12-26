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
    int squareFreeSubsets(vector<int>& nums) {
        vector<i64>primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        const i64 maxn = 10;
        auto check = [&](int x) {
            for (int i = 0; i < 10; i++) {
                if (x % (primes[i]*primes[i]) == 0)return false;
            }
            return true;
        };
        i64 n = nums.size(); vector dp(n + 5, vector<i64>(1 << 12, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < (1 << 10); j++) {
                dp[i][j] = dp[i - 1][j] % mod;
            }
            int x = nums[i - 1];
            if (not check(x))continue;
            i64 msk = 0;
            for (int j = 0; j < 10; j++) {
                if (x % primes[j] == 0)msk |= (1 << j);
            }
            for (int j = 0; j < (1 << 10); j++) {
                if ((j & msk) == 0) {
                    dp[i][j | msk] = (dp[i][j | msk] % mod + dp[i - 1][j]) % mod;
                }
            }
        }
        i64 ans = 0;
        for (int j = 0; j < (1 << 10); j++) {
            ans = (ans % mod + dp[n][j]) % mod;
        }
        ans = ((ans - 1) % mod + mod) % mod; return ans;
    }
};