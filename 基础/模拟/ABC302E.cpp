#include<bits/extc++.h>

using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    i64 N, Q; cin >> N >> Q;
    vector< i64>q(Q + 5), u(Q + 5), v(Q + 5);
    for (int i = 1; i <= Q; i++) {
        cin >> q[i];
        if (q[i] == 1) {
            cin >> u[i] >> v[i];
        } else {
            cin >> v[i];
        }
    }
    /*操作离线处理*/
    i64 ans = N;
    vector<set< i64>> ren(N + 1);
    vector< i64>cnt(N + 5);
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