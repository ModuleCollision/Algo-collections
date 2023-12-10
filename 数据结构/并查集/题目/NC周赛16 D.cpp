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


struct DisjoinSet {

public:
  std::vector<i64>f, v;

  DisjoinSet() {}

  DisjoinSet(int n) {init(n);}

  void init(int n) {
    f.assign(n + 1, 0);
    v.assign(n + 1, 1);
    std::iota(f.begin() + 1, f.begin() + 1 + n, 1);
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
  DisjoinSet st(n + 1);
  std::vector<std::array<i64, 5>>e(m + 1);
  std::vector<i64>ans;
  for (i64 i = 1; i <= m; i++) {
    i64 u, v, w, p; std::cin >> u >> v >> w >> p;
    if (u > v)swap(u, v);
    e[i] = {u, v, w, p, i};
    if (p) {
      st.merge(u, v);
      ans.push_back(i);
    }
  }
  if (st.size(1) == n) {
    std::cout << ans.size() << "\n";
    for (i64 i = 0; i < ans.size(); i++) {
      std::cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return;
  }
  std::unordered_set<i64>t;
  for (i64 i = 1; i <= n; i++) {
    t.insert(st.find(i));
  }
  i64 sz = t.size();// 此时的连通块数量
  i64 cnt = 0;
  std::sort(e.begin() + 1, e.begin() + 1 + m, [&](auto s, auto x)->bool{
    return s[2] < x[2];
  });
  bool f = false;
  for (i64 i = 1; i <= m; i++) {
    auto [u, v, w, p, z] = e[i];
    if (p)continue;
    u = st.find(u), v = st.find(v);
    if (st.same(u, v))continue;
    st.merge(u, v); ans.push_back(z); cnt++; if (cnt == sz - 1) {
      f = true; break;
    }
  }
  if (st.size(1) != n) {

    puts("-1"); return;
  }
  std::sort(ans.begin(), ans.end());
  std::cout << ans.size() << "\n";
  for (i64 i = 0; i < ans.size(); i++) {
    std::cout << ans[i] << " \n"[i == ans.size() - 1];
  }
}

int main() {
  solve();
}

