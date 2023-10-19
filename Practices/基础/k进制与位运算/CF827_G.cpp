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
    ll n; std::cin >> n;
    vector<ll>A(n + 5, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
    ll bs = 0; vector<bool>vis(n + 5, false);
    for (ll j = 0; j < min(n, 30ll); j++) {
        ll idx = 0, mx = 0;
        for (ll i = 1; i <= n; i++) {
            if (vis[i])continue;
            if ((bs | A[i]) >= mx) {
                mx = (bs | A[i]); idx = i;
            }
        }
        cout << A[idx] << " "; vis[idx] = 1; bs |= A[idx];
    }
    for (ll i = 1; i <= n; i++)if (not vis[i])cout << A[i] << " ";
    cout << endl;
}
signed main() {
    ll T; std::cin >> T;
    while (T--)
        solve();
}