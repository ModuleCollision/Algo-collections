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
    i64 n; cin >> n;
    vector<i64>w(n + 1);
    vector<vector<i64>>g(n + 1);
    for (i64 i = 1; i <= n - 1; i++) {
        i64 u, v; cin >> u >> v;
        g[u].push_back(v); g[v].push_back(u);
    }
    for (i64 i = 1; i <= n; i++)cin >> w[i];

    i64 s = 2; i64 y = 10005, inv = 1;
    while (y) {
        if (y & 1)inv = inv * s % 10007;
        s = s * s % 10007;
        y >>= 1;
    }
    vector<i64>fa(n + 1);
    i64 a2 = 0; i64 ans = 0;
    std::set<i64>st;
    function<void(i64, i64)>dfs = [&](i64 u, i64 f) {
        fa[u] = f;
        i64 k = fa[fa[u]];
        if (k) {
            ans = max(ans, w[k] * w[u]);
            a2 = (a2 % 10007 + w[k] % 10007 * w[u] % 10007) % 10007;
        }
        st.clear(); i64 tot = 0;
        for (auto v : g[u]) {
            if (v == f)continue;
            if (st.size()) {
                ans = max(ans, w[v] * (*(--st.end())));
                a2 = (a2 % 10007 + w[v] % 10007 * tot) % 10007;
            }
            st.insert(w[v]); tot = (tot % 10007 + w[v]) % 10007;
        }
        for (auto v : g[u]) {
            if (v == f)continue;
            dfs(v, u);
        }
    };
    dfs(1, 0);
    cout << ans << " " << a2 % 10007 * 2 % 10007;
}
int main() {
    solve();
}