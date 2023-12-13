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
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e7 + 500;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
template<typename T>
struct SegmentTree {
  /*动态开点线段树*/
public:

  struct Node {
    i64 l, r; // 所维护的区间范围
    i64 ls, rs;// 左右孩子
    T mul, add, sum;
  };

  std::vector<Node>tr; i64 n; i64 tot = 1;

  SegmentTree(int n): tr(2 * n + 1), n(n) {tr[1].l = 1; tr[1].r = n; tr[1].mul = 1;}

  void pushUp(i64 p) {
    tr[p].sum = (tr[tr[p].ls].sum % mod + tr[tr[p].rs].sum) % mod;
    return;
  }
  void pushDown(i64 p) {
    i64 mid = (tr[p].l + tr[p].r) >> 1;
    if (not tr[p].ls) {
      tr[p].ls = ++tot;
      tr[tot].l = tr[p].l;
      tr[tot].r = mid;
      tr[tr[p].ls].mul = 1;
    }
    if (not tr[p].rs) {
      tr[p].rs = ++tot;
      tr[tot].l = mid + 1;
      tr[tot].r = tr[p].r;
      tr[tr[p].rs].mul = 1;
    }
    if (tr[p].mul != 1) {
      T mu = tr[p].mul;
      tr[p].mul = 1;
      tr[tr[p].ls].mul = tr[tr[p].ls].mul * mu % mod;
      tr[tr[p].rs].mul = (tr[tr[p].rs].mul * mu % mod);
      tr[tr[p].ls].sum = (tr[tr[p].ls].sum % mod * mu) % mod;
      tr[tr[p].rs].sum = (tr[tr[p].rs].sum % mod * mu) % mod;
      tr[tr[p].ls].add = (tr[tr[p].ls].add % mod * mu) % mod;
      tr[tr[p].rs].add = (tr[tr[p].rs].add % mod * mu) % mod;
    }
    if (tr[p].add) {
      T ad = tr[p].add;
      tr[p].add = 0;
      tr[tr[p].ls].add = (tr[tr[p].ls].add + ad) % mod;
      tr[tr[p].rs].add = (tr[tr[p].rs].add + ad) % mod;
      i64 mid = (tr[p].l + tr[p].r) >> 1;
      i64 len1 = mid - tr[p].l + 1; i64 len2 = tr[p].r - mid;
      tr[tr[p].ls].sum = (tr[tr[p].ls].sum % mod + len1 % mod * ad) % mod;
      tr[tr[p].rs].sum = (tr[tr[p].rs].sum % mod + len2 % mod * ad) % mod;
    }
  }
  void modify1(i64 p, i64 l, i64 r, T v) {
    if (tr[p].l >= l and tr[p].r <= r) {
      tr[p].mul = (tr[p].mul % mod * v) % mod;
      tr[p].add = (tr[p].add % mod * v) % mod;
      tr[p].sum = (tr[p].sum % mod * v) % mod;
      return;
    }
    pushDown(p);
    i64 mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid)modify1(tr[p].ls, l, r, v);
    if (r > mid)modify1(tr[p].rs, l, r, v);
    pushUp(p);
  }

  void modify2(i64 p, i64 l, i64 r, T v) {
    if (tr[p].l >= l and tr[p].r <= r) {
      tr[p].add = (tr[p].add % mod + v) % mod;
      tr[p].sum = (tr[p].sum + (tr[p].r - tr[p].l + 1) % mod * v) % mod;
      return;
    }
    pushDown(p);
    i64 mid = (tr[p].l + tr[p].r) >> 1;
    if (l <= mid)modify2(tr[p].ls, l, r, v);
    if (r > mid)modify2(tr[p].rs, l, r, v);
    pushUp(p);
  }

  T query(i64 u, i64 l, i64 r) {
    if (tr[u].l >= l and tr[u].r <= r) {
      return tr[u].sum % mod;
    }
    pushDown(u);
    T ret = 0;
    i64 mid = (tr[u].l + tr[u].r) >> 1;
    if (l <= mid)ret = (ret % mod + query(tr[u].ls, l, r)) % mod;
    if (r > mid)ret = (ret % mod + query(tr[u].rs, l, r)) % mod;
    return ret % mod;
  }

};


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

int main() {
  i64 n, m; std::cin >> n >> m;
  std::vector<i64>a(n + 1);
  SegmentTree<i64>tr(n);
  for (i64 i = 1; i <= n; i ++)std::cin >> a[i], tr.modify2(1, i, i, a[i]);
  for (i64 i = 1; i <= m; i++) {
    i64 l, r, v; std::cin >> l >> r >> v;
    i64 p = inv(r - l + 1) % mod;
    tr.modify1(1, l, r, ((1 - p) % mod + mod) % mod);
    tr.modify2(1, l, r, v % mod * p % mod);
  }
  for (i64 i = 1; i <= n; i++) {
    std::cout << tr.query(1, i, i) % mod << " \n"[i == n];
  }
  return 0;
}
