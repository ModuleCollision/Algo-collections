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
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


std::vector<std::pair<i64, i64>>e[maxn];

f64 dp[maxn];

bool vis[maxn + 1];
int main() {
    i64 n, m; std::cin >> n >> m;

    for (i64 i = 1; i <= m; i++) {
        i64 u, v, w; std::cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    std::function<void(i64)>dfs = [&](i64 u) {
        if (vis[u])return ; vis[u] = 1;
        f64 k = e[u].size();
        for (auto [v, w] : e[u]) {
            dfs(v);
            dp[u] += (f64)(dp[v] + (f64)w) * 1 / k;
        }
    };
    dfs(1);
    printf("%.2lf\n", dp[1]);
}