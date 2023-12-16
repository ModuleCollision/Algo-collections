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
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e5 + 10;
class Solution {
public:

    int tot = 0;
    int tr[maxn][30]; int fail[maxn];
    int minlen[maxn];
    const int inf = 0x3f3f3f3f;
    int longestValidSubstring(string word, vector<string>& forbidden) {
        memset(minlen, 0x3f, sizeof(minlen));
        auto add = [&](string s) {
            int u = 0; int len = s.size();
            for (int i = 0; i < len; i++) {
                int cur = s[i] - 'a';
                if (not tr[u][cur]) {
                    tr[u][cur] = ++tot;
                    minlen[tot] = inf;
                }
                u = tr[u][cur];
            }
            minlen[u] = min(minlen[u], len);
        };
        auto getfail = [&]() {
            queue<int>q;
            for (int i = 0; i < 26; i++)if (tr[0][i])q.push(tr[0][i]);
            while (q.size()) {
                int cur = q.front(); q.pop();
                for (int i = 0; i < 26; i++) {
                    if (tr[cur][i]) {
                        fail[tr[cur][i]] = tr[fail[cur]][i];
                        q.push(tr[cur][i]);
                        minlen[tr[cur][i]] = min(minlen[tr[cur][i]], minlen[fail[tr[cur][i]]]);
                    } else {
                        tr[cur][i] = tr[fail[cur]][i];
                    }
                }
            }
        };
        for (auto s : forbidden)add(s);
        getfail();
        int cur = 0, ans = 0, u = 0; int n = word.size();
        for (int i = 0; i < n; i++) {
            u = tr[u][word[i] - 'a'];
            cur = max(cur, i - minlen[u] + 2);
            ans = max(ans, i - cur + 1);
        }
        return ans;
    }
};