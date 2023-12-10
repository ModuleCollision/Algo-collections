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

using namespace std;
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


struct DisjoinSets {

  std::vector<i64>f, v;

  DisjoinSets() {}

  DisjoinSets(int n): f(n + 1), v(n + 1) {init(n);}

  void init(int n) {
    f.assign(n + 1, 0);
    v.assign(n + 1, 0);
    std::iota(f.begin() + 1, f.begin() + 1 + n, 1);
    v.assign(n, 1);
  }
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y)return false;
    v[x] += v[y];
    f[y] = x;
    return true;
  }
  int size(int x) {
    return v[find(x)];
  }
};

void solve() {
  i64 n, m; std::cin >> n >> m;
  std::vector<i64>a(n + 1);
  for (i64 i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  i64 tot = 0;
  std::vector<array<i64, 3>>e(m + 1);
  for (i64 i = 1; i <= m; i++) {
    auto &[u, v, w] = e[i];
    std::cin >> u >> v;
    i64 x = a[u], y = a[v];
    i64 cnt1 = 0, cnt2 = 0;
    while (x % 2 == 0) {
      x /= 2, cnt1++;
    }
    while (y % 2 == 0) {
      y /= 2; cnt1++;
    }
    while (x % 5 == 0) {
      x /= 5; cnt2++;
    }
    while (y % 5 == 0) {
      y /= 5; cnt2++;
    }
    tot += min(cnt1, cnt2);
    w = min(cnt1, cnt2);
  }
  sort(e.begin() + 1, e.begin() + 1 + m, [&](auto s, auto t)->bool{
    return s[2] < t[2];
  });
  DisjoinSets st(n + 1);
  i64 cur = 0; i64 s = 0;
  for (i64 i = 1; i <= m; i++) {
    auto [u, v, w] = e[i];
    if (st.same(u, v))continue;
    st.merge(u, v); s += w;
    cur++;
    if (cur == n - 1)break;
  }
  std::cout << tot - s << "\n";
}

int main() {
  solve();
}

