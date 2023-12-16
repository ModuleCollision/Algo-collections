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
    i64 n; std::cin >> n;
    vector<i64>A(n + 5, 0); for (i64 i = 1; i <= n; i++)cin >> A[i];
    i64 bs = 0; vector<bool>vis(n + 5, false);
    for (i64 j = 0; j < min(n, 30ll); j++) {
        i64 idx = 0, mx = 0;
        for (i64 i = 1; i <= n; i++) {
            if (vis[i])continue;
            if ((bs | A[i]) >= mx) {
                mx = (bs | A[i]); idx = i;
            }
        }
        cout << A[idx] << " "; vis[idx] = 1; bs |= A[idx];
    }
    for (i64 i = 1; i <= n; i++)if (not vis[i])cout << A[i] << " ";
    cout << "\n";
}
signed main() {
    i64 T; std::cin >> T;
    while (T--)
        solve();
}