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
const i64 mod = 1e9 + 7;
const i64 maxn = 20050;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 d[maxn], n, m, sum, q[maxn], rt, sz[maxn], mx[maxn]; bool tf[10000010];
bool ans[maxn], vis[maxn]; i64 dis[maxn];
vector<pair<i64, i64>>tr[maxn];
queue<i64>tag; i64 cnt = 0;
void solve() {
    cin >> n >> m;
    for (i64 i = 1; i < n; i++) {
        i64 u, v, w; cin >> u >> v >> w;
        tr[u].push_back({v, w});
        tr[v].push_back({u, w});
    }
    for (i64 i = 1; i <= m; i++)cin >> q[i];
    mx[rt] = inf; sum = n;
    function<void(i64, i64)>dfs1 = [&](i64 u, i64 fa) {
        sz[u] = 1; mx[u] = 0;
        for (auto [v, w] : tr[u]) {
            if (v == fa or vis[v])continue;
            dfs1(v, u);
            mx[u] = max(mx[u], sz[v]);
            sz[u] += sz[v];
        }
        mx[u] = max(mx[u], sum - mx[u]);
        if (mx[u] < mx[rt])rt = u;
    };
    function<void(i64, i64)>cal = [&](i64 u, i64 f) {
        d[++cnt] = dis[u];
        for (auto [v, w] : tr[u]) {
            if (v != f and not vis[v]) {
                dis[v] = dis[u] + w; cal(v, u);
            }
        }
    };
    function<void(i64, i64)>dfs2 = [&](i64 u, i64 fa) {
        tf[0] = true;
        tag.push(0); vis[u] = true;
        for (auto [v, w] : tr[u]) {
            if (v != fa and not vis[v]) {
                dis[v] = w;
                cal(v, u);
                for (i64 k = 1; k <= cnt; k++) {
                    for (i64 i = 1; i <= m; i++) {
                        if (q[i] >= d[k])
                            ans[i] = (ans[i] | tf[q[i] - d[k]]);
                    }
                }
                for (i64 k = 1; k <= cnt; k++) {
                    if (d[k] < 10000010)
                        tag.push(d[k]), tf[d[k]] = true;
                }
                cnt = 0;
            }
        }
        while (tag.size())tf[tag.front()] = false, tag.pop();
        for (auto [v, w] : tr[u]) {
            if (v != fa and not vis[v]) {
                sum = sz[v];
                rt = 0;
                mx[rt] = inf;
                dfs1(v, u);
                dfs1(rt, -1);
                dfs2(rt, u);
            }
        }
    };
    dfs1(1, -1); dfs1(rt, -1);
    dfs2(rt, -1);
    for (i64 i = 1; i <= m; i++) {
        if (ans[i]) {
            puts("AYE");
        } else {
            puts("NAY");
        }
    }
}
int main() {
    solve();
    return 0;
}