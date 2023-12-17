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
  i64 ksm(i64 x, i64 y) {
    i64 ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  }
  i64 inv(i64 x) {
    return ksm(x, mod - 2) % mod;
  }
  i64 fac[100005];
  void init() {
    fac[0] = 1;
    for (int i = 1; i <= 1e5; i++)fac[i] = (fac[i - 1] % mod * i) % mod;
  }
  i64 comb(i64 n, i64 m) {
    return fac[n] % mod * inv(fac[n - m] % mod * fac[m] % mod) % mod;
  }
  i64 arrn(i64 n, i64 m) {
    return comb(n, m) % mod * fac[m] % mod;
  }
  int waysToBuildRooms(vector<int>& prevRoom) {
    int n = prevRoom.size();
    vector<vector<int>>tr(n + 1);
    for (int i = 0; i < n; i++) {
      if (i == 0)continue;
      tr[i + 1].push_back(prevRoom[i] + 1);
      tr[prevRoom[i] + 1].push_back(i + 1);
    }
    init();
    vector<i64>sz(n + 1); vector<i64>dp(n + 1, 0);
    function<void(int, int)>dfs = [&](int u, int f) {
      sz[u] = 1;  i64 tot = 0;
      i64 sx = 1; i64 sy = 1;
      for (auto v : tr[u]) {
        if (v == f)continue;
        dfs(v, u);
        sz[u] = (sz[u] % mod + sz[v]) % mod;
        tot = (tot % mod + sz[v]) % mod;
        sx = (sx % mod * fac[sz[v]]) % mod; sy = (sy % mod * dp[v]) % mod;
      }
      dp[u] = (fac[tot] % mod * inv(sx) % mod) % mod * sy % mod;
    };
    dfs(1, 0); return dp[1] % mod;
  }
};