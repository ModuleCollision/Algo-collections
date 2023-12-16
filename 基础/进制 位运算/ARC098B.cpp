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
    vector<i64>A(n + 1, 0); for (i64 i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector pre(n + 1, vector<i64>(33, 0));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 30; j >= 0; j--)pre[i][j] += pre[i - 1][j];
        for (i64 j = 30; j >= 0; j--) {
            if ((A[i] >> j) & 1)pre[i][j] += 1;
        }
    }
    vector<i64>cur(33, 0); i64 ans = 0;
    for (i64 r = 1, l = 1; r <= n; r++) {
        for (i64 j = 0; j <= 30; j++) {
            if ((A[r] >> j) & 1)cur[j]++;
        }
        for (i64 j = 0; j <= 30; j++) {
            if (cur[j] > 1) {
                while (cur[j] > 1) {
                    for (i64 j = 0; j <= 30; j++)if ((A[l] >> j) & 1)cur[j]--;
                    l++;
                }
            }
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}