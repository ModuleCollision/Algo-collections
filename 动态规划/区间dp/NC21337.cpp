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

i64 dp[maxn][maxn]; char s[maxn];
i64 add[30], del[30], trans[30][30], c[30];
void solve() {
    for (i64 i = 0; i < 26; i++) {
        add[i] = del[i] = inf;
        for (i64 j = 0; j < 26; j++) {
            if (i == j) {
                continue;
            }
            trans[i][j] = inf;
        }
    }//Floyd的初始化
    std::cin >> (s + 1); i64 T; std::cin >> T;
    while (T--) {
        string opt;
        std::cin >> opt;
        if (opt == "add") {
            string c; i64 x; std::cin >> c >> x;
            add[c[0] - 'a'] = min(add[c[0] - 'a'], x);
        } else if (opt == "erase") {
            string c; i64 x;
            std::cin >> c >> x;
            del[c[0] - 'a'] = min(del[c[0] - 'a'], x);
        } else {
            string c1, c2; i64 x;
            std::cin >> c1 >> c2 >> x;
            trans[c1[0] - 'a'][c2[0] - 'a'] = min(trans[c1[0] - 'a'][c2[0] - 'a'], x);
        }
    }
    for (i64 k = 0; k < 26; k++) {
        for (i64 i = 0; i < 26; i++) {
            for (i64 j = 0; j < 26; j++) {
                trans[i][j] = min(trans[i][j], trans[i][k] + trans[k][j]);
            }
        }
    }
    for (i64 i = 0; i < 26; i++) {
        c[i] = min(add[i], del[i]);
        for (i64 j = 0; j < 26; j++) {
            c[i] = min(c[i], trans[i][j] + min(add[j], del[j]));
            c[i] = min(c[i], trans[j][i] + add[j]);
            for (i64 k = 0; k < 26; k++) {
                c[i] = min(c[i], trans[i][k] + add[j] + trans[j][k]);
            }
        }//使得子段[i, j]转移到[i + 1, j]的最小代价
    }
    i64 len = strlen(s + 1);
    for (i64 i = 0; i <= len; i++) {
        dp[i][i] = 0; dp[i + 1][i] = 0;
    }//区间dp的初始化
    for (i64 l = 2; l <= len; l++) {
        for (i64 i = 1; i + l - 1 <= len; i++) {
            i64 j = i + l - 1; dp[i][j] = inf;
            if (s[i] == s[j])dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            dp[i][j] = min(dp[i][j], dp[i + 1][j] + c[s[i] - 'a']);
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + c[s[j] - 'a']);
            dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + min(trans[s[i] - 'a'][s[j] - 'a'], trans[s[j] - 'a'][s[i] - 'a']));
            for (i64 k = 0; k < 26; k++) {
                dp[i][j] = min(dp[i][j], dp[i + 1][j - 1] + trans[s[i] - 'a'][k] + trans[s[j] - 'a'][k]);
            }
        }
    }
    if (dp[1][len] == inf) {
        puts("-1");
    } else {
        cout << dp[1][len] << endl;
    }
}
signed main() {
    solve();
}