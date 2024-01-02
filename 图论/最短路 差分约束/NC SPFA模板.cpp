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
using namespace std;

constexpr i64 mod = 1e5 + 3;
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
/*Bellman - ford算法*/

/*spfa优化*/

int main() {
    i64 n, m; std::cin >> n >> m;
    std::vector<std::vector<pair<i64, i64>>>g(n + 1);
    for (i64 i = 1; i <= m; i++) {
        i64 u, v, w; std::cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    std::vector<i64>dis(n + 1, inf);
    std::vector<bool>vis(n + 1, false);
    dis[1] = 0, vis[1] = 1;
    std::vector<i64>cnt(n + 1);
    queue<i64>q; q.push(1);
    while (q.size()) {
        i64 u = q.front(); q.pop();
        vis[u] = 0;
        for (auto [v, w] : g[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n)return 0;
                if (not vis[v]) {
                    q.push(v), vis[v] = 1;
                }
            }
        }
    }
    for (i64 i = 2; i <= n; i++) {
        std::cout << dis[i] << "\n";

    }
}