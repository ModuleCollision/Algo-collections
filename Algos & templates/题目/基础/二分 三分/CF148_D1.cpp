#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e3 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
    ll n, q; std::cin >> n >> q;
    vector<ll>A(n + 5, 0);
    for (ll i = 1; i <= n; i++) {
        std::cin >> A[i];
    }
    std::sort(A.begin() + 1, A.begin() + 1 + n);
    auto mn = A;
    for (ll i = 1; i <= n; i++) {
        mn[i] -= i - 1;
    }
    auto pre = mn;
    for (ll i = 2; i <= n; i++)pre[i] += pre[i - 1];
    for (ll i = 2; i <= n; i++)mn[i] = min(mn[i - 1], mn[i]);
    while (q--) {
        ll k; std::cin >> k;
        if (n == 1) {
            if (k & 1) {
                cout << A[1] - k / 2 + k << endl;
            } else {
                cout << A[1] - k / 2 << endl;
            }
        }
        auto check = [&](ll mid) {
            ll cnt = lower_bound(A.begin() + 1, A.begin() + 1 + n, mid) - A.begin() - 1;
            if (not cnt)return true;
            if (cnt > k)return false;
            if (cnt == n and (k - cnt) & 1)return false;
            if (mn[cnt] + k < mid)return false;
            if (cnt == n) {
                ll re = k - cnt - 2 * (cnt * (k - mid) + pre[cnt]);
                return re <= 0;
            }
            ll re = k - cnt - 2 * (cnt * (k - mid) + pre[cnt]);
            if (re <= 0 or re % 2 == 1) return true;
            if (n - cnt >= 2) return true;
            if (A.back() - re / 2 >= mid) return true;
            return false;
        };
        ll l = 1, r = 1e10;
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            if (check(mid))l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}
signed main() {
    ll T; std::cin >> T;
    while (T--)solve();
}