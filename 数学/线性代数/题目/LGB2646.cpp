/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

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
constexpr i64 mod = 1145141;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct Matrix {
public:
  i64 n; std::vector<std::vector<i64>>a;
  Matrix(i64 len = 4): n(len), a(len) {
    for (i64 i = 0; i < len; i++) {
      a[i].assign(len, 0);
    }
  }
  friend Matrix operator*(Matrix x, Matrix y) {
    i64 n = x.n;
    Matrix ret(n);
    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < n; j++) {
        for (i64 k = 0; k < n; k++) {
          ret.a[i][j] = (ret.a[i][j] % mod + x.a[i][k] % mod * y.a[k][j] % mod) % mod;
        }
      }
    }
    return ret;
  }
  friend Matrix quickPower(Matrix x, i64 y) {
    Matrix ret(x.n);
    for (i64 i = 0; i < x.n; i++)ret.a[i][i] = 1;
    while (y) {
      if (y & 1)ret = ret * x;
      x = x * x;
      y >>= 1;
    }
    return ret;
  };
};

// 求 伴随阵, 求 行列式, 求逆矩阵

i64 inv(i64 x) {
  i64 ret = 1; i64 b = mod - 2;
  while (b) {
    if (b & 1)ret = ret * x % mod;
    x = x % mod * x % mod;
    b >>= 1;
  }
  return ret % mod;
}


Matrix eval(Matrix k, i64 len) {
  auto s = k;
  if (len == 3) {
    i64 v1 = (k.a[0][0] % mod * (k.a[1][1] % mod * k.a[2][2] % mod - k.a[1][2] % mod * k.a[2][1]) % mod + mod) % mod;
    i64 v2 = (k.a[0][1] % mod * (k.a[1][0] % mod * k.a[2][2] % mod - k.a[1][2] % mod * k.a[2][0]) % mod + mod) % mod;
    i64 v3 = (k.a[0][2] % mod * (k.a[1][0] % mod * k.a[2][1] % mod - k.a[1][1] % mod * k.a[2][0]) % mod + mod) % mod;
    v1 = ((v1 - v2) % mod + mod) % mod;
    v1 = (v1 + v3) % mod;
    for (i64 i = 0; i <= 2; i++) {
      for (i64 j = 0; j <= 2; j++) {
        i64 x = i, y = j;
        i64 x1, x2; i64 y1, y2;
        if (x == 2)x1 = 0, x2 = 1;
        else if (x == 1)x1 = 0, x2 = 2;
        else if (x == 0)x1 = 1, x2 = 2;
        if (y == 2)y1 = 0, y2 = 1;
        else if (y == 1)y1 = 0, y2 = 2;
        else if (y == 0)y1 = 1, y2 = 2;
        i64 v = ((k.a[x1][y1] % mod * k.a[x2][y2] % mod - k.a[x1][y2] % mod * k.a[x2][y1]) % mod + mod) % mod;
        if ((i + j) & 1)v = ((0ll - v) % mod + mod) % mod;
        v = (v % mod * inv(v1) % mod) % mod;
        s.a[j][i] = v % mod;
      }
    }
  } else if (len == 2) {
    i64 v = (s.a[0][0] % mod * s.a[1][1] % mod - s.a[0][1] % mod * s.a[1][0] % mod + mod) % mod;
    s.a[0][0] = k.a[1][1];
    s.a[0][1] = -k.a[0][1];
    s.a[1][0] = -k.a[1][0];
    s.a[1][1] = k.a[0][0];
    for (i64 i = 0; i <= 1; i++) {
      for (i64 j = 0; j <= 1; j++) {
        s.a[i][j] = (s.a[i][j] % mod + mod) % mod;
        s.a[i][j] = (s.a[i][j] % mod * inv(v)) % mod;
      }
    }
  }
  return s;
}
int main() {
  i64 n, k, q; std::cin >> n >> k >> q;
  std::vector<Matrix>p;
  Matrix s(k);
  for (i64 i = 0; i < k; i++)s.a[i][i] = 1;
  p.push_back(s);
  for (i64 i = 0; i < n; i++) {
    for (i64 j = 0; j < k; j++) {
      for (i64 z = 0; z < k; z++) {
        std::cin >> s.a[j][z];
      }
    }
    p.push_back(s);
  }
  auto ix = p;
  //std::cout << ix.size() << "\n";
  for (i64 i = 1; i <= n; i++) {
    p[i] = p[i - 1] * p[i];
  }
  for (i64 i = 0; i <= n; i++) {
    ix[i] = eval(p[i], k);
  }
  i64 ans = 0;
  while (q--) {
    i64 l, r; std::cin >> l >> r;
    auto c = ix[l - 1] * p[r];
    for (i64 i = 0; i <= k - 1; i++) {
      for (i64 j = 0; j <= k - 1; j++) {
        ans ^= c.a[i][j];
      }
    }
  }
  std::cout << ans << "\n";
}

