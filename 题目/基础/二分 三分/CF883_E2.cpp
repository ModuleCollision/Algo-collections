#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 3010;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n; std::cin >> n;
    auto check = [&](ll x, ll p) {
        __int128 f = n;
        f = f * (x - 1);
        __int128 mx = 1e27;
        if (f > mx)return 0;
        __int128 res = 1;
        for (ll i = 1; i <= p; i++) {
            res = res * x; if (res > mx)return 0;
        }
        res -= 1;
        __int128 k = res;
        if (res > f)return 0;
        else if (res < f)return 1;
        else if (res == f)return 2;
    };
    for (ll i = 3; i <= 64; i++) {
        ll l = 2, r = 1e9;
        while (l < r) {
            ll mid = (l + r) >> 1;
            if (check(mid, i) == 0)r = mid;
            else if (check(mid, i) == 1)l = mid + 1;
            else {
                puts("YES"); return;
            }
        }
    }
    puts("NO"); return;
}
signed main() {
    ll T; std::cin >> T; while (T--)
        solve();
}