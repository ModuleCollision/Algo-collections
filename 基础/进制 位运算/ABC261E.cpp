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
    i64 n, c; std::cin >> n >> c;
    vector<pair<i64, i64>>op(n + 1);
    for (i64 i = 1; i <= n; i++) {
        cin >> op[i].fi >> op[i].se;
    }
    vector<i64>ans(n + 1);
    for (i64 k = 0; k < 30; k++) {
        array<i64, 2>func = {0, 1};
        i64 cur = (c >> k) & 1;
        for (i64 i = 1; i <= n; i++) {
            array<i64, 2>f;
            auto [t, a] = op[i];
            i64 x = (a >> k) & 1;
            if (t == 1)f = {0 & x, 1 & x};
            else if (t == 2)f = {0 | x, 1 | x};
            else f = {0 ^ x, 1 ^ x};
            func = {f[func[0]], f[func[1]]};
            cur = func[cur];
            ans[i] |= (cur << k);
        }
    }
    for (i64 i = 1; i <= n; i++)cout << ans[i] << endl;
}
signed main() {
    solve();
}