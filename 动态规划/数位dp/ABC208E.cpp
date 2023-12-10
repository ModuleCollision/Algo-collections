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
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
  i64 n, k; cin >> n >> k;
  auto cal = [&](i64 x) {
    std::map<pair<i64, i64>, i64>dp;
    string s = to_string(x); i64 m = s.size();
    auto dfs = [&](auto self, i64 idx, i64 val, bool isnum, bool islimit)->i64 {
      if (idx == m) {
        return (i64)(isnum and val <= k);
      }
      if (not islimit and isnum and dp.count({idx, val})) {
        return dp[ {idx, val}];
      }
      i64 res = 0;
      if (not isnum)res += self(self, idx + 1, val, false, false);
      i64 low = isnum ? 0 : 1;
      i64 up = islimit ? s[idx] - '0' : 9;
      for (i64 d = low; d <= up; d++) {
        //if (d * val <= k) {
        res += self(self, idx + 1, val * d, true, islimit and d == up);
        //}
      }
      if (not islimit and isnum)dp[{idx, val}] = res;
      return res;
    };
    return dfs(dfs, 0, 1, false, true);
  };
  cout << cal(n) << "\n";
}
signed main() {
  solve();
}