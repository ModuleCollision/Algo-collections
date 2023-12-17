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
  int maxSumMinProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int>q(4 * n + 5); int hed = 1, tal = 0;
    nums.insert(nums.begin(), 0);
    cout << nums[0] << endl;
    vector<int>lt(n + 1, 0), rt(n + 1, 0);
    for (int i = 1; i <= n; i++)lt[i] = 0;
    for (int i = 1; i <= n; i++)rt[i] = n + 1;
    for (int i = 1; i <= n; i++) {
      while (hed <= tal and nums[q[tal]] > nums[i]) {
        rt[q[tal]] = i;
        tal--;
      }
      q[++tal] = i;
    }
    hed = 1, tal = 0;
    for (int i = n; i >= 1; i--) {
      while (hed <= tal and nums[q[tal]] > nums[i]) {
        lt[q[tal]] = i;
        tal--;
      }
      q[++tal] = i;
    }
    i64 ans = 0;
    vector<i64>pre(n + 1, 0);
    for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + nums[i];
    for (int i = 1; i <= n; i++) {
      i64 cur = nums[i];
      i64 d = pre[rt[i] - 1] - pre[lt[i]];
      cur *= d;
      ans = max(ans, cur);
    }
    ans %= mod;
    return int(ans);
  }
};