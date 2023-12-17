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
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size(); int m = grid[0].size();
        int dp[n + 5][m + 5][k + 5];
        memset(dp, 0, sizeof(dp));
        dp[1][1][grid[0][0] % k] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1 and j == 1)continue;
                for (int s = 0; s < k; s++) {
                    dp[i][j][(s + grid[i - 1][j - 1]) % k] = (dp[i][j][(s + grid[i - 1][j - 1]) % k] % mod + dp[i - 1][j][s]) % mod;
                    dp[i][j][(s + grid[i - 1][j - 1]) % k] = (dp[i][j][(s + grid[i - 1][j - 1]) % k] % mod + dp[i][j - 1][s]) % mod;
                }
            }
        }
        int ans = 0;
        ans = dp[n][m][0] % mod;
        return (int)ans;
    }
};