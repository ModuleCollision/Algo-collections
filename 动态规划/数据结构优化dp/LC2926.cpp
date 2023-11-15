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
  i64 tr[maxn];
  void add(i64 idx, i64 v) {
    for (; idx <= 1e5; idx += (idx & -idx))tr[idx] = max(tr[idx], v);
  }
  i64 query(i64 idx) {
    i64 ret = 0;
    for (; idx >= 1; idx -= (idx & -idx))ret = max(ret, tr[idx]);
    return ret;
  }
  long long maxBalancedSubsequenceSum(vector<int>& nums) {
    int n = nums.size();
    vector<i64>p;
    for (i64 i = 0; i < n; i++) {
      p.push_back(nums[i] - i);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    std::unordered_map<i64, i64>w;
    for (int i = 0; i < p.size(); i++) {
      w[p[i]] = i + 1;
    }
    memset(tr, -0x3f, sizeof(tr));
    i64 ans = -inf;
    for (i64 i = 1; i <= n; i++) {
      i64 cur = nums[i - 1] - (i - 1);
      i64 f = query(w[cur]) + nums[i - 1];
      ans = max(ans, f);
      add(w[cur], f);
    }
    return ans;
  }
};