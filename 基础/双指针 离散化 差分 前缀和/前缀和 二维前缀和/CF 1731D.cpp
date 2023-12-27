/*前缀和+二分的经典问题*/
#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

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