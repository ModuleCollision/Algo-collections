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
/*块状数据结构*/
i64 len, tot; i64 a[maxn], d[maxn], laz[maxn];
i64 L[maxn], R[maxn], be[maxn];
i64 n, q;
void build() {
    len = sqrt(n); tot = (n + len - 1) / len;
    for (int i = 1; i <= n; i++) {
        be[i] = (i + len - 1) / len, d[i] = a[i];
    }
    for (int i = 1; i <= tot; i++) {
        L[i] = (i - 1) * len + 1, R[i] = i * len;
    }
    R[tot] = n;
    for (i64 i = 1; i <= tot; i++) {
        sort(d + L[i], d + R[i] + 1);
    }
}
void modify(i64 x, i64 y, i64 k) {
    if (be[x] == be[y]) {
        for (i64 i = x; i <= y; i++)a[i] += k;
        for (i64 i = L[be[x]]; i <= R[be[x]]; i++) {
            d[i] = a[i];
        }
        sort(d + L[be[x]], d + R[be[x]] + 1);
    } else {
        for (int i = x; i <= R[be[x]]; i++) {
            a[i] += k;
        }
        for (int i = L[be[x]]; i <= R[be[x]]; i++) {
            d[i] = a[i];
        }
        sort(d + L[be[x]], d + R[be[x]] + 1);
        for (int i = L[be[y]]; i <= y; i++) {
            a[i] += k;
        }
        for (int i = L[be[y]]; i <= R[be[y]]; i++) {
            d[i] = a[i];
        }
        sort(d + L[be[y]], d + R[be[y]] + 1);
        for (int i = be[x] + 1; i <= be[y] - 1; i++) {
            laz[i] += k;
        }
    }
}

i64 query(i64 x, i64 y, i64 k) {
    i64 ret = 0;
    if (be[x] == be[y]) {
        for (i64 i = x; i <= y; i++) {
            if (laz[be[x]] + a[i] >= k)ret++;
        }
    } else {
        for (i64 i = x; i <= R[be[x]]; i++) {
            if (laz[be[x]] + a[i] >= k)ret++;
        }
        for (i64 i = L[be[y]]; i <= y; i++) {
            if (laz[be[y]] + a[i] >= k)ret++;
        }
        for (i64 i = be[x] + 1; i <= be[y] - 1; i++) {
            i64 l = L[i], r = R[i]; i64 ans = 0;
            while (l <= r) {
                i64 mid = (l + r) >> 1;
                if (d[mid] + laz[i] >= k)r = mid - 1, ans = mid;
                else l = mid + 1;
            }
            if (ans)
                ret += (R[i] - ans + 1);
        }
    }
    return ret;
}
void solve() {
    cin >> n >> q;
    for (i64 i = 1; i <= n; i++)cin >> a[i];
    build();
    while (q--) {
        string o; cin >> o;
        i64 x, y, k; cin >> x >> y >> k;
        if (o == "M") {
            modify(x, y, k);
        } else {
            cout << query(x, y, k) << "\n";
        }
    }
}
signed main() {
    solve();
}