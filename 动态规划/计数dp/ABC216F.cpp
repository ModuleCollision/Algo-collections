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

i64 N, A[maxn], B[maxn];
pair<i64, i64>st[maxn];
i64 dp[maxn][maxn];
void solve() {
    std::cin >> N;
    for (i64 i = 1; i <= N; i++) {
        std::cin >> st[i].first;
    }
    for (i64 i = 1; i <= N; i++) {
        std::cin >> st[i].second;
    }
    std::sort(st + 1, st + 1 + N, [&](pair<i64, i64>a, pair<i64, i64>b)->bool{
        return a.first < b.first;
    });
    dp[0][0] = 1; i64 ans = 0;
    //二维0 1 背包，不限枚举次序
    for (i64 i = 1; i <= N; i++) {
        for (i64 j = 5e3 + 5; j >= 0; j--) {
            if (j >= st[i].second) {
                dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - st[i].second]) % mod;
            }
            dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
        }
        for (i64 k = st[i].second; k <= st[i].first; k++) {
            ans = (ans % mod + dp[i - 1][k - st[i].second]) % mod;
        }
    }
    cout << ans % mod << endl;
}
signed main() {
    solve();
}