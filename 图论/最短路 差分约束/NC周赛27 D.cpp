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


std::vector<std::pair<i64, i64>>dir = {{1, 0}, { -1, 0}, {0, 1}, {0, -1}};



struct cmp {
    bool operator()(const std::array<i64, 3>&x, const std::array<i64, 3>&y) {
        return x[0] > y[0];
    }
};
int main() {
    int n, m; std::cin >> n >> m;
    std::vector a(n + 1, std::vector<i64>(m + 1, 0));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= m; j++) {
            std::cin >> a[i][j];
        }
    }
    std::priority_queue<std::array<i64, 3>, std::vector<std::array<i64, 3>>, cmp>q;
    std::vector dis(n + 1, std::vector<i64>(m + 1, inf));
    dis[1][1] = 0;
    std::vector vis(n + 1, std::vector<bool>(m + 1, false));
    q.push({{0, 1, 1}});
    auto cal = [&](i64 x, i64 y) {
        return (x ^ y) ? 2 : 1;
    };
    auto check = [&](i64 x, i64 y) {
        return x >= 1 and x <= n and y >= 1 and y <= m;
    };
    while (q.size()) {
        auto [d, x, y] = q.top();
        vis[x][y] = true;
        q.pop(); for (auto [dx, dy] : dir) {
            i64 xx = x + dx, yy = y + dy;
            if (not check(xx, yy))continue;
            if (dis[xx][yy] > dis[x][y] + cal(a[x][y], a[xx][yy])) {
                dis[xx][yy] = dis[x][y] + cal(a[x][y], a[xx][yy]);
                if (not vis[xx][yy]) {
                    q.push({dis[xx][yy], xx, yy});
                }
            }
        }
    }
    std::cout << dis[n][m] << "\n";
    return 0;
}