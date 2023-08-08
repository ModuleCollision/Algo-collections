/*普通莫队进行区间处理*/
/*莫队算法 + 约数和定理 + 素数筛*/
#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
ll n, m, cur = 1;
ll a[maxn], inv[maxn], cnt[maxn], ans[maxn];
vector<pair<ll, ll>>v[maxn];//维护每一位数的分解以及幂次
struct query {
    ll l, r, id;
} q[maxn];
ll rk[maxn], son[maxn], tot = 0;
void solve() {
    std::cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (ll i = 1; i <= m; i++) {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    ll k = (ll)sqrt(n);
    std::sort(q + 1, q + 1 + m, [&](query & a, query & b)->bool{
        ll x = (a.l - 1) / k + 1, y = (b.l - 1) / k + 1;
        if (x == y) {
            return a.r < b.r;
        } else{
            return a.l < b.l;
        }
    });//分块处理区间并排序
    for (ll i = 2; i <= 1e6; i++) {
        if (not son[i]) {
            son[i] = i; rk[i] = ++tot;
            for (ll j = i + i; j <= 1e6; j += i) {
                if (not son[j]) {
                    son[j] = i;
                }
            }
        }
    }//维护的是每一个非素数的第一个素数因子
    for (ll i = 1; i <= n; i++) {
        ll x = a[i], las = son[x];
        while (x != 1) {
            ll tem = rk[son[x]];
            ll t = 0;
            while (x % las == 0) {
                ++t; x /= las;
            }
            v[i].push_back({tem, t});
            las = son[x];
        }
    }
    inv[1] = 1;
    for (ll i = 2; i <= 1e6; i++) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
    auto add = [&](ll x) {
        for (auto [a, b] : v[x]) {
            cur = cur * inv[cnt[a] + 1] % mod;
            cnt[a] += b;
            cur = cur * (cnt[a] + 1) % mod;
        }
    };
    auto del = [&](ll x) {
        for (auto [a, b] : v[x]) {
            cur = cur * inv[cnt[a] + 1] % mod;
            cnt[a] -= b;
            cur = cur * (cnt[a] + 1) % mod;
        }
    };
    for (ll i = 1, L = 1, R = 0; i <= m; i++) {
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
    for (ll i = 1; i <= m; i++) {
        cout << ans[i] << endl;
    }
}
signed main() {
    solve(); return 0;
}