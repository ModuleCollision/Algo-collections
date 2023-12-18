/*LGV定理,矩阵计数路径数*/
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
constexpr i64 maxn = 3e3 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 dp[maxn][maxn], n, m;
char G[maxn][maxn];
i64 f(i64 sx, i64 sy, i64 tx, i64 ty) {
    memset(dp, -1, sizeof(dp));
    dp[sx][sy] = (G[sx][sy] == '.');
    function<void(i64, i64)> dfs = [&](i64 x, i64 y) {
        if (!(x >= sx and x <= tx and y >= sy and y <= ty)) {
            dp[x][y] = 0;
            return;
        }
        if (dp[x][y] != -1) {
            return;
        }
        if (G[x][y] == '#') {
            dp[x][y] = 0;
            return;
        }
        dp[x][y] = 0;
        dfs(x - 1, y);
        dfs(x, y - 1);
        dp[x][y] = (dp[x - 1][y] + dp[x][y]) % mod;
        dp[x][y] = (dp[x][y] + dp[x][y - 1]) % mod;
    };
    dfs(tx, ty);
    return dp[tx][ty];
}
signed main() {
    std::cin >> n >> m;
    for (i64 i = 1; i <= n; i++) {
        std::cin >> (G[i] + 1);
    }
    i64 f11 = f(1, 2, n - 1, m) % mod;
    i64 f12 = f(1, 2, n, m - 1) % mod;
    i64 f21 = f(2, 1, n - 1, m) % mod;
    i64 f22 = f(2, 1, n, m - 1) % mod;
    cout << (((f11 * f22) % mod - (f12 * f21) % mod + mod) % mod) << endl;
    return 0;
}
