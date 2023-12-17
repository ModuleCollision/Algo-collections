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

i64 sz[maxn]; bool vis[maxn];
vector<i64>tr[maxn]; i64 n, m, k;
i64 dp[maxn][55];//前i份删了j个
void solve() {
    //memset(dp, 0x3f, sizeof(dp));
    std::cin >> n >> m;
    for (i64 i = 1; i <= n - 1; i++) {
        i64 u, v; std::cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    std::cin >> k;
    for (i64 i = 1; i <= k; i++) {
        i64 b; std::cin >> b;
        vis[b] = 1;
    }
    function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
        if (vis[u])sz[u] = 1;
        for (auto v : tr[u]) {
            if (v == f)continue;
            dfs(v, u);
            vector<i64>tmp(m + 5, inf);
            for (i64 i = 0; i <= min(m, sz[u]); i++) {
                for (i64 j = 0; j <= min(sz[v], m - i); j++) {
                    i64 w = 1;
                    if (j == sz[v])w = 0;
                    tmp[i + j] = min(tmp[i + j], dp[u][i] + dp[v][j] + w * 2);
                }
            }
            for (i64 i = 0; i <= m; i++) {
                dp[u][i] = tmp[i];
            }
            sz[u] += sz[v];
        }
    };
    dfs(1, 1);
    cout << dp[1][m] << endl;
}
signed main() {
    solve();
}