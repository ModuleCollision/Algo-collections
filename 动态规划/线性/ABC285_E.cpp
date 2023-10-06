#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n; std::cin >> n;
    vector<ll>A(n + 1, 0);
    for (ll i = 1; i <= n; i++) {
        cin >> A[i]; A[i] += A[i - 1];
    }
    auto get = [&](ll len) {
        ll ret = 2 * A[len / 2];
        if (len & 1)ret += A[(len / 2) + 1] - A[len / 2];
        return ret;
    };
    vector<ll>dp(n + 5, 0);
    for (ll i = 2; i <= n + 1; i++) {
        for (ll j = 1; j < i; j++) {
            dp[i] = max(dp[i], dp[j] + get(i - j - 1));
        }
    }
    cout << dp[n + 1] << endl;
}
signed main() {
    solve();
}