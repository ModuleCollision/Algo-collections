#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;

void solve() {
    ll a, b, n, l, r;
    ll x, y;
    function<ll(ll, ll, ll&, ll&)>exgcd = [&] (ll a, ll b, ll & x, ll & y) {
        if (b == 0) {
            x = 1; y = 0;
            return a;
        }
        ll d = exgcd(b, a % b, x, y);
        ll temp = x; x = y;
        y = temp - a / b * y;
        return d;
    };
    std::cin >> a >> b >> n >> l >> r;
    ll d = exgcd(a, b, x, y);
    if (n % d) {
        puts("NO"); return;
    }
    b /= d;
    ll x0 = (x * n / d % b + b) % b;
    if (x0 >= l) {
        if (x0 <= r) {
            puts("YES"); return;
        } else {
            puts("NO"); return;
        }
    } else {
        x0 = (l - x0 + b - 1) / b * b + x0;
        if (x0 <= r) {
            puts("YES"); return;
        } else {
            puts("NO"); return;
        }
    }
    puts("NO"); return;
}
signed main() {
    ll T; std::cin >> T;
    while (T--)solve();
}