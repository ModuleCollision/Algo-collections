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
    i64 n; std::cin >> n;
    vector<array<i64, 3>>A(n + 5);
    std::unordered_map<i64, i64>w;
    std::vector<i64>k;
    for (i64 i = 1; i <= n; i++) {
        std::cin >> A[i][0] >> A[i][1] >> A[i][2];
        std::sort(A[i].begin(), A[i].end());
        k.push_back(A[i][1]);
    }
    std::sort(k.begin(), k.end());
    k.erase(unique(k.begin(), k.end()), k.end());
    std::sort(A.begin() + 1, A.begin() + 1 + n, [&](auto x, auto y)->bool{
        return x[0] < y[0];
    });
    vector<i64>tr(n + 5, inf);
    auto add = [&](i64 idx, i64 v) {
        for ( ; idx <= n; idx += (idx & -idx)) tr[idx] = min(tr[idx], v);
    };
    auto query = [&](i64 idx) {
        i64 ret = inf;
        for (; idx >= 1; idx -= (idx & -idx))ret = min(ret, tr[idx]);
        return ret;
    };
    vector<bool>vis(n + 5, 0);
    for (i64 i = 0; i < k.size(); i++)w[k[i]] = i + 1;
    for (i64 i = 1; i <= n; i++) {
        i64 y = w[A[i][1]], z = A[i][2]; i64 l = i;
        if (query(y - 1) < z) {
            puts("Yes"); return;
        }
        while (i + 1 <= n and A[i + 1][0] == A[i][0]) {
            i++; i64 y = w[A[i][1]], z = A[i][2];
            if (query(y - 1) < z) {
                puts("Yes"); return;
            }
        }
        for (i64 j = l; j <= i; j++) {
            i64 y = w[A[j][1]], z = A[j][2];
            add(y, z);
        }
    }
    puts("No");
}
signed main() {
    solve();
}