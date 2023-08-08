/*LGV定理,矩阵计数路径数*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3e3 + 5;
const ll mod = 1e9 + 7;
ll fac[maxn], invfac[maxn], inv[maxn];
void pre() {
    fac[0] = fac[1] = 1;
    invfac[0] = invfac[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i <= 2e3; i++) {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
        invfac[i] = invfac[i - 1] * inv[i] % mod;
    }
}
ll C(ll n, ll m) {
    return fac[n] % mod * invfac[n - m] % mod * invfac[m] % mod;
}
signed main() {
    pre();
    ll n, m;
    while (std::cin >> n >> m) {
        ll ans;
        ans = (C(n + m, n) % mod * C(n + m, n) % mod - C(n + m, n - 1) % mod * C(n + m, n + 1) % mod + mod) % mod;
        cout << ans << endl;
    }
}