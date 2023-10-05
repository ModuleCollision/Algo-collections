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
    ll n, k; std::cin >> n >> k; bool f1 = 1;
    vector<ll>A(n + 5, 0); auto B = A;
    for (ll i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] > k) {
            f1 = 0; break;
        }
        B[i] = A[i];
    }
    if (not f1) {
        puts("NO"); return;
    }
    sort(B.begin() + 1, B.begin() + 1 + n);
    ll len = unique(B.begin() + 1, B.begin() + 1 + n) - B.begin() - 1;
    std::unordered_map<ll, ll>ws;
    for (ll i = 1; i <= len; i++)ws[B[i]] = i;
    for (ll i = 1; i <= n; i++)A[i] = ws[A[i]];
    vector<bool>pre(n + 5, 0);
    vector<ll>cnt1(n + 5, 0), cnt2(n + 5, 0);
    pre[0] = 1; ll cur = 0;
    for (ll i = 1; i <= n; i++) {
        cnt1[A[i]]++; if (cnt1[A[i]] == 1)cur++;
        if (i > k) {
            cnt1[A[i - k]]--;
            if (cnt1[A[i - k]] == 0)cur--;
        }
        if (i >= k and cur == k)pre[i] = pre[i - k];
        if (i < k and cur == i)pre[i] = true;
    }
    //枚举分割点
    cur = 0; bool f2 = 0;
    for (ll i = n; i >= max(0ll, n - k); i--) {
        if (pre[i] and cur == n - i) {
            f2 = 1; break;
        }
        cnt2[A[i]]++; if (cnt2[A[i]] == 1)cur++;
    }
    if (f2) {
        puts("YES");
    } else puts("NO");
}
signed main() {
    ll T; std::cin >> T;
    while (T--)
        solve();
}
/**/