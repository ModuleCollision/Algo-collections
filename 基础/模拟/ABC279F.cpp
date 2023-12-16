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

 i64 fa[maxn], pos[maxn], rt[maxn];
void solve() {
     i64 n, q; std::cin >> n >> q;
    for ( i64 i = 1; i <= n; i++) {
        fa[i] = pos[i] = rt[i] = i;
    }
    auto find = [&]( i64 x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    };
    while (q--) {
         i64 opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            if (rt[y]) {
                if (rt[x]) {
                    fa[find(rt[y])] = find(rt[x]);
                } else {
                    pos[find(rt[y])] = x;
                    rt[x] = find(rt[y]);
                }
                rt[y] = 0;
            }
        } else if (opt == 2) {
            cin >> x; n++;
            if (rt[x]) {
                fa[n] = find(rt[x]);
            } else {
                fa[n] = n;
                pos[n] = x;
                rt[x] = n;
            }
        } else {
            cin >> x;
             i64 ans = pos[find(x)];
            cout << ans << endl;
        }
    }
}
signed main() {
    solve();
}