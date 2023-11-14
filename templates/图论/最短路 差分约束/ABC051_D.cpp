#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 100 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
ll n, m; ll d[maxn][maxn];
void solve() {
    cin >> n >> m; vector<array<ll, 3>>e(m + 1);
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i == j)continue;
            d[i][j] = d[j][i] = inf;
        }
    }
    for (ll i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        e[i] = {u, v, w};
        d[u][v] = d[v][u] = w;
    }
    for (ll k = 1; k <= n; k++) {
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= n; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    ll ans = 0;
    for (ll i = 1; i <= m; i++) {
        auto [u, v, w] = e[i]; bool f = false;
        for (ll j = 1; j <= n; j++) {
            f |= (w + d[u][j] == d[v][j]);
            f |= (w + d[v][j] == d[u][j]);
        }
        if (not f)ans++;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}