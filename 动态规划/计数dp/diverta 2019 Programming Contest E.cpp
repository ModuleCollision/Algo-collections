#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
    ll n; std::cin >> n;
    vector<ll>A(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (ll i = 1; i <= n; i++) {
        A[i] ^= A[i - 1];
    }
    if (A[n] != 0) { //0 A[n] 0 A[n]
        vector dp(n + 1, vector<ll>(2, 0));
        dp[0][0] = 1;
        vector<ll>pre(2, 0);
        pre[0] = 1;
        for (ll i = 1; i <= n; i++) {
            if (A[i] == 0) {
                dp[i][0] = (dp[i][0] % mod + pre[1]) % mod;
                pre[0] = (pre[0] % mod + dp[i][0]) % mod;
            } else if (A[i] == A[n]) {
                dp[i][1] = (dp[i][1] % mod + pre[0]) % mod;
                pre[1] = (pre[1] % mod + dp[i][1]) % mod;
            }
        }
        cout << dp[n][1] % mod << endl;
    } else {
        auto ksm = [&](ll x, ll y) {
            ll ret = 1;
            while (y) {
                if (y & 1)ret = ret * x % mod;
                x = x * x % mod;
                y >>= 1;
            }
            return ret % mod;
        }; ll ans = 0;
        ll cnt = 0;
        for (ll i = 0; i <= n; i++)if (A[i] == 0)cnt++;
        ans = (ans % mod + ksm(2, cnt - 2)) % mod;
        vector<ll>pre(n + 1);
        std::unordered_map<ll, ll>pos;
        vector dp(n + 1, 0);
        for (ll i = 1; i <= n; i++) {
            pre[i] += pre[i - 1];
            pre[i] += (A[i] == 0);
        }
        std::unordered_map<ll, ll>w[2];//维护某数下0 1 结尾的dp总数
        for (ll i = 1; i <= n; i++) {
            if (A[i]) {
                if (pos[A[i]] == 0) {
                    ll d = pre[i - 1] + 1;
                    dp[i] = (dp[i] % mod + 1) % mod;
                    w[0][A[i]] = (w[0][A[i]] % mod + 1) % mod;
                    w[1][A[i]] = (w[1][A[i]] % mod + dp[i]) % mod;
                } else {
                    ll d = pre[i] - pre[pos[A[i]]];
                    w[0][A[i]] = (w[0][A[i]] % mod + d * w[1][A[i]]) % mod;
                    dp[i] = (dp[i] % mod + w[0][A[i]]) % mod;
                    w[1][A[i]] = (w[1][A[i]] % mod + dp[i]) % mod;
                }
                pos[A[i]] = i;
            }
        }
        //延迟计算dp    
        for (ll i = 1; i <= n; i++)if (A[i])ans = (ans % mod + dp[i]) % mod;
        cout << ans % mod << endl;
    }
}
signed main() {
    solve();
}