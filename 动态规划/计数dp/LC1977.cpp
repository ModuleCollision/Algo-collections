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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

class Solution {
public:
    int numberOfCombinations(string num) {
        i64 n = num.size();
        num = " " + num;
        std::vector dp(n + 1, std::vector<i64>(n + 1, 0));
        dp[0][0] = 1;
        std::vector lcp(n + 2, std::vector<i64>(n + 2, 0));
        for (i64 i = n; i >= 1; i--) {
            for (i64 j = i + 1; j <= n; j++) {
                if (num[i] < num[j]) {
                    lcp[i][j] = n - j + 1;
                } else if (num[i] == num[j]) {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }
        for (i64 i = 1; i <= n; i++) {
            dp[0][i] = (dp[0][i] % mod + dp[0][i - 1]) % mod;
        }
        for (i64 i = 1; i <= n; i++) {
            for (i64 j = 1; j <= i; j++) {
                if (num[i - j + 1] == '0') {
                    continue;
                }
                if (i - 2 * j + 1 <= 0 or lcp[i - 2 * j + 1][i - j + 1] >= j) {
                    dp[i][j] = (dp[i][j] % mod + dp[i - j][j]) % mod;
                } else {
                    dp[i][j] = (dp[i][j] % mod + dp[i - j][j - 1]) % mod;
                }
            }
            for (i64 j = 1; j <= n; j++) {
                dp[i][j] = (dp[i][j] % mod + dp[i][j - 1]) % mod;
            }
        }
        return (int)(dp[n][n] % mod);
    }
};