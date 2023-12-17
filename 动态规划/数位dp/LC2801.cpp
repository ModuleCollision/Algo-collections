
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
class Solution {
public:


    int countSteppingNumbers(string low, string high) {
        auto cal = [&] (string & s) {
            i64 n = s.size();
            i64 dp[n + 5][10]; memset(dp, -1, sizeof(dp));
            function<i64(i64, i64, bool, bool)>dfs = [&](i64 idx, i64 pre, bool isnum, bool islimit) {
                if (idx == n) {
                    return (i64)isnum;
                }
                if ((not islimit) and isnum and dp[idx][pre] != -1)return dp[idx][pre];
                i64 res = 0;
                if (not isnum)res = (res % mod + dfs(idx + 1, pre, false, false)) % mod;
                i64 low = isnum ? 0 : 1; i64 up = islimit ? s[idx] - '0' : 9;
                for (i64 d = low; d <= up; d++) {
                    if ((not isnum) or abs(d - pre) == 1) {
                        res = (res % mod + dfs(idx + 1, d, true, d == up and islimit)) % mod;
                    }
                }
                if (not islimit and isnum)dp[idx][pre] = res % mod;
                return res % mod;
            };
            return dfs(0, 0, false, true);
        };
        auto valid = [&](string s) {
            for (int i = 1; i < s.size(); i++) {
                if (abs((int)s[i] - (int)s[i - 1]) != 1)return false;
            }
            return true;
        };
        return (int)((cal(high) - cal(low)) % mod + mod + valid(low)) % mod;
    }
};


class Solution {
public:

    i64 dp[1005][15];
    int countSteppingNumbers(string low, string high) {
        for (i64 i = 0; i <= 9; i++)dp[1][i] = 1;
        for (i64 i = 2; i <= 100; i++) {
            for (i64 j = 0; j <= 9; j++) {
                for (i64 k = 0; k <= 9; k++) {
                    if (abs(k - j) == 1)dp[i][j] = (dp[i][j] % mod + dp[i - 1][k]) % mod;
                }
            }
        }
        i64 pre = 1;
        for (i64 i = low.size() - 1; i >= 0; i--) {
            i64 cur = low[i] - '0';
            cur -= pre; bool f = 1;
            if (cur < 0)cur = (cur + 10) % 10, pre = 1, f = 0;
            low[i] = cur + '0';
            if (f)break;
        }
        reverse(low.begin(), low.end());
        while (low.back() == '0')low.pop_back();
        reverse(low.begin(), low.end());
        cout << low << endl;
        auto cal = [&](string t) {
            reverse(t.begin(), t.end());
            i64 res = 0; i64 pre = -10; i64 len = t.size() - 1;
            for (i64 i = len; i >= 0; i--) {
                i64 cur = t[i] - '0';
                for (i64 j = (i == len); j < cur; j++) {
                    if ((abs(j - pre) == 1) or i == len)res = (res % mod + dp[i + 1][j]) % mod;
                }
                if (abs(cur - pre) != 1 and pre != -10)break;
                pre = cur;
                if (not i)res++;
            }
            for (i64 i = 1; i <= len; i++) {
                for (i64 j = 1; j <= 9; j++) {
                    res = (res % mod + dp[i][j]) % mod;
                }
            }
            return res % mod;
        };
        i64 ans = (cal(high) - cal(low) % mod + mod) % mod;
        return (int)ans;
    }
};


