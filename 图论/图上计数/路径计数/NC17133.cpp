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
i64 fac[maxn], invfac[maxn], inv[maxn];
void pre() {
    fac[0] = fac[1] = 1;
    invfac[0] = invfac[1] = 1;
    inv[1] = 1;
    for (i64 i = 2; i <= 2e3; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        invfac[i] = invfac[i - 1] * inv[i] % mod;
    }
}
i64 C(i64 n, i64 m) {
    return fac[n] % mod * invfac[n - m] % mod * invfac[m] % mod;
}
signed main() {
    pre();
    i64 n, m;
    while (std::cin >> n >> m) {
        i64 ans;
        ans = (C(n + m, n) % mod * C(n + m, n) % mod - C(n + m, n - 1) % mod * C(n + m, n + 1) % mod + mod) % mod;
        cout << ans << endl;
    }
}