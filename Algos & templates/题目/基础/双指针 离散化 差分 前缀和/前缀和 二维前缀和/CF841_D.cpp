/*前缀和+二分的经典问题*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int ans = 0;
    auto check = [&](int k)->bool {
        vector<vector<int>> pre(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                pre[i][j] = (a[i][j] >= k) +
                pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
            }
        }
        for (int i = k; i <= n; i++) {
            for (int j = k; j <= m; j++) {
                int x = i - k + 1, y = j - k + 1;
                if (pre[i][j] + pre[x - 1][y - 1] - pre[x - 1][j] - pre[i][y - 1] == k * k)
                    return true;
            }
        }
        return false;
    };
    int L = 1, R = min(n, m);
    for (int i = 1; i <= 50; i++) {
        int mid = (L + R) >> 1;
        if (check(mid)) {
            ans = max(ans, mid);
            L = mid + 1;
        }
        else R = mid - 1;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}