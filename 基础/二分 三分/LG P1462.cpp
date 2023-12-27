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
constexpr i64 maxn = 3e4 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


struct cmp {
  bool operator()(const std::pair<i64, i64>&x, const std::pair<i64, i64>&y)const {
    return x.second > y.second;
  }
};
std::priority_queue<std::pair<i64, i64>, std::vector<std::pair<i64, i64>>, cmp>q;
i64 f[maxn]; i64 dis[maxn]; bool vis[maxn];
std::vector<std::pair<i64, i64>>g[maxn];
int main() {
  i64 n, m, b; std::cin >> n >> m >> b;
  for (i64 i = 1; i <= n; i++) {
    std::cin >> f[i];
  }
  for (i64 i = 1; i <= m; i++) {
    i64 x, y, z; std::cin >> x >> y >> z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  auto check = [&](i64 x) {
    while (q.size())q.pop();
    std::fill(dis + 1, dis + 1 + n, inf);
    dis[1] = 0;
    if (f[1] > x)return false;
    std::fill(vis + 1, vis + 1 + n, false);
    q.push({1, 0});
    while (q.size()) {
      auto [u, d] = q.top(); q.pop(); vis[u] = true;
      for (auto [v, w] : g[u]) {
        if (f[v] > x)continue; //  ban掉这个点
        if (dis[v] > dis[u] + w) {
          dis[v] = dis[u] + w;
          if (not vis[v]) {
            q.push({dis[v], v});
          }
        }
      }
    }
    return dis[n] <= b;
  };
  i64 ans = -1;
  i64 l = 0, r = 1e15;
  while (l <= r) {
    i64 mid = (l + r) >> 1;
    if (check(mid))r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  if (ans == -1) {
    puts("AFK"); return 0;
  }
  std::cout << ans << "\n";
}