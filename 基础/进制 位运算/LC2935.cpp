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
  struct sq {
    int to[2]; int cnt = 0;
  };
  /*支持撤销的 0 1 trie*/
  int maximumStrongPairXor(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<sq>tr;
    auto insert = [&](int x) {
      int u = 0;
      for (int i = 20; i >= 0; i--) {
        int cur = (x >> i) & 1;
        if (not tr[u].to[cur]) {
          tr[u].to[cur] = tr.size();
          tr.push_back(sq());
        }
        u = tr[u].to[cur]; tr[u].cnt ++;
      }
    };
    auto del = [&](int x) {
      int  u = 0;
      for (int i = 20; i >= 0; i --) {
        int cur = ((x >> i) & 1);
        u = tr[u].to[cur]; tr[u].cnt --;
      }
    };
    auto query = [&](int x) {
      int ans = 0, u = 0;
      for (int i = 20; i >= 0; i--) {
        int cur = (x >> i) & 1;
        if (tr[u].to[cur ^ 1] and tr[tr[u].to[cur ^ 1]].cnt) {
          ans |= (1 << i); u = tr[u].to[cur ^ 1];
        } else {
          u = tr[u].to[cur];
        }
      }
      return ans;
    };
    tr.push_back(sq());
    nums.insert(nums.begin(), 0);
    int ans = 0;
    for (int r = 1, l = 1; r <= n; r++) {
      insert(nums[r]);
      while (nums[l] * 2 < nums[r]) {
        del(nums[l]); l++;
      }
      ans = max(ans, query(nums[r]));
    }
    return ans;
  }
};