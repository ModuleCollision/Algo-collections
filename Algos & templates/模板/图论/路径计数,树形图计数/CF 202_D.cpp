/*LGV定理,矩阵计数路径数*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3 + 5;
ll dp[maxn][maxn], n, m;
const ll mod = 1e9 + 7;
char G[maxn][maxn];
ll f(ll sx, ll sy, ll tx, ll ty) {
    memset(dp, -1, sizeof(dp));
    dp[sx][sy] = (G[sx][sy] == '.');
    function<void(ll, ll)> dfs = [&](ll x, ll y) {
        if (!(x >= sx and x <= tx and y >= sy and y <= ty)) {
            dp[x][y] = 0;
            return;
        }
        if (dp[x][y] != -1) {
            return;
        }
        if (G[x][y] == '#') {
            dp[x][y] = 0;
            return;
        }
        dp[x][y] = 0;
        dfs(x - 1, y);
        dfs(x, y - 1);
        dp[x][y] = (dp[x - 1][y] + dp[x][y]) % mod;
        dp[x][y] = (dp[x][y] + dp[x][y - 1]) % mod;
    };
    dfs(tx, ty);
    return dp[tx][ty];
}
signed main() {
    std::cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        std::cin >> (G[i] + 1);
    }
    ll f11 = f(1, 2, n - 1, m) % mod;
    ll f12 = f(1, 2, n, m - 1) % mod;
    ll f21 = f(2, 1, n - 1, m) % mod;
    ll f22 = f(2, 1, n, m - 1) % mod;
    cout << (((f11 * f22) % mod - (f12 * f21) % mod + mod) % mod) << endl;
    return 0;
}
