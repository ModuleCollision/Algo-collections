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
    i64 n, k; std::cin >> n >> k; bool f1 = 1;
    vector<i64>A(n + 5, 0); auto B = A;
    for (i64 i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] > k) {
            f1 = 0; break;
        }
        B[i] = A[i];
    }
    if (not f1) {
        puts("NO"); return;
    }
    sort(B.begin() + 1, B.begin() + 1 + n);
    i64 len = unique(B.begin() + 1, B.begin() + 1 + n) - B.begin() - 1;
    std::unordered_map<i64, i64>ws;
    for (i64 i = 1; i <= len; i++)ws[B[i]] = i;
    for (i64 i = 1; i <= n; i++)A[i] = ws[A[i]];
    vector<bool>pre(n + 5, 0);
    vector<i64>cnt1(n + 5, 0), cnt2(n + 5, 0);
    pre[0] = 1; i64 cur = 0;
    for (i64 i = 1; i <= n; i++) {
        cnt1[A[i]]++; if (cnt1[A[i]] == 1)cur++;
        if (i > k) {
            cnt1[A[i - k]]--;
            if (cnt1[A[i - k]] == 0)cur--;
        }
        if (i >= k and cur == k)pre[i] = pre[i - k];
        if (i < k and cur == i)pre[i] = true;
    }
    //枚举分割点
    cur = 0; bool f2 = 0;
    for (i64 i = n; i >= max(0i64, n - k); i--) {
        if (pre[i] and cur == n - i) {
            f2 = 1; break;
        }
        cnt2[A[i]]++; if (cnt2[A[i]] == 1)cur++;
    }
    if (f2) {
        puts("YES");
    } else puts("NO");
}
signed main() {
    i64 T; std::cin >> T;
    while (T--)
        solve();
}
/**/