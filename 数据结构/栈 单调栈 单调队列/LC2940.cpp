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
const i64 mod = 998244353;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
  //单调递减栈
  vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size(); int q = queries.size();
    vector<int>ans(q);
    vector<pair<int, int>>stk;//值单调减
    vector<vector<pair<int, int>>>fq(n);
    for (int i = 0; i < q; i++) {
      int a = queries[i][1], b = queries[i][0];
      if (b < a)swap(a, b);
      fq[b].push_back({a, i});
    }
    for (int i = n - 1; i >= 0; i--) {

      if (fq[i].size()) {
        int b = i;
        for (auto [a, idx] : fq[i]) {
          if (heights[a] < heights[b]) {
            ans[idx] = b; continue;
          }
          if ( a == b) {
            ans[idx] = a; continue;
          }
          int id = lower_bound(stk.begin(), stk.end(), heights[a], [&](auto s, int  t)-> bool {
            return s.first > t;
          }) - stk.begin() - 1;
          if (id < stk.size()) {
            ans[idx] = stk[id].second;
          } else {
            ans[idx] = -1;
          }
        }
      }
      while (stk.size() and stk.back().first <= heights[i]) {
        stk.pop_back();
      }
      stk.push_back({heights[i], i});
    }
    return ans;
  }
};



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
const i64 mod = 998244353;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
class Solution {
public:
  //单调递减栈
  vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
    int n = heights.size(); int q = queries.size();
    vector<int>ans(q);
    vector<pair<int, int>>stk;//值单调减
    vector<vector<pair<int, int>>>fq(n);
    for (int i = 0; i < q; i++) {
      int a = queries[i][1], b = queries[i][0];
      if (b < a)swap(a, b);
      fq[b].push_back({a, i});
    }
    for (int i = n - 1; i >= 0; i--) {

      if (fq[i].size()) {
        int b = i;
        for (auto [a, idx] : fq[i]) {
          if (heights[a] < heights[b]) {
            ans[idx] = b; continue;
          }
          if ( a == b) {
            ans[idx] = a; continue;
          }
          int l = 0, r = stk.size() - 1;
          int id = -1;
          while (l <= r) {
            int mid = (l + r) >> 1;
            if (stk[mid].first > heights[a]) {
              l = mid + 1; id = mid;
            } else {
              r = mid - 1;
            }
          }
          if (id != -1) {
            ans[idx] = stk[id].second;
          } else {
            ans[idx] = -1;
          }
        }
      }
      while (stk.size() and stk.back().first <= heights[i]) {
        stk.pop_back();
      }
      stk.push_back({heights[i], i});
    }
    return ans;
  }
};