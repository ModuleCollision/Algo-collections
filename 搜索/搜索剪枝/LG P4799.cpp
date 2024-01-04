#include<bits/stdc++.h>
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

const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;



/*折半 + 暴搜*/
int main() {
    i64 n, m; std::cin >> n >> m;
    std::vector<i64>a(n + 1);
    for (i64 i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    if (m <= 1e6) {
        std::vector<i64>dp(m + 1, 0);
        dp[0] = 1;
        for (i64 i = 1; i <= n; i++) {
            for (i64 j = m; j >= a[i]; j--) {
                dp[j] += dp[j - a[i]];
            }
        }
        i64 ans = 0;
        for (i64 i = 0; i <= m; i++)ans += dp[i];
        std::cout << ans << "\n";
        return 0;
    }

    std::vector<i64>x(1);
    std::vector<i64>y(1);
    i64 cnt = 0;
    std::function<void(i64, i64, i64, std::vector<i64>&)>dfs = [&](i64 cur, i64 r, i64 sum, std::vector<i64>&s) {
        if (cur > r) {
            s.push_back(sum);
            return;
        }
        dfs(cur + 1, r, sum + a[cur], s);
        dfs(cur + 1, r, sum, s);
    };
    cnt = 0; dfs(1, n / 2, 0, x);
    cnt = 0;
    dfs(n / 2 + 1, n, 0, y);
    i64 ans = 0;

    std::sort(x.begin() + 1, x.end());

    std::sort(y.begin() + 1, y.end());

    i64 r = y.size() - 1;
    for (i64 l = 1; l < x.size(); l++) {
        if (x[l] > m)continue;
        while (x[l] + y[r] > m)r--;
        ans += std::max(0ll, r);
    }
    std::cout << ans << "\n";
    return 0;
}