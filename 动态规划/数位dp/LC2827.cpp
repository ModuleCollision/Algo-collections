
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
  int numberOfBeautifulIntegers(int low, int high, int k) {
    auto cal = [&](int x) {
      std::map<array<int, 3>, int>dp;
      string s = to_string(x); int m = s.size();
      function<int(int, int, int, bool, bool)>dfs = [&](int idx, int val, int diff, bool isnum, bool islimit) {
        if (idx == m) {
          return (int)(isnum and val == 0 and diff == 0);
        }
        if (not islimit and isnum and dp.count({idx, val, diff}))return dp[ {idx, val, diff}];
        int res = 0;
        if (not isnum)res += dfs(idx + 1, val, diff, false, false);
        int low = isnum ? 0 : 1;
        int up = islimit ? s[idx] - '0' : 9;
        for (int d = low; d <= up; d++) {
          int diff2 = diff;
          if (d & 1)diff2 += 1; else diff2 -= 1;
          res += dfs(idx + 1, (val * 10 + d) % k, diff2, true, islimit and d == up);
        }
        if (not islimit and isnum)dp[ {idx, val, diff}] = res;
        return res;
      };
      return dfs(0, 0, 0, false, true);
    };
    return cal(high) - cal(low - 1);
  }
};

class Solution {
public:

  int numberOfBeautifulIntegers(int low, int high, int k) {
    int dp[11][11][11][k];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= 9; i++) {
      if (i & 1)dp[1][1][i][i % k]++;
      else dp[1][0][i][i % k]++;
    }
    for (int i = 2; i <= 9; i++) {
      for (int j = 0; j <= i; j++) {
        for (int s = 0; s <= 9; s++) {
          if (s & 1) {
            if (j >= 1) {
              for (int w = 0; w <= 9; w++) {
                for (int q = 0; q < k; q++) {
                  dp[i][j][s][(q + s) % k] += dp[i - 1][j - 1][w][q];
                }
              }
            }
          } else {
            for (int w = 0; w <= 9; w++) {
              for (int q = 0; q < k; q++)dp[i][j][s][(q + s) % k] += dp[i - 1][j][w][q];
            }
          }
        }
      }
    }
    auto cal = [&](int x) {
      vector<int>num;
      num.push_back(0);
      while (x) {
        num.push_back(x % 10); x /= 10;
      }
      int ret = 0;
      int len = num.size() - 1;
      int cnt1 = 0, cnt2 = 0; int ps = len / 2;
      if (len % 2 == 0) {
        for (int i = len; i >= 1; i--) {
          int cur = num[i];
          for (int j = (i == len); j < cur; j++) {
            ret += dp[i][ps - cnt2][j][0];
          }
          if (cur & 1)cnt2++;
          if (cnt2 > ps)break;
          if (cnt2 == ps and i == 1)ret++;
        }
      }
      for (int i = 1; i <= len - 1; i++) {
        for (int j = 1; j <= 9; j++) {
          if (i % 2 == 0)ret += dp[i][i / 2][j][0];
        }
      }
      return ret;
    };
    return cal(high) - cal(low - 1);
  }
};


