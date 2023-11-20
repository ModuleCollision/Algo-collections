#include<bits/stdc++.h>
using i8 = signed char;
typedef long long ll;
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
const i64 mod = 9901;
const i64 maxn = 1005;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
/*扩展欧拉定理*/
signed main() {
  i64 a, m; string b;
  cin >> a >> m >> b; reverse(b.begin(), b.end());
  i64 phi = m; i64 x = m;
  for (i64 i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      phi *= (1 - 1 / i);
      while (x % i == 0)x /= i;
    }
  }
  if (x > 1) {
    phi *= (1 - 1 / x);
  }
  auto ksm = [&](i64 x, i64 y) {
    i64 ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % m;
      x = x * x % m;
      y >>= 1;
    }
    return ret % m;
  };
  if (gcd(a, m) == 1) {
    i64 p = 0, cur = 1;
    for (i64 i = 0; i < b.size(); i++) {
      p = (p % phi + (b[i] - '0') % phi * cur) % phi;
      cur = (cur % phi * 10) % phi;
    }
    cout << ksm(a, p) % m;
  } else {
    if (b.size() <= to_string(phi).size()) {
      i64 p = 0, cur = 1;
      for (i64 i = 0; i < b.size(); i++) {
        p = (p + (b[i] - '0') * cur);
        cur = (cur * 10);
      }
      if (p >= phi) {
        p %= phi; p += phi;
      }
      cout << ksm(a, p) % m;
    } else {
      i64 p = 0, cur = 1;
      for (i64 i = 0; i < b.size(); i++) {
        p = (p % phi + (b[i] - '0') % phi * cur) % phi;
        cur = (cur % phi * 10) % phi;
      }
      p %= phi; p += phi;
      cout << ksm(a, p) % m;
    }
  }
}