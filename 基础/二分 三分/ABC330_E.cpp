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
    i64 n, q; cin >> n >> q;
    vector<i64>a(n + 1);
    for (i64 i = 1; i <= n; i++)cin >> a[i];
    std::map<i64, i64>cnt;
    vector<i64>tr(n + 5);
    auto add = [&](i64 idx, i64 v) {
        for (; idx <= n + 1; idx += (idx & -idx))tr[idx] += v;
    };
    auto query = [&](i64 idx) {
        i64 ret = 0;
        for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
        return ret;
    };
    for (i64 i = 1; i <= n; i++) {
        cnt[a[i]]++;
        if (a[i] >= 0 and a[i] <= n and cnt[a[i]] == 1)add(a[i] + 1, 1);
    }
    i64 cur = 0;
    while (cnt[cur])cur++;
    while (q--) {
        i64 idx, x; cin >> idx >> x;
        i64 tmp = a[idx];
        cnt[tmp]--; a[idx] = x; cnt[x]++;
        if (cnt[tmp] == 0)add(tmp + 1, -1);
        if (cnt[x] == 1)add(x + 1, 1);
        if (tmp < cur and cnt[tmp] == 0)cur = tmp;
        else {
            i64 l = 0, r = n;
            i64 ans = -1;
            while (l <= r) {
                i64 mid = (l + r) >> 1;
                if (query(mid) == mid)l = mid + 1, ans = mid;
                else r = mid - 1;
            }
            if (ans != -1)
                cur = ans;
        }
        cout << cur << "\n";
    }
}
signed main() {
    solve();
}