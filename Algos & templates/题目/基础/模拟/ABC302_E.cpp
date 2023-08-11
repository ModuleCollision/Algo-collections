#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    ll N, Q; cin >> N >> Q;
    vector<ll>q(Q + 5), u(Q + 5), v(Q + 5);
    for (int i = 1; i <= Q; i++) {
        cin >> q[i];
        if (q[i] == 1) {
            cin >> u[i] >> v[i];
        } else {
            cin >> v[i];
        }
    }
    /*操作离线处理*/
    ll ans = N;
    vector<set<ll>> ren(N + 1);
    vector<ll>cnt(N + 5);
    for (int i = 1; i <= Q; i++) {
        if (q[i] == 1) {
            if (not ren[u[i]].size())ans--;
            if (not ren[v[i]].size())ans--;
            ren[u[i]].insert(v[i]);
            ren[v[i]].insert(u[i]);
            cnt[u[i]]++; cnt[v[i]]++;
            cout << ans << endl;
        } else {
            if (cnt[v[i]]) {
                ans++;
            }
            for (auto t : ren[v[i]]) {
                cnt[t]--;
                if (ren[t].count(v[i]))
                    ren[t].erase(v[i]);
                if (not cnt[t]) {
                    ans++;
                }
            }
            ren[v[i]].clear();
            cnt[v[i]] = 0;

            cout << ans << endl;
        }
    }
}
signed main() {
    solve();
}