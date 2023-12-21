/*多组Test下使用封装数据结构, 在函数中开对象,避免暴力清空数组造成时间浪费*/

/*STL: 数据结构 cin cout function类 lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std,避免命名空间污染*/

/*数学先打表, 后对拍, 图论只会暴力就bitset搞*/

/*300兆字节 1- 2 秒*/

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

constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
i64 n, m, seed, vmax;
i64 qpow(i64 x, i64 y, i64 m) {
  i64 ret = 1;
  while (y) {
    if (y & 1)ret = ret * x % m;
    x = x * x % m;
    y >>= 1;
  }
  return ret % m;
}
class ChthollyTree {
public:
  struct Node {
    i64 l, r; mutable i64 val;
    bool operator<(const Node &t)const {
      return l < t.l;
    }
  };
  std::set<Node>st;
  ChthollyTree() {}
  std::set<Node>::iterator split(i64 w) {
    auto it = st.lower_bound({w, 0, 0});
    if (it != st.end() and it->l == w)return it;
    it--;
    i64 l = it->l, r = it->r, v = it->val;
    st.erase(it);
    st.insert({l, w - 1, v});
    st.insert({w, r, v});
    return st.lower_bound({w, 0, 0});
  }
  void build(i64 n, std::vector<i64>a) {
    for (i64 i = 1; i <= n; i++) {
      st.insert({i, i, a[i]});
    }
  }
  void update1(i64 l, i64 r, i64 w) {
    auto y = split(r + 1), x = split(l);
    st.erase(x, y);
    st.insert({l, r, w});
  }
// 区间修改
  void update2(i64 l, i64 r, i64 w) {
    auto y = split(r + 1);
    for (auto it = split(l); it != y; it++) {
      (it->val) += w;
    }
  }
  i64 kth(i64 l, i64 r, i64 w) {
    auto y = split(r + 1);
    std::vector<std::pair<i64, i64>>p;
    for (auto it = split(l); it != y; it++) {
      p.push_back({it->val, it->r - it->l + 1});
    }
    std::sort(p.begin(), p.end());
    for (auto [s, t] : p) {
      w -= t;
      if (w <= 0) {
        return s;
      }

    }
    return 0;
  }
  i64 querySum(i64 l, i64 r, i64 w, i64 m) {
    auto y = split(r + 1);
    i64 ret = 0;
    for (auto it = split(l); it != y; it++) {
      i64 u1 = (it->r - it->l + 1);
      i64 u2 = qpow(it->val, w, m);
      ret += u1 % m * u2 % m;
      ret %= m;
    }
    return ret % m;
  }
};
i64 rnd() {
  i64 ret = seed;
  seed = (seed * 7 + 13) % mod;
  return ret;
}
int main() {
  std::cin >> n >> m >> seed >> vmax;
  ChthollyTree tr;
  std::vector<i64>a(n + 1);
  for (i64 i = 1; i <= n; i++) {
    a[i] = (rnd() % vmax) + 1;
  }
  tr.build(n, a);
  while (m--) {
    i64 opt = (rnd() % 4) + 1;
    i64 l = (rnd() % n) + 1;
    i64 r = (rnd() % n) + 1;
    if (l > r)std::swap(l, r);
    i64 x = 0, y = 0;
    if (opt == 3) {
      x = (rnd() % (r - l + 1)) + 1;

    } else x = (rnd() % vmax) + 1;
    if (opt == 4) {
      y = (rnd() % vmax) + 1;
    }
    if (opt == 1) {
      tr.update2(l, r, x);
    } else if (opt == 2) {
      tr.update1(l, r, x);
    } else if (opt == 3) {
      std::cout << tr.kth(l, r, x) << "\n";
    } else {
      std::cout << tr.querySum(l, r, x, y) << "\n";
    }
  }
  return 0;
}
