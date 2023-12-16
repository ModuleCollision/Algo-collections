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


i64 tr[maxn][2]; i64 tot = 1;
i64 l[maxn], r[maxn];
void insert(i64 x, i64 idx) {
    i64 u = 0;
    for (i64 i = 32; i >= 0; i--) {
        i64 cur = (x >> i) & 1;
        if (not tr[u][cur])tr[u][cur] = ++tot;
        u = tr[u][cur];
        if (!l[u])l[u] = idx;
        r[u] = idx;
    }
}
i64 w[maxn];
i64 query(i64 u, i64 pos, i64 x) {
    i64 ret = 0;
    for (i64 i = pos; i >= 0; i--) {
        i64 tmp = (x >> i) & 1;
        if (tr[u][tmp])u = tr[u][tmp];
        else {
            ret += (1 << i);
            u = tr[u][tmp ^ 1];
        }
    }
    return ret;
}
i64 dfs2(i64 u, i64 pos) {
    if (tr[u][0] and tr[u][1]) {
        i64 x = tr[u][0], y = tr[u][1];
        i64 mn = inf;
        if (r[x] - l[x] + 1 <= r[y] - l[y] + 1) {
            for (i64 k = l[x]; k <= r[x]; k++) {
                mn = min(mn, query(y, pos - 1, w[k]) + (1i64 << pos));
            }
        } else {
            for (i64 k = l[y]; k <= r[y]; k++) {
                mn = min(mn, query(x, pos - 1, w[k]) + (1i64 << pos));
            }
        }
        return mn + dfs2(x, pos - 1) + dfs2(y, pos - 1);
    } else if (tr[u][0]) {
        return dfs2(tr[u][0], pos - 1);
    } else if (tr[u][1]) {
        return dfs2(tr[u][1], pos - 1);
    }
    return 0;
}
void solve() {
    i64 n; std::cin >> n;
    vector<array<i64, 3>>e(n + 1);
    for (i64 i = 1; i <= n - 1; i++)std::cin >> e[i][0] >> e[i][1] >> e[i][2];
    vector<vector<pair<i64, i64>>>g(n + 1);
    for (i64 i = 1; i <= n - 1; i++) {
        auto [u, v, w] = e[i];
        u++; v++;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
        for (auto [v, q] : g[u]) {
            if (v == f)continue;
            w[v] = w[u] ^ q;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    sort(w + 1, w + 1 + n);
    for (i64 i = 1; i <= n; i++)insert(w[i], i);
    cout << dfs2(0, 32) << endl;
}
signed main() {
    solve();
}