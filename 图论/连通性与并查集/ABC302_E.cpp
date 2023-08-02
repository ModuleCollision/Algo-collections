#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
    int N, Q;
    cin >> N >> Q;
    int q[Q], u[Q], v[Q];
    for (int i = 0; i < Q; i++) {
        cin >> q[i];
        if (q[i] == 1) {
            cin >> u[i] >> v[i];
            u[i]--;
            v[i]--;
        } else {
            cin >> v[i];
            v[i]--;
        }
    }

    int ans = N;
    vector<set<int>> ren(N);
    int cnt[N];
    for (int i = 0; i < N; i++) {
        cnt[i] = 0;
    }
    for (int i = 0; i < Q; i++) {
        if (q[i] == 1) {
            if (ren[u[i]].size() == 0) {
                ans--;
            }
            if (ren[v[i]].size() == 0) {
                ans--;
            }
            ren[u[i]].insert(v[i]);
            ren[v[i]].insert(u[i]);
            cnt[u[i]]++;
            cnt[v[i]]++;

            cout << ans << endl;
        } else {
            if (cnt[v[i]] != 0) {
                ans++;
            }
            auto itr = ren[v[i]].begin();
            while (itr != ren[v[i]].end()) {
                if (ren[*itr].count(v[i])) {
                    cnt[*itr]--;
                    if (cnt[*itr] == 0) {
                        ans++;
                        ren[*itr].clear();
                    }
                }
                itr++;
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