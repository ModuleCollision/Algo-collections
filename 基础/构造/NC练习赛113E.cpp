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
    i64 n, k;
    cin >> n >> k;
    k -= n - 1;
    vector<i64> seq;
    seq.push_back(1);
    seq.push_back(n);
    for (i64 l = 2, r = n - 1, flag = 1; l <= r && k;) {
        if (flag) {
            i64 t = min(k, seq.back() - l);
            l = seq.back() - t;
            k -= t;
            seq.push_back(l);
            ++l;
        } else {
            i64 t = min(k, r - seq.back());
            r = seq.back() + t;
            k -= t;
            seq.push_back(r);
            --r;
        }
        flag = !flag;
    }
    vector<i64>ans(n + 5, 0);
    seq.erase(seq.begin());
    i64 t = n;
    for (auto it = seq.rbegin(); it != seq.rend(); ++it) {
        ans[*it] = t--;
    }
    t = 1;
    for (i64 i = 1; i <= n; ++i) {
        if (!ans[i]) {
            ans[i] = t++;
        }
    }
    for (i64 i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}
signed main() {
    solve();
}
