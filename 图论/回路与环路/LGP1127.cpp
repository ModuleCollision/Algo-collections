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
const i64 mod = 666623333;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
/*无向图找欧拉通路 / 欧拉回路*/
void solve() {
    int n; cin >> n; std::vector<std::string>s(n + 1);
    std::vector<int>ind(30), rnd(30);
    for (int i = 1; i <= n; i++) {
        cin >> s[i]; ++ind[s[i][0] - 'a'];
        ++rnd[s[i].back() - 'a'];
    }
    std::vector<vector<int>>g(n + 1);
    std::sort(s.begin() + 1, s.begin() + 1 + n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j and s[i].back() == s[j].front()) {
                g[i].push_back(j);
            }
        }
    }
    std::vector<bool>vis(n + 1);
    std::function<void(int, std::string, int)>dfs = [&](int u, std::string cur, int cnt) {
        if (cnt == n) {
            cur.pop_back();
            cout << cur;
            exit(0);
        }
        for (auto i : g[u]) {
            if (not vis[i]) {
                vis[i] = true;
                dfs(i, cur + s[i] + '.', cnt + 1);
                vis[i] = false;
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (ind[s[i].front() - 'a'] == rnd[s[i].front() - 'a'] + 1) {
            vis[i] = true;
            dfs(i, s[i] + '.', 1);
            vis[i] = false;
        }
    }
    vis[1] = true;
    dfs(1, s[1] + '.', 1);
    vis[1] = false;
}
signed main() {
    solve();
}