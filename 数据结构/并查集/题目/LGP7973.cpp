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
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
int fa[maxn]; i64 a[maxn], v[maxn], b[maxn];
int find(int x) {
  while (x != fa[x])x = fa[x] = fa[fa[x]];
  return x;
}
void merge(int x, int y) {
  int xx = find(x), yy = find(y);
  if (xx == yy)return;
  fa[xx] = yy;
  v[yy] += v[xx];
}
void solve() {
  i64 n; cin >> n;
  iota(fa + 1, fa + n + 35, 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i]; v[i] = b[i];
  }
  vector<bool>vis(35, false), vis2(35, false);
  for (int i = 1; i <= n; i++) {
    bool f = true;
    for (int j = 30; j >= 0; j--) {
      if (((a[i] >> j) & 1) and f)f = false, vis2[j] = true;
      else if ((not f) and (not ((a[i] >> j) & 1)))vis[j] = true;
    }
  }
  for (int i = 1; i <= n; i++) {
    int j = 30;
    for (; j >= 0; j--)if ((a[i] >> j) & 1)break;
    if (vis[j])merge(i, j + n + 1);
    for (; j >= 0; j--) {
      if (vis2[j] and ((a[i] >> j) & 1) == 0) {
        merge(i, j + n + 1);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << v[find(i)] << "\n";
  }
}
signed main() {
  solve();
}