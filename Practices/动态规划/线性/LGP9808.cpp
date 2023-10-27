#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 3e3 + 105;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
int dp[maxn][105][105][2]; int a[maxn], b[105];
//前 n + m位 , 使用前i个数和前 j个数,序列中第 k 个数选不选
int dp2[maxn][2];
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++)cin >> a[i];
    int m; cin >> m;
    for (int i = 1; i <= m; i++)cin >> b[i];
    sort(b + 1, b + 1 + m);
    dp[1][1][0][1] = a[1]; dp[1][0][1][1] = b[1];
    if (not m) {
        for (int i = 1; i <= n; i++) {
            dp2[i][1] = max(dp2[i][1], dp2[i - 1][0] + a[1]);
            dp2[i][0] = max(dp2[i][0], dp2[i - 1][1]);
            dp2[i][0] = max(dp2[i][0], dp2[i - 1][0]);
        }
        cout << max(dp2[n][0], dp2[n][1]) << endl;
        return;
    }
    for (int i = 2; i <= n + m; i++) {
        for (int j = 0; j <= min(n, i); j++) {
            for (int k = 0; k <= min(m, i - j); k++) {
                if (j)
                    dp[i][j][k][1] = max(dp[i][j][k][1], dp[i - 1][j - 1][k][0] + a[j]);
                if (k)
                    dp[i][j][k][1] = max(dp[i][j][k][1], dp[i - 1][j][k - 1][0] + b[k]);
                if (j >= 1) {
                    dp[i][j][k][0] = max(dp[i][j][k][0], dp[i - 1][j - 1][k][1]);
                    dp[i][j][k][0] = max(dp[i][j][k][0], dp[i - 1][j - 1][k][0]);
                }
                if (k >= 1) {
                    dp[i][j][k][0] = max(dp[i][j][k][0], dp[i - 1][j][k - 1][1]);
                    dp[i][j][k][0] = max(dp[i][j][k][0], dp[i - 1][j][k - 1][0]);
                }
            }
        }
    }
    int ans = max(dp[n + m][n][m][1], dp[n + m][n][m][0]);
    cout << ans << " \n";
}
signed main() {
    solve();
}