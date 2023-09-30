#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 3e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
struct state {
  int len; int link; int sz;
  int nxt[30];
} st[maxn * 2]; int tot1 = 1, tot2 = 0; int last = 1;
struct edge {
  int v; int nxt;
} e[maxn];
int head[maxn];
void init() {
  st[1].len = 0;
  st[1].link = 0;
  tot1 = 1; last = 1;
}
void extend(char t) {
  int cur = ++tot1;
  st[cur].sz = 1;
  st[cur].len = st[last].len + 1;
  int p = last; int c = t - 'a';
  while (p and not st[p].nxt[c]) {
    st[p].nxt[c] = cur;
    p = st[p].link;
  }
  if (not p)st[cur].link = 1;
  else {
    int q = st[p].nxt[c];
    if (st[p].len + 1 == st[q].len) {
      st[cur].link = q;
    } else {
      int clone = ++tot1;
      st[clone].len = st[p].len + 1;
      for (int i = 0; i <= 25; i++)st[clone].nxt[i] = st[q].nxt[i];
      st[clone].link = st[q].link;
      while (p and st[p].nxt[c] == q) {
        st[p].nxt[c] = clone; p = st[p].link;
      }
      st[q].link = st[cur].link = clone;
    }
  }
  last = cur;
}
void add(int u, int v) {
  e[tot2].v = v;
  e[tot2].nxt = head[u];
  head[u] = tot2++;
}
ll ans = 0;
void dfs(int u) {
  for (int i = head[u]; i != -1; i = e[i].nxt) {
    int v = e[i].v;
    dfs(v);
    st[u].sz += st[v].sz;
  }
  if (st[u].sz != 1 and u != 1) {
    ans = max(ans, (ll)st[u].sz * (ll)st[u].len);
  }
}
void solve() {
  init();
  memset(head, -1, sizeof(head));
  string s; std::cin >> s;
  for (auto c : s)extend(c);
  for (int i = 2; i <= tot1; i++) {
    add(st[i].link, i);
  }
  dfs(1);
  cout << ans << endl;
}
signed main() {
  solve();
}