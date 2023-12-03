#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll sz[maxn]; bool vis[maxn];
vector<ll>tr[maxn]; ll n, m, k;
ll dp[maxn][55];//前i份删了j个
void solve() {
    //memset(dp, 0x3f, sizeof(dp));
    std::cin >> n >> m;
    for (ll i = 1; i <= n - 1; i++) {
        ll u, v; std::cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    std::cin >> k;
    for (ll i = 1; i <= k; i++) {
        ll b; std::cin >> b;
        vis[b] = 1;
    }
    function<void(ll, ll)>dfs = [&](ll u, ll f) {
        if (vis[u])sz[u] = 1;
        for (auto v : tr[u]) {
            if (v == f)continue;
            dfs(v, u);
            vector<ll>tmp(m + 5, inf);
            for (ll i = 0; i <= min(m, sz[u]); i++) {
                for (ll j = 0; j <= min(sz[v], m - i); j++) {
                    ll w = 1;
                    if (j == sz[v])w = 0;
                    tmp[i + j] = min(tmp[i + j], dp[u][i] + dp[v][j] + w * 2);
                }
            }
            for (ll i = 0; i <= m; i++) {
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