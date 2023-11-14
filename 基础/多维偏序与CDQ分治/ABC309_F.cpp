#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n; std::cin >> n;
    vector<array<ll, 3>>A(n + 5);
    std::unordered_map<ll, ll>w;
    std::vector<ll>k;
    for (ll i = 1; i <= n; i++) {
        std::cin >> A[i][0] >> A[i][1] >> A[i][2];
        std::sort(A[i].begin(), A[i].end());
        k.push_back(A[i][1]);
    }
    std::sort(k.begin(), k.end());
    k.erase(unique(k.begin(), k.end()), k.end());
    std::sort(A.begin() + 1, A.begin() + 1 + n, [&](auto x, auto y)->bool{
        return x[0] < y[0];
    });
    vector<ll>tr(n + 5, inf);
    auto add = [&](ll idx, ll v) {
        for ( ; idx <= n; idx += (idx & -idx)) tr[idx] = min(tr[idx], v);
    };
    auto query = [&](ll idx) {
        ll ret = inf;
        for (; idx >= 1; idx -= (idx & -idx))ret = min(ret, tr[idx]);
        return ret;
    };
    vector<bool>vis(n + 5, 0);
    for (ll i = 0; i < k.size(); i++)w[k[i]] = i + 1;
    for (ll i = 1; i <= n; i++) {
        ll y = w[A[i][1]], z = A[i][2]; ll l = i;
        if (query(y - 1) < z) {
            puts("Yes"); return;
        }
        while (i + 1 <= n and A[i + 1][0] == A[i][0]) {
            i++; ll y = w[A[i][1]], z = A[i][2];
            if (query(y - 1) < z) {
                puts("Yes"); return;
            }
        }
        for (ll j = l; j <= i; j++) {
            ll y = w[A[j][1]], z = A[j][2];
            add(y, z);
        }
    }
    puts("No");
}
signed main() {
    solve();
}