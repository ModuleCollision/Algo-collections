#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll x;
void solve() {
    ll n, m, k, Q;
    std::cin >> n >> m >> k >> Q;
    vector<ll>A(n + 5, 0), B(m + 5, 0);
    for (ll i = 1; i <= n; i++) {
        std::cin >> A[i];
    }
    for (ll i = 1; i <= m; i++) {
        std::cin >> B[i];
    }
    vector<ll>C(k + 5, 0);
    for (ll i = 1; i <= k; i++) {
        ll u, v; std::cin >> u >> v;
        C[i] = A[u] * B[v];
    }
    std::sort(A.begin() + 1, A.begin() + 1 + n);
    std::sort(B.begin() + 1, B.begin() + 1 + m);
    std::sort(C.begin() + 1, C.begin() + 1 + k);
    auto check = [&](ll mid) {
        ll sum = 0;
        for (ll i = 1; i <= n; i++) {
            if (mid % A[i] == 0) {
                sum += lower_bound(B.begin() + 1, B.begin() + 1 + m, mid / A[i]) - B.begin() - 1;
            } else {
                sum += upper_bound(B.begin() + 1, B.begin() + 1 + m, mid / A[i]) - B.begin() - 1;
            }
        }
        sum -= lower_bound(C.begin() + 1, C.begin() + 1 + k, mid) - C.begin() - 1;
        return sum <= x - 1;
    };
    while (Q--) {
        std::cin >> x;
        ll l = 0, r = 1e12, ans = 0;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            if (check(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        //第二种二分方
        /*while (l < r) {
            ll mid = (l + r + 1) >> 1;
            if (check(mid))l = mid;
            else r = mid - 1;
        }*/

        cout << ans << endl;
    }
}
signed main() {
    solve();
}