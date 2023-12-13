#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll f[maxn];
void solve() {
    auto chart = [&](ll x) {
        vector<ll>s(x + 5);
        for (ll i = 1; i <= x; i++)s[i] = i;
        ll cnt = 0;
        do {
            vector<ll>w(x + 5);
            for (ll i = 1; i <= x; i++)w[i] = s[i];
            while (1) {
                bool f = 1;
                for (ll i = 1; i <= x - 1; i++) {
                    if (w[i] > w[i + 1]) {
                        f = 0; break;
                    }
                }
                if (f)break;
                cnt++;
                ll idx = 0, val = 0; ll cur = 0;
                for (ll i = x; i >= 1; i--) {
                    if (w[i] != i) {
                        if (w[i] > cur) {
                            cur = w[i]; val = w[i], idx = i;
                        }
                    }
                }
                for (ll i = idx; i <= val - 1; i++)swap(w[i], w[i + 1]);
            }
        } while (next_permutation(s.begin() + 1, s.begin() + 1 + x));
        cout << cnt << endl;
    };
    auto inv = [&](ll x) {
        ll ret = 1; ll y = mod - 2;
        while (y) {
            if (y & 1)ret = ret * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ret % mod;
    };
    f[1] = 0;
    for (ll i = 2; i <= 1e6; i++) {
        f[i] = (f[i - 1] % mod + (i - 1) % mod * inv(i)) % mod;
    }
    ll t; std::cin >> t;
    while (t--) {
        ll n; cin >> n; cout << f[n] << endl;
    }
}
signed main() {
    solve();
}