/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 3e4 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

/*有向图带权并查集*/
struct DisjoinSet {

public:
    std::vector<i64>f, v;

    DisjoinSet() {}

    DisjoinSet(int n) {init(n);}

    void init(int n) {
        f.assign(n + 1, 0);
        v.assign(n + 1, 0);
        std::iota(f.begin() + 1, f.begin() + 1 + n, 1);
    }
    int find(int x) {
        if (x != f[x]) {
            i64 tmp = find(f[x]);
            v[x] += v[f[x]];
            f[x] = tmp;
            return f[x];
        }
        return x;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    bool merge(int a, int b, int s) {
        i64 ta = find(a), tb = find(b);
        if (ta != tb) {
            f[ta] = tb;
            v[ta] = v[b] - v[a] + s; return true;
        } else if (v[a] - s == v[b]) {
            return true;
        } else {
            return false;
        }
    }
    int size(int x) {
        return v[find(x)];
    }
};


int main() {
    i64 n, q; std::cin >> n >> q;
    std::vector<std::array<i64, 3>>e(q + 1);
    DisjoinSet st(n);
    std::vector<i64>ans;
    for (int i = 1; i <= q; i++) {
        i64 a, b, s; std::cin >> a >> b >> s;
        if (st.merge(a, b, s)) {
            ans.push_back(i);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}