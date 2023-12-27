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
    auto check = [&](i64 x, i64 p) {
        __int128 f = n;
        f = f * (x - 1);
        __int128 mx = 1e27;
        if (f > mx)return 0;
        __int128 res = 1;
        for (i64 i = 1; i <= p; i++) {
            res = res * x; if (res > mx)return 0;
        }
        res -= 1;
        __int128 k = res;
        if (res > f)return 0;
        else if (res < f)return 1;
        else if (res == f)return 2;
    };
    for (i64 i = 3; i <= 64; i++) {
        i64 l = 2, r = 1e9;
        while (l < r) {
            i64 mid = (l + r) >> 1;
            if (check(mid, i) == 0)r = mid;
            else if (check(mid, i) == 1)l = mid + 1;
            else {
                puts("YES"); return;
            }
        }
    }
    puts("NO"); return;
}
signed main() {
    i64 T; std::cin >> T; while (T--)
        solve();
}