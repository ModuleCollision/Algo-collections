/*多组Test尽量封装, 在函数中开对象,避免暴力清空数组造成时间浪费*/
/*STL数据结构 (cin cout function类) lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std*/
#include<bits/stdc++.h>

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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct edge {
    i64 v; bool ex; i64 rev;
};
/*欧拉通路 经过所有边恰好一次*/
void solve() {
    i64 n, m; std::cin >> n >> m;
    std::vector<i64>d(n + 1); std::vector<i64>revtop(n + 1);
    std::vector<std::vector<edge>>g(n + 1);
    for (i64 i = 1; i <= m; i++) {
        i64 u, v; std::cin >> u >> v;
        g[u].push_back({v, 1, 0}); g[v].push_back({u, 1, 0}); d[v]++; d[u]++;
    }
    for (int i = 1; i <= n; i++) {
        std::sort(g[i].begin(), g[i].end(), [&](auto s, auto t)->bool{
            return s.v < t.v;
        });
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < g[i].size(); j++) {
            g[i][j].rev = revtop[g[i][j].v]++;
        }
    }
    int from = 0;
    for (int i = 1; i <= n; i++) {
        if (not d[from] and d[i]) {
            from = i;
        }
        if ((d[from] % 2 == 0) and (d[i] & 1)) {
            from = i;
        }
    }
    std::vector<bool>vis(n + 1);
    std::function<void(i64)>dfs = [&](i64 x) {
        vis[x] = true;
        for (auto &e : g[x]) {
            if (e.ex) {
                e.ex = false;
                g[e.v][e.rev].ex = false;
                dfs(e.v);
            }
        }
    };
    dfs(from);
    for (int i = 1; i <= n; i++) {
        if (not vis[i]) {
            puts("Xun"); return;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if ((d[i] & 1))cnt++;
    }
    if (cnt == 2 or cnt == 0) {
        puts("Zhen");
    } else puts("Xun");
}

int main() {
    int T; std::cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

