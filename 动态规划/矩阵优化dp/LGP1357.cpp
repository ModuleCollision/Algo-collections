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
  i64 n, m, k; cin >> n >> m >> k;
  vector<i64>p;
  auto count = [&](i64 i) {
    i64 ret = 0;
    for (i64 j = 0; j < m; j++) {
      if ((i >> j) & 1)ret++;
    }
    return ret;
  };
  for (i64 i = 0; i < (1 << m); i++) {
    if (count(i) <= k) {
      p.push_back(i);
      //cout << i << "\n";
    }
  }
  i64 q = p.size();
  auto check = [&](i64 s, i64 t) {
    if ((s >> (m - 1)) & 1)s -= (1 << (m - 1));
    return s == ((t >> 1));
  };
  vector ret(q, vector<i64>(q, 0)); auto w = ret;
  for (i64 i = 0; i < q; i++) {
    for (i64 j = 0; j < q; j++) {
      if (check(p[i], p[j])) {
        w[j][i] = 1;
      }
    }
  }
  auto mul = [&](vector<vector<i64>>&x, vector<vector<i64>>&y) {
    vector r(q, vector<i64>(q, 0));
    for (int i = 0; i < q; i++) {
      for (int j = 0; j < q; j++) {
        i64 v = 0;
        for (int k = 0; k < q; k++) {
          v = (v % mod + x[i][k] % mod * y[k][j] % mod) % mod;
        }
        r[i][j] = v % mod;
      }
    }
    return r;
  };
  auto mat_ksm = [&](i64 y) {
    auto c = ret;
    auto ww = w;
    while (y) {
      if (y & 1)c = mul(ww, c);
      ww = mul(ww, ww);
      y >>= 1;
    }
    return c;
  };
  i64 ans = 0;
  for (i64 i = 0; i < q; i++) {
    ret[i][0] = 1;
    auto f = mat_ksm(n);
    ans = (ans % mod + f[i][0]) % mod;
    ret[i][0] = 0;
  }
  cout << ans << "\n";
}
signed main() {
  solve();
}