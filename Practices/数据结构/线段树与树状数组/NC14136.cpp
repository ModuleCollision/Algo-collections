#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
    ll l, r, k;
} ;
void solve() {
    ll n, m;
    std::cin >> n >> m;
    sq q[m + 5];
    for (ll i = 1; i <= m; i++) {
        std::cin >> q[i].l >> q[i].r >> q[i].k;
    }
    std::sort(q + 1, q + 1 + m, [&](sq a, sq b)->bool{
        if (a.r != b.r)return a.r < b.r;
        if (a.l != b.l) return a.l < b.l;
        return a.k > b.k;//以后区间排序统一使用该规则
    });
    vector<bool>vis(n + 5, 0); vector<ll>tr(n + 5, 0);
    auto lowbit = [&](ll x) {
        return x & -x;
    };
    auto add = [&](ll idx, ll v) {
        for ( ; idx <= n; idx += lowbit(idx)) {
            tr[idx] += v;
        }
    };
    auto query = [&](ll idx) {
        ll ret = 0;
        for (; idx >= 1; idx -= lowbit(idx)) {
            ret += tr[idx];
        }
        return ret;
    };

    for (ll i = 1; i <= m; i++) {
        ll l = q[i].l, r = q[i].r;
        ll tmp = query(r) - query(l - 1);
        if (tmp >= q[i].k)continue;
        ll las = q[i].k - tmp;
        for (ll j = r; j >= l; j--) {
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