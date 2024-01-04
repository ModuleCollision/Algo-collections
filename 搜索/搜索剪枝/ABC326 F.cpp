/*期望dp+状态机模型*/
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
constexpr i64 maxn = 2e2 + 10;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


/*折半搜索 一般在 数据量1 - 40 时使用*/
/*折半搜索 + 双指针*/
int main() {
    i64 n, x, y; std::cin >> n >> x >> y;
    std::array<std::vector<i64>, 2>a;
    for (i64 i = 0; i < n; i++) {
        i64 x; std::cin >> x;
        a[i & 1].push_back(x);
    }
    std::function<void(std::vector<i64>&, i64, i64, i64, i64, i64, std::vector<std::array<i64, 2>>&)>dfs = [&](std::vector<i64>&a,
    i64 pos, i64 sum, i64 msk, i64 l, i64 r, std::vector<std::array<i64, 2>>&tmp) {
        if (pos + l == r) {
            tmp.push_back({sum, msk});
            return;
        }
        dfs(a, pos + 1, sum + a[pos + l], msk, l, r, tmp);
        dfs(a, pos + 1, sum - a[pos + l], msk | (1 << pos), l, r, tmp);
    };
    auto solve = [&](vector<i64>&a, i64 val) {
        i64 mid = a.size() / 2;
        std::vector<std::array<i64, 2>>l, r;
        dfs(a, 0, 0, 0, 0, mid, l);
        dfs(a, 0, 0, 0, mid, a.size(), r);
        std::vector<i64>lid(l.size()), rid(r.size());
        iota(lid.begin(), lid.end(), 0);
        iota(rid.begin(), rid.end(), 0);
        std::sort(lid.begin(), lid.end(), [&](i64 x, i64 y) {
            return l[x][0] < l[y][0];
        });
        std::sort(rid.begin(), rid.end(), [&](i64 x, i64 y) {
            return r[x][0] > r[y][0];
        });
        auto lp = lid.begin(), rp = rid.begin();
        while (lp != lid.end() and rp != rid.end()) {
            if (l[*lp][0] + r[*rp][0] == val) {
                return l[*lp][1] + ((1ll * r[*rp][1]) << mid);
            } else if (l[*lp][0] + r[*rp][0] < val) {
                lp = next(lp);
            } else if (l[*lp][0] + r[*rp][0] > val) {
                rp = next(rp);
            }
        }
        return -1ll;
    };
    auto dy = solve(a[0], y);
    auto dx = solve(a[1], x);
    if (dx == -1 or dy == -1) {
        puts("No"); return 0;
    } else {
        puts("Yes");
        std::vector<i64>ans;
        for (i64 i = 0; i < n / 2; i++) {
            ans.push_back((dy >> i) & 1);
            if (i < n / 2) {
                ans.push_back((dx >> i) & 1);
            }
        }
        int dir = 0;
        for (i64 i = 0; i < n; i++) {
            std::cout << "LR"[ans[i] ^ dir ^ (i & 1)];
            dir = ans[i];
        }
        std::cout << "\n";
        return 0;
    }
}

