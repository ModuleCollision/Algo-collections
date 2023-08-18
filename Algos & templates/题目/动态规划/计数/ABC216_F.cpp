#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll N, A[maxn], B[maxn];
pair<ll, ll>st[maxn];
ll dp[maxn][maxn];
void solve() {
    std::cin >> N;
    for (ll i = 1; i <= N; i++) {
        std::cin >> st[i].first;
    }
    for (ll i = 1; i <= N; i++) {
        std::cin >> st[i].second;
    }
    std::sort(st + 1, st + 1 + N, [&](pair<ll, ll>a, pair<ll, ll>b)->bool{
        return a.first < b.first;
    });
    dp[0][0] = 1; ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        for (ll j = 5e3 + 5; j >= 0; j--) {
            if (j >= st[i].second) {
                dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - st[i].second]) % mod;
            }
            dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
        }
        for (ll k = st[i].second; k <= st[i].first; k++) {
            ans = (ans % mod + dp[i - 1][k - st[i].second]) % mod;
        }
    }
    cout << ans % mod << endl;
}
signed main() {
    solve();
}