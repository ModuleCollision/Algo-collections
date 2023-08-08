#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1000005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n, k;
    cin >> n >> k;
    k -= n - 1;
    vector<ll> seq;
    seq.push_back(1);
    seq.push_back(n);
    for (ll l = 2, r = n - 1, flag = 1; l <= r && k;) {
        if (flag) {
            ll t = min(k, seq.back() - l);
            l = seq.back() - t;
            k -= t;
            seq.push_back(l);
            ++l;
        } else {
            ll t = min(k, r - seq.back());
            r = seq.back() + t;
            k -= t;
            seq.push_back(r);
            --r;
        }
        flag = !flag;
    }
    vector<ll>ans(n + 5, 0);
    seq.erase(seq.begin());
    ll t = n;
    for (auto it = seq.rbegin(); it != seq.rend(); ++it) {
        ans[*it] = t--;
    }
    t = 1;
    for (ll i = 1; i <= n; ++i) {
        if (!ans[i]) {
            ans[i] = t++;
        }
    }
    for (ll i = 1; i <= n; ++i) {
        cout << ans[i] << ' ';
    }
}
signed main() {
    solve();
}
