#include<bits/stdc++.h>
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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
    i64 n, q; cin >> n >> q;
    i64 fa[maxn];
    std::map<i64, i64>v;
    vector<array<i64, 3>>e(q + 1);
    iota(fa + 1, fa + 1 + n, 1);
    for (int i = 1; i <= n; i++)v[i] = 0;
    vector<i64>ans;
    for (int i = 1; i <= q; i++) {
        i64 a, b, s; cin >> a >> b >> s;
        auto find = [&](auto self, i64 x) ->i64 {
            if (x != fa[x]) {
                i64 tmp = self(self, fa[x]);
                v[x] += v[fa[x]];
                fa[x] = tmp;
                return fa[x];
            }
            return x;
        };
        i64 ta = find(find, a), tb = find(find, b);
        if (ta != tb) {
            fa[ta] = tb;
            v[ta] = v[b] - v[a] + s; ans.push_back(i);
        } else if (v[a] - s == v[b]) {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
}
signed main() {
    solve();
}