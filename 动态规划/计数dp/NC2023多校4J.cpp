#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
//前缀优化dp
void solve() {
    ll n, m; std::cin >> n >> m;
    vector dp(n + 5, vector<ll>(2 * m + 5, 0));
    ll off = m + 1;
    for (ll i = -m; i <= m; i++) {
        dp[1][i + off] = 1;
    }
    vector<ll>pre(2 * m + 5);
    for (ll i = -m; i <= m; i++) {
        pre[i + off] = (pre[i - 1 + off] % mod + dp[1][i + off]) % mod;
    }
    for (ll i = 2; i <= n; i++) {
        for (ll j = -m; j <= m; j++) {
            if (j >= 0) {
                dp[i][j + off] = ((pre[m + off] - pre[j - m - 1 + off]) % mod + mod) % mod;
            } else if (j < 0) {
                ll v = ((pre[m + off] - pre[-j - 1 + off]) % mod + mod) % mod;
                dp[i][j + off] = (dp[i][j + off] % mod + v) % mod;
            }
        }
        for (ll j = -m; j <= m; j++) {
            pre[j + off] = (pre[j + off - 1] % mod + dp[i][j + off]) % mod;
        }
    }
    ll ans = 0;
    for (ll i = -m; i <= m; i++) {
        ans = (ans % mod + dp[n][i + off]) % mod;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}