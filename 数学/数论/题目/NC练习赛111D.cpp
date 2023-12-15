/*求解 ax + by = c的最小正整数解*/
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

constexpr i64 mod = 1145141;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


void solve() {
    i64 a, b, n, l, r;
    i64 x, y;
    function<i64(i64, i64, i64&, i64&)>exgcd = [&] (i64 a, i64 b, i64 & x, i64 & y) {
        if (b == 0) {
            x = 1; y = 0;
            return a;
        }
        i64 d = exgcd(b, a % b, x, y);
        i64 temp = x; x = y;
        y = temp - a / b * y;
        return d;
    };
    std::cin >> a >> b >> n >> l >> r;
    i64 d = exgcd(a, b, x, y);
    if (n % d) {
        puts("NO"); return;
    }
    b /= d;
    i64 x0 = (x * n / d % b + b) % b;
    if (x0 >= l) {
        if (x0 <= r) {
            puts("YES"); return;
        } else {
            puts("NO"); return;
        }
    } else {
        x0 = (l - x0 + b - 1) / b * b + x0;
        if (x0 <= r) {
            puts("YES"); return;
        } else {
            puts("NO"); return;
        }
    }
    puts("NO"); return;
}
signed main() {
    i64 T; std::cin >> T;
    while (T--)solve();
}