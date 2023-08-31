#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n; std::cin >> n;
    vector<ll>x(n + 5, 0), y(n + 5, 0), z(n + 5, 0);
    ll p = 0, sum = 0;
    vector<array<ll, 3>>w(n + 5); ll tot = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> x[i] >> y[i] >> z[i];
        sum += z[i];
        if (x[i] > y[i])p += z[i];
        else {
            w[++tot] = {x[i], y[i], z[i]};
        }
    }
    ll s = (sum + 1) / 2;
    if (p >= s) {
        puts("0"); return;
    }
    ll v = s - p;
    vector dp(tot + 5, vector<ll>(sum + 5, inf));
    dp[0][0] = 0;
    for (ll i = 1; i <= tot; i++) {
        for (ll j = 0; j <= sum; j++) {
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            ll d = (w[i][0] + w[i][1] + 1) / 2 - w[i][0];
            if (j >= w[i][2]) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - w[i][2]] + d);
            }
        }
    }
    ll ans = inf;
    for (ll j = v; j <= sum; j++)ans = min(ans, dp[tot][j]);
    cout << ans << endl;
}
signed main() {
    solve();
}