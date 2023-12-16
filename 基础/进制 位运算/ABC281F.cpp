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

struct sq {
    i64 to[2];
}; vector<sq>tr;
void add(i64 x) {
    i64 u = 0;
    for (i64 i = 30; i >= 0; i--) {
        i64 cur = (x >> i) & 1;
        if (not tr[u].to[cur]) {
            tr[u].to[cur] = tr.size();
            tr.push_back(sq());
        }
        u = tr[u].to[cur];
    }
}
void solve() {
    i64 n; cin >> n;
    vector<i64>a(n, 0);
    tr.push_back(sq());
    for (i64 i = 0; i < n; i++)cin >> a[i];
    function<i64(i64, vector<i64>)>dfs = [&](i64 cur, vector<i64>v) {
        if (cur == -1)return 0i64;
        vector<i64>s, t;
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