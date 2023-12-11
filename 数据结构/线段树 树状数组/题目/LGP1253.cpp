/*多组Test尽量封装, 在函数中开对象,避免暴力清空数组造成时间浪费*/
/*STL数据结构 (cin cout function类) lowerbound builtin max min accumulate iota stoi atoi等函数需要加上std*/
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
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 1e10;


template<typename T>
struct SegmentTree {

public:

  struct Node {
    int l; int r; T mx; T add;
    T c;
  };

  std::vector<Node>tr; int n;

  SegmentTree(int n): tr(4 * n + 10), n(n) {}

  void pushUp(int p) {
    tr[p].mx = std::max(tr[p << 1].mx, tr[p << 1 | 1].mx);
  }

  void build(int p, int l, int r, std::vector<T>&a) {
    tr[p].l = l; tr[p].r = r; tr[p].c = -inf;
    if (l == r) {
      tr[p].mx = a[l];
      return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid, a);
    build(p << 1 | 1, mid + 1, r, a);
    pushUp(p);
  }

  void pushDown(int p) {
    if (tr[p].c != -inf) {
      T c = tr[p].c; tr[p].c = -inf;
      tr[p << 1].mx = c; tr[p << 1 | 1].mx = c;
      tr[p << 1].add = 0; tr[p << 1 | 1].add = 0;
      tr[p << 1].c = c; tr[p << 1 | 1].c = c;
    }
    if (tr[p].add) {
      T add = tr[p].add; tr[p].add = 0;
      tr[p << 1].add += add; tr[p << 1 | 1].add += add;
      tr[p << 1].mx += add; tr[p << 1 | 1].mx += add;
    }
  }

  void modify1(int p, int l, int r, T val) { // 修改为 x
    if (tr[p].l >= l and tr[p].r <= r) {
      tr[p].mx = val; tr[p].add = 0;
      tr[p].c = val;
      return;
    }
    pushDown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (r > mid) {
      modify1(p << 1 | 1, l, r, val);
    }
    if (l <= mid) {
      modify1(p << 1, l, r, val);
    }
    pushUp(p);
  }

  void modify2(int p, int l, int r, T val) { // 修改为 x
    if (tr[p].l >= l and tr[p].r <= r) {
      tr[p].mx += val; tr[p].add += val;
      return;
    }
    pushDown(p);
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (r > mid) {
      modify2(p << 1 | 1, l, r, val);
    }
    if (l <= mid) {
      modify2(p << 1, l, r, val);
    }
    pushUp(p);
  }


  T query(int p, int l, int r) {
    if (tr[p].l >= l and tr[p].r <= r) {
      return tr[p].mx;
    }
    pushDown(p);
    T ret = 0; int mid = (tr[p].l + tr[p].r) >> 1;
    if (r > mid) {
      ret = std::max(ret, query(p << 1 | 1, l, r));
    }
    if (l <= mid) {
      ret = std::max(ret, query(p << 1, l, r));
    }
    return ret;
  }

};
int main() {
  int n, q; std::cin >> n >> q;
  SegmentTree<i64>t(n);
  std::vector<i64>a(n + 1);
  for (int i = 1; i <= n; i++)std::cin >> a[i];
  t.build(1, 1, n, a);
  while (q--) {
    int opt; std::cin >> opt;
    if (opt == 1) {
      i64 l, r, x; std::cin >> l >> r >> x;
      t.modify1(1, l, r, x);
    } else if (opt == 2) {
      i64 l, r, x; std::cin >> l >> r >> x;
      t.modify2(1, l, r, x);
    } else {
      i64 l, r; std::cin >> l >> r;
      std::cout << t.query(1, l, r) << "\n";
    }
  }
}

