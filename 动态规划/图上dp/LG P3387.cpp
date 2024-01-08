/*tarjan 缩点模板*/
/*对有向带环图的, 缩环为点, 一个点代表一个强联通分量*/
/*有向基环树用拓扑排序, 非基环树有向无环图用缩点*/
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

i64 dfn[maxn], stk[maxn], top = 0, cur = 0, low[maxn]; bool vis[maxn];
i64 scc[maxn], sc = 0;
i64 sz[maxn], in[maxn]; // 缩点后每个联通分量的大小，每个联通分量的度

int main() {
    i64 n, m; std::cin >> n >> m;
    std::vector<i64>a(n + 1);
    for (i64 i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::vector<i64>>g(n + 1);
    std::vector<pair<i64, i64>>e(m + 1);
    for (i64 i = 1; i <= m; i++) {
        i64 u, v; std::cin >> u >> v;
        e[i] = {u, v};
        g[u].push_back(v); g[v].push_back(u);
    }
    std::function<void(i64)>tarjan = [&](i64 u) {
        low[u] = dfn[u] = ++cur;
        stk[++top] = u; vis[u] = true;
        for (auto v : g[u]) {
            if (not dfn[v]) {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            } else if (vis[v]) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            ++sc;
            while (stk[top] != u) {
                scc[stk[top]] = sc;
                sz[sc] += a[stk[top]];
                vis[stk[top]] = false;
                top--;
            }
            scc[stk[top]] = sc;
            sz[sc] += a[stk[top]];
            vis[stk[top]] = false; top--;
        }
    };
    for (i64 i = 1; i <= n; i++) {
        if (not dfn[i]) {
            tarjan(i);
        }
    }
    for (i64 i = 1; i <= n; i++)g[i].clear();
    queue<i64>q; std::vector<i64>d(sc + 1, 0);
    for (i64 i = 1; i <= m; i++) {
        auto [u, v] = e[i];
        if (scc[u] == scc[v])continue;
        d[scc[v]]++;
        g[scc[u]].push_back(scc[v]);
    }
    /*拓扑 + dp*/
    std::vector<i64>dp(sc + 1);
    for (i64 i = 1; i <= sc; i++) {
        if (not d[i]) {
            q.push(i); dp[i] = sz[i];
        }
    }
    i64 ans = 0;
    while (q.size()) {
        auto u = q.front(); q.pop();
        for (auto v : g[u]) {
            d[v]--;
            if (not d[v]) {
                q.push(v); dp[v] = std::max(dp[v], dp[u] + sz[v]);
            }
        }
    }
    for (i64 i = 1; i <= sc; i++)ans = std::max(ans, dp[i]);
    std::cout << ans << "\n";
}



