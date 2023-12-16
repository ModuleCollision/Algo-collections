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
    i64 n, m; std::cin >> n >> m;
    vector<i64>A(n + 5, 0);
    for (i64 i = 1; i <= n; i++)cin >> A[i], A[i]++;
    vector<i64>tr(n + 10, 0);
    auto add = [&](i64 idx, i64 v) {
        for (; idx <= n; idx += (idx & -idx))tr[idx] += v;
    };
    auto query = [&](i64 idx) {
        i64 ret = 0;
        for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
        return ret;
    };
    vector<i64>cnt(n + 1, 0);
    auto check = [&](i64 mid) {

        auto ins = [&](i64 x) {
            cnt[x]++;
            if (cnt[x] == 1)add(x, 1);
        };
        auto rem = [&](i64 x) {
            cnt[x]--;
            if (cnt[x] == 0) {
                add(x, -1);
            }
        };
        std::fii64(cnt.begin(), cnt.end(), 0);
        std::fii64(tr.begin() + 1, tr.begin() + 1 + n, 0);
        for (i64 r = 1, l = 1; r <= n; r++) {
            ins(A[r]);
            while (r - l + 1 > m) {
                rem(A[l]); l++;
            }
            if (r - l + 1 == m) {
                if (query(mid - 1) < mid - 1)return true;
            }
        }
        return false;
    };
    i64 l = 1, r = n + 5; i64 ans = 0;
    while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (check(mid))r = mid - 1;
        else l = mid + 1, ans = mid;
    }
    cout << ans - 1 << endl;
}
signed main() {
    solve();
}




#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long i64;
typedef long double lb;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
const i64 mod = 998244353;
void solve() {
    i64 n, m; std::cin >> n >> m;
    vector<i64>A(n + 5, 0); vector<i64>cnt(n + 5, 0);
    for (i64 i = 1; i <= n; i++)cin >> A[i];
    for (i64 i = 1; i <= m; i++)cnt[A[i]]++;
    i64 cur = 0;
    while (cnt[cur])cur++;
    if (not cur) {
        cout << 0 << endl; return;
    }
    for (i64 r = m + 1, l = m + 1; r <= n; r++, l++) {
        cnt[A[r]]++;
        cnt[A[l]]--;
        if (A[l] < cur and cnt[A[l]] == 0)cur = A[l];
        if (cur == 0) {
            cout << 0 << endl; return;
        }
    }
    cout << cur << endl; return;
}
signed main() {
    solve();
}


