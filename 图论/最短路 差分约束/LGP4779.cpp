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


struct cmp {
    bool operator()(const pair<i64, i64>&x, const pair<i64, i64>&y)const {
        return x.first > y.first;
    }
};


int main() {
    i64 n, m; std::cin >> n >> m;
    std::vector<i64>dis(n + 1, inf);
    i64 s; std::cin >> s;
    std::vector<std::vector<std::pair<i64, i64>>>e(n + 1);
    for (i64 i = 1; i <= m; i++) {
        i64 u, v, w; std::cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    std::priority_queue<std::pair<i64, i64>, vector<pair<i64, i64>>, cmp>q;
    q.push({0, s}); dis[s] = 0;
    std::vector<bool>vis(n + 1);
    while (q.size()) {
        auto [d, u] = q.top();
        q.pop();
        vis[u] = true;
        for (auto [v, w] : e[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                if (not vis[v]) {
                    q.push({dis[v], v});
                }
            }
        }
    }
    for (i64 i = 1; i <= n; i++) {
        std::cout << dis[i] << " \n"[i == n];
    }
    return 0;
}