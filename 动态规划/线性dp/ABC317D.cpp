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

void solve() {
    i64 n; std::cin >> n;
    vector<i64>x(n + 5, 0), y(n + 5, 0), z(n + 5, 0);
    i64 p = 0, sum = 0;
    vector<array<i64, 3>>w(n + 5); i64 tot = 0;
    for (i64 i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
        sum += z[i];
        if (x[i] > y[i])p += z[i];
        else {
            w[++tot] = {x[i], y[i], z[i]};
        }
    }
    i64 s = (sum + 1) / 2;
    if (p >= s) {
        puts("0"); return;
    }
    i64 v = s - p;
    vector dp(tot + 5, vector<i64>(sum + 5, inf));
    dp[0][0] = 0;
    for (i64 i = 1; i <= tot; i++) {
        for (i64 j = 0; j <= sum; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            i64 d = (w[i][0] + w[i][1] + 1) / 2 - w[i][0];
            if (j >= w[i][2]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - w[i][2]] + d);
            }
        }
    }
    i64 ans = inf;
    for (i64 j = v; j <= sum; j++)ans = min(ans, dp[tot][j]);
    cout << ans << endl;
}
signed main() {
    solve();
}