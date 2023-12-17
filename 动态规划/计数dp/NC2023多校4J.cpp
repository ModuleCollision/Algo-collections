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

//前缀优化dp
void solve() {
    i64 n, m; std::cin >> n >> m;
    vector dp(n + 5, vector<i64>(2 * m + 5, 0));
    i64 off = m + 1;
    for (i64 i = -m; i <= m; i++) {
        dp[1][i + off] = 1;
    }
    vector<i64>pre(2 * m + 5);
    for (i64 i = -m; i <= m; i++) {
        pre[i + off] = (pre[i - 1 + off] % mod + dp[1][i + off]) % mod;
    }
    for (i64 i = 2; i <= n; i++) {
        for (i64 j = -m; j <= m; j++) {
            if (j >= 0) {
                dp[i][j + off] = ((pre[m + off] - pre[j - m - 1 + off]) % mod + mod) % mod;
            } else if (j < 0) {
                i64 v = ((pre[m + off] - pre[-j - 1 + off]) % mod + mod) % mod;
                dp[i][j + off] = (dp[i][j + off] % mod + v) % mod;
            }
        }
        for (i64 j = -m; j <= m; j++) {
            pre[j + off] = (pre[j + off - 1] % mod + dp[i][j + off]) % mod;
        }
    }
    i64 ans = 0;
    for (i64 i = -m; i <= m; i++) {
        ans = (ans % mod + dp[n][i + off]) % mod;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}