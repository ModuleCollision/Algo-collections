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
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 2e4 + 5;


class Solution {
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int m = log2(n);
        vector fa(n + 1, vector<int>(m + 1, 0));
        vector dis(n + 1, vector<array<int, 27>>(m + 1));
        vector<int>dep(n + 1, 0);
        vector<vector<pair<int, int>>>tr(n + 1);
        function<void(int, int)> dfs = [&](int u, int f) {
            fa[u][0] = f;
            dep[u] = dep[fa[u][0]] + 1;
            for (int i = 1; (1 << i) <= dep[u]; i++) {
                fa[u][i] = fa[fa[u][i - 1]][i - 1];
                for (int j = 1; j <= 26; j++) {
                    dis[u][i][j] = dis[u][i - 1][j] + dis[fa[u][i - 1]][i - 1][j];
                }
            }
            for (auto [x, y] : tr[u]) {
                if (x == f)continue;
                dis[x][0][y] = 1;
                dfs(x, u);
            }
        };
        int q = queries.size();
        vector<int>ans(q);
        for (auto k : edges) {
            int u = k[0], v = k[1], w = k[2];
            tr[u + 1].push_back({v + 1, w});
            tr[v + 1].push_back({u + 1, w});
        }
        dfs(1, 0);
        int tot = 0;
        auto lca = [&](int u, int v) {
            tot = 0; int cnt[27] = {0};
            for (int i = 1; i <= 26; i ++ )cnt[i] = 0;
            if (dep[u] < dep[v])swap(u, v);
            if (dep[u] != dep[v]) {
                for (int i = log2(dep[u] - dep[v]); i >= 0; i--) {
                    if (dep[fa[u][i]] >= dep[v]) {
                        for (int j = 1; j <= 26; j++) {
                            tot += dis[u][i][j], cnt[j] += dis[u][i][j];
                        }
                        u = fa[u][i];
                    }
                }
            }
            if (u == v)return tot - *max_element(cnt + 1, cnt + 1 + 26);
            for (int i = log2(dep[u]); i >= 0; i--) {
                if (fa[u][i] != fa[v][i]) {
                    for (int j = 1; j <= 26; j++) {
                        tot += dis[u][i][j]; tot += dis[v][i][j];
                        cnt[j] += dis[u][i][j]; cnt[j] += dis[v][i][j];
                    }
                    u = fa[u][i]; v = fa[v][i];
                }
            }
            if (u != v) {
                for (int j = 1; j <= 26; j++) {
                    cnt[j] += dis[u][0][j];
                    cnt[j] += dis[v][0][j];
                    tot += dis[u][0][j];
                    tot += dis[v][0][j];
                }
            }
            return tot - *max_element(cnt + 1, cnt + 1 + 26);
        };
        for (int i = 0; i < q; i++) {
            int u = queries[i][0], v = queries[i][1];
            u ++ ; v ++;
            ans[i] = lca(u, v);

        }
        return ans;
    }
};