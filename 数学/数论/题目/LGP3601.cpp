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
const i64 inf = 0x3f3f3f3f3f3f3f3f; bool vis[maxn];
i64 s[maxn], t[maxn], cnt = 0, prime[maxn];
void init() {
    for (i64 i = 2; i <= 1e6; i++) {
        if (not vis[i]) {
            prime[++cnt] = i;
        }
        for (i64 j = 1; j <= cnt and prime[j]*i <= 1e6; j++) {
            vis[prime[j]*i] = true;
            if (i % prime[j] == 0)break;
        }
    }
}
void solve() {
    init();
    i64 l, r; cin >> l >> r;
    for (i64 i = l; i <= r; i++) {
        s[i - l] = i, t[i - l] = i;
    }
    for (i64 i = 1; i <= cnt and prime[i]*prime[i] <= r; i++) {
        i64 p = prime[i];
        for (i64 j = (l + p - 1) / p * p - l; j <= r - l; j += p) {
            s[j] /= p; s[j] *= (p - 1);
            while (t[j] % p == 0) {
                t[j] /= p;
            }
        }
    }
    i64 ans = 0;
    for (i64 i = 0; i <= r - l; i++) {
        if (t[i] != 1) {
            s[i] /= t[i]; s[i] *= (t[i] - 1);
            //  cout << "#" << s[i] << endl;
        }
        ans = (((ans + i + l) % mod - s[i]) % mod + mod) % mod;
    }
    cout << ans << "\n";
}
signed main() {
    solve();
}