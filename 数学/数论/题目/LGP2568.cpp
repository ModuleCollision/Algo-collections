/*筛法求欧拉函数*/

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
const i64 maxn = 1e7 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 prime[maxn], tot = 0; i64 e[maxn];
bool vis[maxn]; i64 n; i64 pre[maxn];

void init() {
    e[1] = 1; pre[1] = e[1];
    for (i64 i = 2; i <= n; i++) {
        if (not vis[i]) {
            prime[++tot] = i; e[i] = i - 1;
        }
        pre[i] = e[i] + pre[i - 1];
        for (i64 j = 1; j <= tot and i * prime[j] <= n; j++) {
            vis[i * prime[j]] = 1;
            e[i * prime[j]] = e[i] * e[prime[j]];
            if (i % prime[j] == 0) {
                e[i * prime[j]] = e[i] * prime[j];
                break;
            }
        }
    }
}
void solve() {
    cin >> n; init(); i64 ans = 0;
    for (i64 i = 1; i <= tot; i++) {
        i64 s = n / prime[i];
        ans += 2 * pre[s] - 1;
    }
    cout << ans << "\n";
}
signed main() {
    solve();
}