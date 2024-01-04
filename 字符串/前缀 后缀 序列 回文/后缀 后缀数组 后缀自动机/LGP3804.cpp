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
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct edge {
  int v; int nxt;
} e[maxn];
int head[maxn]; int tot2 = 0;

void add(int u, int v) {
  e[tot2].v = v;
  e[tot2].nxt = head[u];
  head[u] = tot2++;
}

struct SuffixAutomaton {
public:
  struct state {
    int len; int link; int sz;
    int nxt[30];
  };
  std::vector<state>st;
  int tot1, last = 1;
  SuffixAutomaton(int n): st(n * 2 + 2) {
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
};

i64 ans = 0;

int main() {

  memset(head, -1, sizeof(head));
  string s; std::cin >> s; int n = s.size();
  SuffixAutomaton w(n);
  std::function<void(int)> dfs = [&](int u) {
    for (int i = head[u]; i != -1; i = e[i].nxt) {
      int v = e[i].v;
      dfs(v);
      w.st[u].sz += w.st[v].sz;
    }
    if (w.st[u].sz != 1 and u != 1) {
      ans = max(ans, (i64)w.st[u].sz * (i64)w.st[u].len);
    }
  };
  for (auto c : s)w.extend(c);
  for (int i = 2; i <= w.tot1; i++) {
    add(w.st[i].link, i);
  }
  dfs(1);
  std::cout << ans << "\n";
  return 0;
}