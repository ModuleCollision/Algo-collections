#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
    ll to[2];
}; vector<sq>tr;
void add(ll x) {
    ll u = 0;
    for (ll i = 30; i >= 0; i--) {
        ll cur = (x >> i) & 1;
        if (not tr[u].to[cur]) {
            tr[u].to[cur] = tr.size();
            tr.push_back(sq());
        }
        u = tr[u].to[cur];
    }
}
void solve() {
    ll n; cin >> n;
    vector<ll>a(n, 0);
    tr.push_back(sq());
    for (ll i = 0; i < n; i++)cin >> a[i];
    function<ll(ll, vector<ll>)>dfs = [&](ll cur, vector<ll>v) {
        if (cur == -1)return 0ll;
        vector<ll>s, t;
        for (auto c : v) {
            if ((c >> cur) & 1)s.push_back(c);
            else t.push_back(c);
        }
        if (not s.size())return dfs(cur - 1, t);
        if (not t.size())return dfs(cur - 1, s);
        return min(dfs(cur - 1, s), dfs(cur - 1, t)) | (1 << cur);
    };
    cout << dfs(30, a) << endl;
}
signed main() {
    solve();
}