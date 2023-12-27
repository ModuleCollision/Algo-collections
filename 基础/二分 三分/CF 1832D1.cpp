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
    i64 n, q; std::cin >> n >> q;
    vector<i64>A(n + 5, 0);
    for (i64 i = 1; i <= n; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin() + 1, A.begin() + 1 + n);
    auto mn = A;
    for (i64 i = 1; i <= n; i++) {
        mn[i] -= i - 1;
    }
    auto pre = mn;
    for (i64 i = 2; i <= n; i++)pre[i] += pre[i - 1];
    for (i64 i = 2; i <= n; i++)mn[i] = min(mn[i - 1], mn[i]);
    while (q--) {
        i64 k; std::cin >> k;
        if (n == 1) {
            if (k & 1) {
                cout << A[1] - k / 2 + k << endl;
            } else {
                cout << A[1] - k / 2 << endl;
            }
        }
        auto check = [&](i64 mid) {
            i64 cnt = lower_bound(A.begin() + 1, A.begin() + 1 + n, mid) - A.begin() - 1;
            if (not cnt)return true;
            if (cnt > k)return false;
            if (cnt == n and (k - cnt) & 1)return false;
            if (mn[cnt] + k < mid)return false;
            if (cnt == n) {
                i64 re = k - cnt - 2 * (cnt * (k - mid) + pre[cnt]);
                return re <= 0;
            }
            i64 re = k - cnt - 2 * (cnt * (k - mid) + pre[cnt]);
            if (re <= 0 or re % 2 == 1) return true;
            if (n - cnt >= 2) return true;
            if (A.back() - re / 2 >= mid) return true;
            return false;
        };
        i64 l = 1, r = 1e10;
        while (l < r) {
            i64 mid = (l + r + 1) >> 1;
            if (check(mid))l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}
signed main() {
    i64 T; std::cin >> T;
    while (T--)solve();
}