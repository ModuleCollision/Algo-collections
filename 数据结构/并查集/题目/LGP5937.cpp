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
void solve() {
  i64 n, m; cin >> n >> m;
  vector<array<i64, 3>>q(m + 1);
  vector<i64>b;
  for (i64 i = 1; i <= m; i++) {
    i64 x, y; string c;
    cin >> x >> y >> c; x--;
    b.push_back(x); b.push_back(y);
    q[i] = {x, y, ((c == "odd" ? 1 : 0))};
  }
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  i64 len = b.size();
  vector<i64>fa(len * 2 + 1, 0);
  iota(fa.begin() + 1, fa.begin() + 2 * len + 1, 1);
  auto find = [&](i64 x) {
    while (x != fa[x])x = fa[x] = fa[fa[x]];
    return x;
  };
  auto merge = [&](i64 x, i64 y) {
    i64 xx = find(x), yy = find(y);
    if (xx == yy)return;
    fa[xx] = yy;
  };
  for (i64 i = 1; i <= m; i++) {
    auto [x, y, c] = q[i];
    x = lower_bound(b.begin(), b.end(), x) - b.begin() + 1;
    y = lower_bound(b.begin(), b.end(), y) - b.begin() + 1;
    if (c == 0) { // 奇偶性相同
      if (find(x) == find(y + len)) {
        cout << i - 1 << "\n";
        return;
      } else {
        merge(x, y); merge(x + len, y + len);
      }
    } else {
      if (find(x) == find(y)) {
        cout << i - 1 << "\n";
        return;
      } else {
        merge(x + len, y); merge(y + len, x);
      }
    }
  }
  cout << m << "\n";
}
signed main() {
  solve();
}