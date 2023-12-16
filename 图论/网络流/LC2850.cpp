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
using namespace std;

constexpr i64 mod = 998244353;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;


const int maxn = 1e3 + 5;
class Solution {
public:
  struct edge {
    int v; int cap; int flow; int c; int nx;
  } e[maxn];
  int head[maxn]; int cur[maxn]; int dis[maxn]; bool vis[maxn];
  int minimumMoves(vector<vector<int>>& grid) {
    std::fill(head + 1, head + 12, -1); int cnt = 0;
    auto add_edge = [&](int u, int v, int w, int c) {
      e[cnt].flow = 0;
      e[cnt].v = v; e[cnt].cap = w; e[cnt].c = c; e[cnt].nx = head[u];
      head[u] = cnt++;
    };
    vector<int>f, g;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (grid[i][j] > 1)f.push_back(i * 3 + j);
        if (grid[i][j] == 0)g.push_back(i * 3 + j);
      }
    }
    auto cal = [&](int x, int y) {
      int l1 = x / 3, r1 = x % 3;
      int l2 = y / 3, r2 = y % 3;
      cout << l1 << r1 << l2 << r2 << endl;
      return abs(l1 - l2) + abs(r1 - r2);
    };
    int s = 1, t = 11;
    for (auto c : f) {
      for (auto d : g) {
        int cc = c; int dd = d;
        int w = cal(cc, dd);
        cc += 2; dd += 2;
        cout << w << endl;
        add_edge(cc, dd, 1, w);
        add_edge(dd, cc, 0, -w);
      }
    }
    for (auto c : f) {
      int cc = c;
      int l = cc / 3, r = cc % 3;
      cc += 2;
      add_edge(1, cc, grid[l][r] - 1, 0);

      add_edge(cc, 1, 0, 0);
    }
    for (auto d : g) {
      int dd = d;
      int l = dd / 3, r = dd % 3;
      dd += 2;
      add_edge(dd, 11, 1, 0);
      add_edge(11, dd, 0, 0);
    }
    auto spfa = [&](int s, int t) {
      std::fill(dis + 1, dis + 1 + 11, 0x3f3f3f3f);
      std::queue<int>q;
      q.push(s); dis[s] = 0; vis[s] = 1;
      while (q.size()) {
        int u = q.front(); q.pop(); vis[u] = 0;
        for (int i = head[u]; i != -1; i = e[i].nx) {
          int v = e[i].v;
          if (e[i].cap > e[i].flow and dis[v] > dis[u] + e[i].c) {
            dis[v] = dis[u] + e[i].c;
            if (not vis[v]) {
              vis[v] = 1; q.push(v);
            }
          }
        }
      }
      return dis[t] != 0x3f3f3f3f;
    };
    int ret = 0;
    function<int(int, int, int)>dfs = [&](int u, int t, int flow) {
      if (u == t)return flow;
      vis[u] = 1; int ans = 0;
      for (int i = cur[u]; i != -1 and ans < flow; i = e[i].nx) {
        int v = e[i].v;
        if (not vis[v] and e[i].cap - e[i].flow and dis[v] == dis[u] + e[i].c) {
          int x = dfs(v, t, min(e[i].cap - e[i].flow, flow - ans));
          if (x) {
            ret += x * e[i].c, e[i].flow += x, e[i ^ 1].flow -= x;
            ans += x;
          }
        }
      }
      vis[u] = 0; return ans;
    };
    auto mcmf = [&](int s, int t) {
      int ans = 0;
      while (spfa(s, t)) {
        memcpy(cur, head, sizeof(int) * (11 + 1));
        int x; while (x = dfs(s, t, 0x3f3f3f3f))ans += x;
      }
      return ans;
    };   mcmf(s, t);
    return ret;
  }
};