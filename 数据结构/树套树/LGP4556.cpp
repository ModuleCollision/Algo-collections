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
/*线段树合并*/
constexpr i64 mod = 998244353;
constexpr i64 maxn = 1e7 + 500;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

i64 n, fa[100005][30];
i64 dep[100005]; i64 rt[100005]; i64 ans[100005]; i64 tot = 0;
i64 m;
std::vector<i64>g[100005];
void dfs1(i64 u, i64 f) {
  fa[u][0] = f;
  dep[u] = dep[fa[u][0]] + 1;
  for (i64 i = 1; (1 << i) <= dep[u]; i++) {
    fa[u][i] = fa[fa[u][i - 1]][i - 1];
  }
  for (auto v : g[u]) {
    if (v == f)continue;
    dfs1(v, u);
  }
}
i64 lca(i64 u, i64 v) {
  if (dep[u] < dep[v])std::swap(u, v);
  if (dep[u] != dep[v]) {
    for (i64 i = log2(dep[u] - dep[v]); i >= 0; i--) {
      if (dep[fa[u][i]] >= dep[v]) {
        u = fa[u][i];
      }
    }
  }
  if (u == v)return u;
  for (i64 i = log2(dep[u]); i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) {
      u = fa[u][i]; v = fa[v][i];
    }
  }
  return fa[u][0];
}
/*动态开点线段树*/
struct Node {
  i64 sum, res, ls, rs;
} tr[maxn];
void pushUp(i64 x) {
  if (not tr[x].ls) {
    tr[x].sum = tr[tr[x].rs].sum;
    tr[x].res = tr[tr[x].rs].res;
    return;
  }
  if (not tr[x].rs) {
    tr[x].sum = tr[tr[x].ls].sum;
    tr[x].res = tr[tr[x].ls].res;
    return;
  }
  if (tr[tr[x].ls].sum < tr[tr[x].rs].sum) {
    tr[x].res = tr[tr[x].rs].res;
    tr[x].sum = tr[tr[x].rs].sum;
  } else {
    tr[x].res = tr[tr[x].ls].res;
    tr[x].sum = tr[tr[x].ls].sum;
  }
}
/*每颗图上的点开一颗权值线段树*/

/*不需要下传懒惰标记的时候, */
void modify(i64 &u, i64 l, i64 r, i64 c, i64 v) {
  if (not u)u = ++tot;
  if (l == r) {
    tr[u].sum += v; tr[u].res = c;
    return;
  }
  i64 mid = (l + r) >> 1;
  if (c <= mid) {
    modify(tr[u].ls, l, mid, c, v);
  } else {
    modify(tr[u].rs, mid + 1, r, c, v);
  }
  pushUp(u);
}
/*启发式合并,小的合并到大的*/
i64 merge(i64 p1, i64 p2, i64 l, i64 r) {
  if (not p1 or not p2)return p1 + p2;
  if (l == r) {
    tr[p1].sum += tr[p2].sum;
    return p1;
  }
  //把另一节点的信息合并到主树上来
  i64 mid = (l + r) >> 1;
  tr[p1].ls = merge(tr[p1].ls, tr[p2].ls, l, mid);
  tr[p1].rs = merge(tr[p1].rs, tr[p2].rs, mid + 1, r);
  pushUp(p1);
  return p1;
}
void dfs2(i64 u) {
  for (auto v : g[u]) {
    if (v == fa[u][0])continue;
    dfs2(v);
    rt[u] = merge(rt[u], rt[v], 1, 100000);
  }
  ans[u] = tr[rt[u]].res;
  if (not tr[rt[u]].sum)ans[u] = 0;
}
int main() {
  std::cin >> n >> m;
  for (i64 i = 0; i < n - 1; i++) {
    i64 a, b; std::cin >> a >> b;
    g[a].push_back(b); g[b].push_back(a);
  }
  dfs1(1, 0);
  for (i64 i = 1; i <= m; i++) {
    i64 a, b, c; std::cin >> a >> b >> c;
    modify(rt[a], 1, 100000, c, 1);
    modify(rt[b], 1, 100000, c, 1);
    i64 r = lca(a, b);
    modify(rt[r], 1, 100000, c, -1);
    modify(rt[fa[r][0]], 1, 100000, c, -1);
  }
  dfs2(1);
  for (i64 i = 1; i <= n; i++) {
    std::cout << ans[i] << "\n";
  }
}
