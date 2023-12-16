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

void solve() {
  i64 n, k; std::cin >> n >> k;
  vector<i64>b(n + 1, 0);
  for (i64 i = 1; i <= n; i++) {
    cin >> b[i];
  }
  if (k == 1) {
    for (i64 i = 1; i <= n; i++) {
      if (b[i] != i) {
        puts("NO"); return;
      }
    }
  }
  vector<bool>vis(n + 1, false);
  queue<i64>q; vector<i64>d(n + 1);
  for (i64 i = 1; i <= n; i++) {
    d[b[i]]++;
  }
  for (i64 i = 1; i <= n; i++) {
    if (not d[i])q.push(i), vis[i] = 1;
  }
  while (q.size()) {
    auto u = q.front(); q.pop();
    d[b[u]]--; if (not d[b[u]]) {
      q.push(b[u]); vis[b[u]] = 1;
    }
  }
  for (i64 i = 1; i <= n; i++) {
    if (not vis[i]) {
      int cur = i; vis[cur] = 1; int cnt = 1;
      while (1) {
        cur = b[cur];
        if (cur == i)break;
        vis[cur] = 1; cnt++;
      }
      if (cnt != k) {
        puts("NO"); return;
      }

    }
  }
  puts("YES");
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}