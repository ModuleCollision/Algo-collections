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
void solve() {
    ll n, c; std::cin >> n >> c;
    vector<pair<ll, ll>>op(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> op[i].fi >> op[i].se;
    }
    vector<ll>ans(n + 1);
    for (ll k = 0; k < 30; k++) {
        array<ll, 2>func = {0, 1};
        ll cur = (c >> k) & 1;
        for (ll i = 1; i <= n; i++) {
            array<ll, 2>f;
            auto [t, a] = op[i];
            ll x = (a >> k) & 1;
            if (t == 1)f = {0 & x, 1 & x};
            else if (t == 2)f = {0 | x, 1 | x};
            else f = {0 ^ x, 1 ^ x};
            func = {f[func[0]], f[func[1]]};
            cur = func[cur];
            ans[i] |= (cur << k);
        }
    }
    for (ll i = 1; i <= n; i++)cout << ans[i] << endl;
}
signed main() {
    solve();
}