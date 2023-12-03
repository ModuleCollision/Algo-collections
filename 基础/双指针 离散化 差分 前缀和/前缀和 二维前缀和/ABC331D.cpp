#include<bits/stdc++.h>
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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
    i64 n; cin >> n; i64 q; cin >> q;
    vector<string>g(n + 1);
    for (i64 i = 1; i <= n; i++)cin >> g[i], g[i] = " " + g[i];
    vector pre(n + 1, vector<i64>(n + 1, 0));
    for (i64 i = 1; i <= n; i++) {
        for (i64 j = 1; j <= n; j++) {
            pre[i][j] = (pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
            pre[i][j] += (g[i][j] == 'B');
        }
    }
    auto query = [&](i64 x, i64 y, i64 x2, i64 y2) {
        return (pre[x2][y2] - pre[x - 1][y2] - pre[x2][y - 1] + pre[x - 1][y - 1]);
    };
    auto ch = [&](i64 x) {
        x %= n; if (not x)x = n;
        return x;
    };
    auto cal = [&](i64 x, i64 y) {
        return pre[n][n] * (x / n) * (y / n) + pre[x % n][y % n] + pre[x % n][n] * (y / n) + pre[n][y % n] * (x / n);
    };
    while (q--) {
        i64 a, b, c, d; cin >> a >> b >> c >> d;
        a++; b++; c++; d++;
        cout << cal(c, d) - cal(a - 1, d) - cal(c, b - 1) + cal(a - 1, b - 1) << "\n";

    }
}
signed main() {
    solve();
}