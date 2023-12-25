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

constexpr i64 mod = 1e5 + 3;
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


int main() {
    i64 n, m; std::cin >> n >> m;
    std::vector<std::vector<i64>>e(n + 1);
    std::map<std::pair<i64, i64>, i64>cnt;
    for (i64 i = 1; i <= m; i++) {
        i64 x, y; std::cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    std::vector<i64>ans(n + 1);
    std::vector<bool>vis(n + 1, false);
    std::vector<i64>dis(n + 1, inf);
    vis[1] = true;
    dis[1] = 0; queue<i64>q; q.push(1);
    ans[1] = 1;
    while (q.size()) {
        auto u = q.front(); q.pop();
        for (auto v : e[u]) {
            if (not vis[v]) {
                vis[v] = 1;
                dis[v] = dis[u] + 1; q.push(v);
                ans[v] = (ans[v] % mod + ans[u]) % mod;
            } else if (dis[v] == dis[u] + 1) {
                ans[v] = (ans[v] % mod + ans[u]) % mod;
            }
        }
    }
    for (i64 i = 1; i <= n; i++) {
        std::cout << ans[i] % mod << "\n";
    }
    return 0;
}