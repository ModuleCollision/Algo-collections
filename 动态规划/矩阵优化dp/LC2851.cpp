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
  int numberOfWays(string s, string t, long long k) {
    string p = s + s; string f = t + '#' + p;
    vector<i64>w(f.size() + 1);
    i64 len = f.size();
    for (i64 i = 1; i < len; i++) {
      i64 j = w[i - 1];
      while (j > 0 and f[i] != f[j])j = w[j - 1];
      if (f[i] == f[j])j++;
      w[i] = j;
    }
    i64 c = 0;
    for (i64 i = t.size() + 1; i < f.size() - 1; i++) {
      if (w[i] == t.size())c++;
    }
    cout << c << endl;
    auto mul = [&](vector<vector<i64>>x, vector<vector<i64>>y) {
      vector ret(2, vector<i64>(2, 0));
      for (i64 i = 0; i < 2; i++) {
        for (i64 j = 0; j < 2; j++) {
          i64 v = 0;
          for (i64 k = 0; k < 2; k++) {
            v = (v % mod + x[i][k] % mod * y[k][j] % mod) % mod;
          }
          ret[i][j] = (ret[i][j] % mod + v) % mod;
        }
      }
      return ret;
    };
    auto ksm = [&](vector<vector<i64>>w, i64 b) {
      vector ret(2, vector<i64>(2, 0)); ret[0][0] = 1; ret[1][1] = 1;
      while (b) {
        if (b & 1)ret = mul(w, ret);//次序不能错
        w = mul(w, w);
        b >>= 1;
      }
      return ret;
    };
    vector q(2, vector<i64>(2, 0)); i64 n = s.size();
    q[0][0] = c - 1, q[0][1] = c, q[1][0] = n - c, q[1][1] = n - c - 1;
    auto res = ksm(q, k);
    i64 ans = 0;
    if (s == t)ans = res[0][0];
    else ans = res[0][1];
    return ans % mod;
  }
};