#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll sz[maxn], dfn[maxn], son[maxn], dep[maxn];
ll L[maxn], R[maxn]; ll cnt = 0; ll wdep[maxn];//维护最大可达深度
ll mx[maxn];//维护某一层的节点最大值
void solve() {
    ll n; std::cin >> n;
    vector<ll>A(n + 1, 0);
    for (ll i = 1; i <= n; i++)cin >> A[i];
    vector<vector<ll>>tr(n + 1);
    for (ll i = 1; i <= n - 1; i++) {
        ll u, v; std::cin >> u >> v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    ll m; cin >> m; vector<vector<pair<ll, ll>>>q(n + 1);
    for (ll i = 1; i <= m; i++) {
        ll t, x; cin >> t >> x; q[x].push_back({t, i});
    }
    vector<ll>ans(m + 1);
    function<void(ll, ll)>dfs1 = [&](ll u, ll f) {
        L[u] = ++cnt; sz[u] = 1; dfn[cnt] = u;
        dep[u] = dep[f] + 1; wdep[u] = dep[u];
        for (auto v : tr[u]) {
            if (v == f)continue;
            dfs1(v, u); sz[u] += sz[v];
            wdep[u] = max(wdep[u], wdep[v]);
            if (son[u] == 0 or sz[son[u]] < sz[v])son[u] = v;
        }
        R[u] = cnt;
    };
    auto add = [&](ll u) {
        mx[dep[u]] = max(mx[dep[u]], A[u]);
    };
    function<void(ll, ll, bool)>dfs2 = [&](ll u, ll f, bool flag) {
        for (auto v : tr[u]) {
            if (v == f or v == son[u])continue;
            dfs2(v, u, false);
        }
        if (son[u])dfs2(son[u], u, true);
        for (auto v : tr[u]) {
            if (v == f or v == son[u])continue;
            for (ll i = L[v]; i <= R[v]; i++) {
                add(dfn[i]);
            }
        }
        add(u);
        for (ll i = dep[u] + 1; i <= wdep[u]; i++)mx[i] = max(mx[i], mx[i - 1]);
        for (auto [t, idx] : q[u]) {
            ans[idx] = mx[min(dep[u] + t, wdep[u])];
        }
        if (flag)return;
        for (ll i = dep[u]; i <= wdep[u]; i++)mx[i] = 0;
    };
    dfs1(1, 0); dfs2(1, 0, 0);
    for (ll i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
    return;
}
signed main() {
    solve();
}