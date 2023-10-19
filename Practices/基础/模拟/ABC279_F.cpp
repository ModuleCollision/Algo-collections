#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll fa[maxn], pos[maxn], rt[maxn];
void solve() {
    ll n, q; std::cin >> n >> q;
    for (ll i = 1; i <= n; i++) {
        fa[i] = pos[i] = rt[i] = i;
    }
    auto find = [&](ll x) {
        while (x != fa[x]) {
            x = fa[x] = fa[fa[x]];
        }
        return x;
    };
    while (q--) {
        ll opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            if (rt[y]) {
                if (rt[x]) {
                    fa[find(rt[y])] = find(rt[x]);
                } else {
                    pos[find(rt[y])] = x;
                    rt[x] = find(rt[y]);
                }
                rt[y] = 0;
            }
        } else if (opt == 2) {
            cin >> x; n++;
            if (rt[x]) {
                fa[n] = find(rt[x]);
            } else {
                fa[n] = n;
                pos[n] = x;
                rt[x] = n;
            }
        } else {
            cin >> x;
            ll ans = pos[find(x)];
            cout << ans << endl;
        }
    }
}
signed main() {
    solve();
}