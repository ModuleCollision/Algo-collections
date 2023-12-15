/*普通莫队进行区间处理*/
/*莫队算法 + 约数和定理 + 素数筛*/
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

constexpr i64 mod = 1145141;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 n, m, cur = 1;
i64 a[maxn], inv[maxn], cnt[maxn], ans[maxn];
vector<pair<i64, i64>>v[maxn];//维护每一位数的分解以及幂次
struct query {
    i64 l, r, id;
} q[maxn];
i64 rk[maxn], son[maxn], tot = 0;
void solve() {
    std::cin >> n >> m;
    for (i64 i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (i64 i = 1; i <= m; i++) {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    i64 k = (i64)sqrt(n);
    std::sort(q + 1, q + 1 + m, [&](query & a, query & b)->bool{
        i64 x = (a.l - 1) / k + 1, y = (b.l - 1) / k + 1;
        if (x == y) {
            return a.r < b.r;
        } else{
            return a.l < b.l;
        }
    });//分块处理区间并排序
    for (i64 i = 2; i <= 1e6; i++) {
        if (not son[i]) {
            son[i] = i; rk[i] = ++tot;
            for (i64 j = i + i; j <= 1e6; j += i) {
                if (not son[j]) {
                    son[j] = i;
                }
            }
        }
    }//维护的是每一个非素数的第一个素数因子
    for (i64 i = 1; i <= n; i++) {
        i64 x = a[i], las = son[x];
        while (x != 1) {
            i64 tem = rk[son[x]];
            i64 t = 0;
            while (x % las == 0) {
                ++t; x /= las;
            }
            v[i].push_back({tem, t});
            las = son[x];
        }
    }
    inv[1] = 1;
    for (i64 i = 2; i <= 1e6; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    auto add = [&](i64 x) {
        for (auto [a, b] : v[x]) {
            cur = cur * inv[cnt[a] + 1] % mod;
            cnt[a] += b;
            cur = cur * (cnt[a] + 1) % mod;
        }
    };
    auto del = [&](i64 x) {
        for (auto [a, b] : v[x]) {
            cur = cur * inv[cnt[a] + 1] % mod;
            cnt[a] -= b;
            cur = cur * (cnt[a] + 1) % mod;
        }
    };
    for (i64 i = 1, L = 1, R = 0; i <= m; i++) {
        while (R < q[i].r) {
            add(++R);
        }
        while (L > q[i].l) {
            add(--L);
        }
        while (R > q[i].r) {
            del(R--);
        }
        while (L < q[i].l) {
            del(L++);
        }
        ans[q[i].id] = cur;
    }
    for (i64 i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
}
signed main() {
    solve(); return 0;
}