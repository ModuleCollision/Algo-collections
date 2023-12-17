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
    vector<i64>A(n + 1, 0);
    for (i64 i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (i64 i = 1; i <= n; i++) {
        A[i] ^= A[i - 1];
    }
    if (A[n] != 0) { //0 A[n] 0 A[n]
        vector dp(n + 1, vector<i64>(2, 0));
        dp[0][0] = 1;
        vector<i64>pre(2, 0);
        pre[0] = 1;
        for (i64 i = 1; i <= n; i++) {
            if (A[i] == 0) {
                dp[i][0] = (dp[i][0] % mod + pre[1]) % mod;
                pre[0] = (pre[0] % mod + dp[i][0]) % mod;
            } else if (A[i] == A[n]) {
                dp[i][1] = (dp[i][1] % mod + pre[0]) % mod;
                pre[1] = (pre[1] % mod + dp[i][1]) % mod;
            }
        }
        cout << dp[n][1] % mod << endl;
    } else {
        auto ksm = [&](i64 x, i64 y) {
            i64 ret = 1;
            while (y) {
                if (y & 1)ret = ret * x % mod;
                x = x * x % mod;
                y >>= 1;
            }
            return ret % mod;
        }; i64 ans = 0;
        i64 cnt = 0;
        for (i64 i = 0; i <= n; i++)if (A[i] == 0)cnt++;
        ans = (ans % mod + ksm(2, cnt - 2)) % mod;
        vector<i64>pre(n + 1);
        std::unordered_map<i64, i64>pos;
        vector dp(n + 1, 0);
        for (i64 i = 1; i <= n; i++) {
            pre[i] += pre[i - 1];
            pre[i] += (A[i] == 0);
        }
        std::unordered_map<i64, i64>w[2];//维护某数下0 1 结尾的dp总数
        for (i64 i = 1; i <= n; i++) {
            if (A[i]) {
                if (pos[A[i]] == 0) {
                    i64 d = pre[i - 1] + 1;
                    dp[i] = (dp[i] % mod + 1) % mod;
                    w[0][A[i]] = (w[0][A[i]] % mod + 1) % mod;
                    w[1][A[i]] = (w[1][A[i]] % mod + dp[i]) % mod;
                } else {
                    i64 d = pre[i] - pre[pos[A[i]]];
                    w[0][A[i]] = (w[0][A[i]] % mod + d * w[1][A[i]]) % mod;
                    dp[i] = (dp[i] % mod + w[0][A[i]]) % mod;
                    w[1][A[i]] = (w[1][A[i]] % mod + dp[i]) % mod;
                }
                pos[A[i]] = i;
            }
        }
        //延迟计算dp
        for (i64 i = 1; i <= n; i++)if (A[i])ans = (ans % mod + dp[i]) % mod;
        cout << ans % mod << endl;
    }
}
signed main() {
    solve();
}