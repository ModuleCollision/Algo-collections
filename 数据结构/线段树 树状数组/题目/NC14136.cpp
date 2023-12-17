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

struct sq {
    i64 l, r, k;
} ;
void solve() {
    i64 n, m;
    std::cin >> n >> m;
    sq q[m + 5];
    for (i64 i = 1; i <= m; i++) {
        std::cin >> q[i].l >> q[i].r >> q[i].k;
    }
    std::sort(q + 1, q + 1 + m, [&](sq a, sq b)->bool{
        if (a.r != b.r)return a.r < b.r;
        if (a.l != b.l) return a.l < b.l;
        return a.k > b.k;//以后区间排序统一使用该规则
    });
    vector<bool>vis(n + 5, 0); vector<i64>tr(n + 5, 0);
    auto lowbit = [&](i64 x) {
        return x & -x;
    };
    auto add = [&](i64 idx, i64 v) {
        for ( ; idx <= n; idx += lowbit(idx)) {
            tr[idx] += v;
        }
    };
    auto query = [&](i64 idx) {
        i64 ret = 0;
        for (; idx >= 1; idx -= lowbit(idx)) {
            ret += tr[idx];
        }
        return ret;
    };

    for (i64 i = 1; i <= m; i++) {
        i64 l = q[i].l, r = q[i].r;
        i64 tmp = query(r) - query(l - 1);
        if (tmp >= q[i].k)continue;
        i64 las = q[i].k - tmp;
        for (i64 j = r; j >= l; j--) {
            if (not vis[j]) {
                vis[j] = 1; add(j, 1); las--;
            }
            if (not las)break;
        }
    }
    cout << query(n) << endl;
}
signed main() {
    solve();
}