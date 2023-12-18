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
using namespace std;
constexpr i64 mod = 1e9 + 7;
constexpr i64 maxn = 1e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
int dfn[maxn], low[maxn], cnt, res;
bool vis[maxn], flag[maxn];
int n, m;
std::vector<std::vector<i64>>g;
void solve() {
  std::cin >> n >> m; g.resize(n + 1);
  std::function<void(int , int)>tarjan = [&](int u, int f) {
    vis[u] = true;
    low[u] = dfn[u] = ++cnt;
    int child = 0;
    for (auto v : g[u]) {
      if (not vis[v]) {
        child++; tarjan(v, u);
        low[u] = min(low[u], low[v]);
        if (u != f and low[v] >= dfn[u] and not flag[u]) {
          flag[u] = true; res++;
        }
      } else if (v != f) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (u == f and child >= 2 and not flag[u]) {
      flag[u] = true; res++;
    }
  };
  for (int i = 1; i <= m; i++) {
    int u, v; std::cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (not vis[i]) {
      cnt = 0; tarjan(i, i);
    }
  }
  std::cout << res << "\n";
  for (int i = 1; i <= n; i++) {
    if (flag[i])std::cout << i << " \n"[i == n];
  }
}

int main() {
  solve();
}

/*求无向图割点*/