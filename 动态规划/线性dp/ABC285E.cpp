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
        cin >> A[i]; A[i] += A[i - 1];
    }
    auto get = [&](i64 len) {
        i64 ret = 2 * A[len / 2];
        if (len & 1)ret += A[(len / 2) + 1] - A[len / 2];
        return ret;
    };
    vector<i64>dp(n + 5, 0);
    for (i64 i = 2; i <= n + 1; i++) {
        for (i64 j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + get(i - j - 1));
        }
    }
    cout << dp[n + 1] << endl;
}
signed main() {
    solve();
}