#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 233;
void solve() {
    ll n; std::cin >> n; ll tot = 0;
    pair<ll, ll>k[50];
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll c = 0;
            while (n % i == 0)n /= i, c++;
            k[++tot] = {c, i};
        }
    }
    if (n >= 2) {
        k[++tot] = {1, n};
    }
    vector<ll>pre(tot + 5, 0);
    ll p = 1;
    std::sort(k + 1, k + 1 + tot, [&](pair<ll, ll>a, pair<ll, ll>b)->bool{
        return a.first < b.first;
    });
    for (ll i = tot; i >= 1; i--) {
        p *= k[i].second;
        pre[i] = p;
    }
    ll ans = 0;
    for (ll i = 1; i <= tot; i++) {
        ans += (k[i].first - k[i - 1].first) * pre[i];
    }
    cout << ans << endl;
}
signed main() {
    ll T; std::cin >> T;
    while (T--)solve();
}