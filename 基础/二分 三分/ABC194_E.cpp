#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n, m; std::cin >> n >> m;
    vector<ll>A(n + 5, 0);
    for (ll i = 1; i <= n; i++)cin >> A[i], A[i]++;
    vector<ll>tr(n + 10, 0);
    auto add = [&](ll idx, ll v) {
        for (; idx <= n; idx += (idx & -idx))tr[idx] += v;
    };
    auto query = [&](ll idx) {
        ll ret = 0;
        for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
        return ret;
    };
    vector<ll>cnt(n + 1, 0);
    auto check = [&](ll mid) {

        auto ins = [&](ll x) {
            cnt[x]++;
            if (cnt[x] == 1)add(x, 1);
        };
        auto rem = [&](ll x) {
            cnt[x]--;
            if (cnt[x] == 0) {
                add(x, -1);
            }
        };
        std::fill(cnt.begin(), cnt.end(), 0);
        std::fill(tr.begin() + 1, tr.begin() + 1 + n, 0);
        for (ll r = 1, l = 1; r <= n; r++) {
            ins(A[r]);
            while (r - l + 1 > m) {
                rem(A[l]); l++;
            }
            if (r - l + 1 == m) {
                if (query(mid - 1) < mid - 1)return true;
            }
        }
        return false;
    };
    ll l = 1, r = n + 5; ll ans = 0;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        if (check(mid))r = mid - 1;
        else l = mid + 1, ans = mid;
    }
    cout << ans - 1 << endl;
}
signed main() {
    solve();
}




#include<bits/stdc++.h>
using namespace std;
#define fi fifst
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll n, m; std::cin >> n >> m;
    vector<ll>A(n + 5, 0); vector<ll>cnt(n + 5, 0);
    for (ll i = 1; i <= n; i++)cin >> A[i];
    for (ll i = 1; i <= m; i++)cnt[A[i]]++;
    ll cur = 0;
    while (cnt[cur])cur++;
    if (not cur) {
        cout << 0 << endl; return;
    }
    for (ll r = m + 1, l = m + 1; r <= n; r++, l++) {
        cnt[A[r]]++;
        cnt[A[l]]--;
        if (A[l] < cur and cnt[A[l]] == 0)cur = A[l];
        if (cur == 0) {
            cout << 0 << endl; return;
        }
    }
    cout << cur << endl; return;
}
signed main() {
    solve();
}


