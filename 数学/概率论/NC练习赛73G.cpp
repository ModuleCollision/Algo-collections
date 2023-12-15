/*300兆字节 1- 2 秒*/

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

i64 f[maxn];
void solve() {
    auto chart = [&](i64 x) {
        vector<i64>s(x + 5);
        for (i64 i = 1; i <= x; i++)s[i] = i;
        i64 cnt = 0;
        do {
            vector<i64>w(x + 5);
            for (i64 i = 1; i <= x; i++)w[i] = s[i];
            while (1) {
                bool f = 1;
                for (i64 i = 1; i <= x - 1; i++) {
                    if (w[i] > w[i + 1]) {
                        f = 0; break;
                    }
                }
                if (f)break;
                cnt++;
                i64 idx = 0, val = 0; i64 cur = 0;
                for (i64 i = x; i >= 1; i--) {
                    if (w[i] != i) {
                        if (w[i] > cur) {
                            cur = w[i]; val = w[i], idx = i;
                        }
                    }
                }
                for (i64 i = idx; i <= val - 1; i++)swap(w[i], w[i + 1]);
            }
        } while (next_permutation(s.begin() + 1, s.begin() + 1 + x));
        cout << cnt << endl;
    };
    auto inv = [&](i64 x) {
        i64 ret = 1; i64 y = mod - 2;
        while (y) {
            if (y & 1)ret = ret * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ret % mod;
    };
    f[1] = 0;
    for (i64 i = 2; i <= 1e6; i++) {
        f[i] = (f[i - 1] % mod + (i - 1) % mod * inv(i)) % mod;
    }
    i64 t; std::cin >> t;
    while (t--) {
        i64 n; cin >> n; cout << f[n] << endl;
    }
}
signed main() {
    solve();
}