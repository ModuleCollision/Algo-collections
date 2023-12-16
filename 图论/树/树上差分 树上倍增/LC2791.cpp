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
  
  long long countPalindromePaths(vector<int>& parent, string s) {
    std::map< i64, int>cnt;
    std::vector<vector<pair<int, char>>>tr(parent.size() + 5);
    for (int i = 1; i < parent.size(); i++) {
      tr[i].push_back({parent[i], s[i]});
      tr[parent[i]].push_back({i, s[i]});
    }
     i64 res = 0;
    function<void(int, int,  i64)>dfs = [&](int u, int f,  i64 cur) {
      res += cnt[cur];
      for (int i = 0; i < 26; i++) {
        res += cnt[cur ^ (1 << i)];
      }
      cnt[cur]++;
      for (auto [v, c] : tr[u]) {
        if (v == f)continue;
         i64 fs = cur ^ (1 i64 << (c - 'a'));
        dfs(v, u, fs);
      }
    };
    dfs(0, -1, 0 i64);
    return res;
  }
};