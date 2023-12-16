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

i64 n, m; i64 d[maxn][maxn];
void solve() {
    cin >> n >> m; vector<array<i64, 3>>e(m + 1);
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++) {
            if (i == j)continue;
            d[i][j] = d[j][i] = inf;
        }
    }
    for (i64 i = 1; i <= m; i++) {
        i64 u, v, w; cin >> u >> v >> w;
        e[i] = {u, v, w};
        d[u][v] = d[v][u] = w;
    }
    for (i64 k = 1; k <= n; k++) {
        for (i64 i = 1; i <= n; i++) {
            for (i64 j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    i64 ans = 0;
    for (i64 i = 1; i <= m; i++) {
        auto [u, v, w] = e[i]; bool f = false;
        for (i64 j = 1; j <= n; j++) {
            f |= (w + d[u][j] == d[v][j]);
            f |= (w + d[v][j] == d[u][j]);
        }
        if (not f)ans++;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}