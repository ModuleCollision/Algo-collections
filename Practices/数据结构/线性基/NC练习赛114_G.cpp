#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll w[maxn]; ll p[50];
/*求一组线性无关向量组最大异或和*/
void solve() {
    memset(p, 0, sizeof(p));
    ll n, m; std::cin >> n >> m;
    std::fill(w + 1, w + 1 + n, 0);
    while (m--) {
        ll u, v, q; std::cin >> u >> v >> q;
        w[u] ^= q; w[v] ^= q;
    }
    auto insert = [&](ll u) {
        for (ll i = 33; i >= 0; i--) {
            if ((u >> i) & 1) {
                if (not p[i]) {
                    p[i] = u; break;
                }
                else {
                    u ^= p[i];
                }
            }
        }
    };
    for (ll i = 1; i <= n; i++) {
        insert(w[i]);
    }
    ll ans = 0;
    for (ll i = 33; i >= 0; i--) {
        ans = max(ans, ans ^ p[i]);
    }
    cout << ans << endl;
}
signed main() {
    ll T; std::cin >> T;
    while (T--)
        solve();
}