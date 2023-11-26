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
class Solution {
public:
  int findMaximumLength(vector<int>& nums) {
    int n = nums.size();
    vector<i64>p(n + 5);
    for (i64 i = 0; i < n; i++) {
      p[i + 1] = nums[i] + p[i];
    }
    vector<i64>val(n + 5), dp(n + 5);
    vector<pair<i64, i64>>w;
    for (i64 i = 1; i <= n; i++) {
      dp[i] = 1; val[i] = p[i] - p[i - 1];
      i64 idx = lower_bound(w.begin(), w.end(), p[i], [&](pair<i64, i64>x, i64 y)->bool{
        return x.first <= y;
      }) - w.begin() - 1;
      if (idx >= 0 and idx < w.size() and w[idx].first <= p[i]) {
        dp[i] = max(dp[i], dp[w[idx].second] + 1);
        val[i] = max(val[i], p[i] - p[w[idx].second]);
      }
      while (w.size() and w.back().first >= val[i] + p[i]) {
        w.pop_back();
      }
      w.push_back({val[i] + p[i], i});
    }
    return dp[n];
  }
};