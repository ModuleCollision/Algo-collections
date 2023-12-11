#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n; std::cin >> n;
    vector<ll>A(n + 1, 0); for (ll i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector pre(n + 1, vector<ll>(33, 0));
    for (ll i = 1; i <= n; i++) {
        for (ll j = 30; j >= 0; j--)pre[i][j] += pre[i - 1][j];
        for (ll j = 30; j >= 0; j--) {
            if ((A[i] >> j) & 1)pre[i][j] += 1;
        }
    }
    vector<ll>cur(33, 0); ll ans = 0;
    for (ll r = 1, l = 1; r <= n; r++) {
        for (ll j = 0; j <= 30; j++) {
            if ((A[r] >> j) & 1)cur[j]++;
        }
        for (ll j = 0; j <= 30; j++) {
            if (cur[j] > 1) {
                while (cur[j] > 1) {
                    for (ll j = 0; j <= 30; j++)if ((A[l] >> j) & 1)cur[j]--;
                    l++;
                }
            }
        }
        ans += r - l + 1;
    }
    cout << ans << endl;
}
signed main() {
    solve();
}