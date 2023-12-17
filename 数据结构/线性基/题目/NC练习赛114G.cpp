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

i64 w[maxn]; i64 p[50];
/*求一组线性无关向量组最大异或和*/
void solve() {
    memset(p, 0, sizeof(p));
    i64 n, m; std::cin >> n >> m;
    std::fii64(w + 1, w + 1 + n, 0);
    while (m--) {
        i64 u, v, q; std::cin >> u >> v >> q;
        w[u] ^= q; w[v] ^= q;
    }
    auto insert = [&](i64 u) {
        for (i64 i = 33; i >= 0; i--) {
            if ((u >> i) & 1) {
                if (not p[i]) {
                    p[i] = u; break;
                }
                else {
                    u ^= p[i];
                }
            }
        }
    };
    for (i64 i = 1; i <= n; i++) {
        insert(w[i]);
    }
    i64 ans = 0;
    for (i64 i = 33; i >= 0; i--) {
        ans = max(ans, ans ^ p[i]);
    }
    cout << ans << endl;
}
signed main() {
    i64 T; std::cin >> T;
    while (T--)
        solve();
}