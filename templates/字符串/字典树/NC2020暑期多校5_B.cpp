#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e7 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll tr[maxn][2]; ll tot = 1;
ll l[maxn], r[maxn];
void insert(ll x, ll idx) {
    ll u = 0;
    for (ll i = 32; i >= 0; i--) {
        ll cur = (x >> i) & 1;
        if (not tr[u][cur])tr[u][cur] = ++tot;
        u = tr[u][cur];
        if (!l[u])l[u] = idx;
        r[u] = idx;
    }
}
ll w[maxn];
ll query(ll u, ll pos, ll x) {
    ll ret = 0;
    for (ll i = pos; i >= 0; i--) {
        ll tmp = (x >> i) & 1;
        if (tr[u][tmp])u = tr[u][tmp];
        else {
            ret += (1 << i);
            u = tr[u][tmp ^ 1];
        }
    }
    return ret;
}
ll dfs2(ll u, ll pos) {
    if (tr[u][0] and tr[u][1]) {
        ll x = tr[u][0], y = tr[u][1];
        ll mn = inf;
        if (r[x] - l[x] + 1 <= r[y] - l[y] + 1) {
            for (ll k = l[x]; k <= r[x]; k++) {
                mn = min(mn, query(y, pos - 1, w[k]) + (1ll << pos));
            }
        } else {
            for (ll k = l[y]; k <= r[y]; k++) {
                mn = min(mn, query(x, pos - 1, w[k]) + (1ll << pos));
            }
        }
        return mn + dfs2(x, pos - 1) + dfs2(y, pos - 1);
    } else if (tr[u][0]) {
        return dfs2(tr[u][0], pos - 1);
    } else if (tr[u][1]) {
        return dfs2(tr[u][1], pos - 1);
    }
    return 0;
}
void solve() {
    ll n; std::cin >> n;
    vector<array<ll, 3>>e(n + 1);
    for (ll i = 1; i <= n - 1; i++)std::cin >> e[i][0] >> e[i][1] >> e[i][2];
    vector<vector<pair<ll, ll>>>g(n + 1);
    for (ll i = 1; i <= n - 1; i++) {
        auto [u, v, w] = e[i];
        u++; v++;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    function<void(ll, ll)>dfs = [&](ll u, ll f) {
        for (auto [v, q] : g[u]) {
            if (v == f)continue;
            w[v] = w[u] ^ q;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    sort(w + 1, w + 1 + n);
    for (ll i = 1; i <= n; i++)insert(w[i], i);
    cout << dfs2(0, 32) << endl;
}
signed main() {
    solve();
}