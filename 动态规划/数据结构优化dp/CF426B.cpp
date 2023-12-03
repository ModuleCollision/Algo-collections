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
struct sq {
    i64 l; i64 r;
    i64 mx; i64 laz;
} tr[maxn];
i64 a[maxn];
void pushup(i64 p) {
    tr[p].mx = max(tr[p << 1].mx, tr[p << 1 | 1].mx);
}
void pushdown(i64 p) {
    if (tr[p].laz) {
        i64 laz = tr[p].laz;
        tr[p].laz = 0;
        tr[p << 1].laz += laz;
        tr[p << 1].mx += laz;
        tr[p << 1 | 1].laz += laz;
        tr[p << 1 | 1].mx += laz;
    }
}
void build(i64 p, i64 l, i64 r) {
    tr[p].l = l; tr[p].r = r; tr[p].mx = tr[p].laz = 0;
    if (l == r) {
        tr[p].mx = a[l - 1];
        return;
    }
    i64 mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
void modify(i64 p, i64 l, i64 r, i64 v) {
    if (tr[p].l >= l and tr[p].r <= r) {
        tr[p].mx += v; tr[p].laz += v;
        return;
    }
    i64 mid = (tr[p].l + tr[p].r) >> 1;
    pushdown(p);
    if (l <= mid)modify(p << 1, l, r, v);
    if (r > mid)modify(p << 1 | 1, l, r, v);
    pushup(p);
}
i64 query(i64 p, i64 l, i64 r) {
    if (tr[p].l >= l and tr[p].r <= r) {
        return tr[p].mx;
    }
    i64 ret = 0;
    pushdown(p);
    i64 mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid)ret = max(ret, query(p << 1, l, r));
    if (r > mid)ret = max(ret, query(p << 1 | 1, l, r));
    return ret;
}
void solve() {
    i64 n, k; cin >> n >> k;

    for (i64 i = 1; i <= n; i++)cin >> a[i];
    vector<i64>p(n + 5), pre(n + 5);
    for (i64 i = 1; i <= n; i++) {
        pre[i] = p[a[i]];
        p[a[i]] = i;
    }
    vector<i64>dp(n + 1);
    for (i64 i = k; i >= 1; i--) {
        build(1, 1, n);
        for (i64 j = 1; j <= n; j++) {
            modify(1, pre[j] + 1, j, 1);
            dp[j] = query(1, 1, j);
        }
    }
    cout << dp[n] << "\n";
}
signed main() {
    solve();
}