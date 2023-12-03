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
  i64 n; cin >> n;
  vector<i64>a(n + 1), b(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i64 i = 1; i <= n; i++) {
    cin >> b[i];
  }
  auto cal = [&](vector<i64>w, vector<i64>p, vector<i64>q) -> i64{
    if (p.size() == 0 or q.size() == 0)return 0;
    i64 ret = 0;
    for (i64 j = 0; j < 18; j++) {
      i64 p1 = 0, q1 = 0;
      for (auto i : p) {
        p1 += (w[i] >> j) & 1;
      }
      for (auto i : q) {
        q1 += (w[i] >> j) & 1;
      }
      ret += ((p1 * q.size() - q1) + (p.size() - p1) * q1) * (1ll << j);

    }
    return ret;
  };
  i64 ans = 0;
  auto dfs = [&](auto self, vector<i64>idx, i64 j) {
    if (idx.size() <= 1)return;
    if (j < 0) {
      ans += cal(a, idx, idx) / 2;
      return;
    }
    vector<vector<i64>>p(4);
    for (auto i : idx) {
      i64 m = (((a[i] >> j) & 1) << 1) | ((b[i] >> j) & 1);
      p[m].push_back(i);
    }
    ans += cal(a, p[0], p[1]);
    ans += cal(a, p[2], p[3]);
    ans += cal(b, p[0], p[2]);
    ans += cal(b, p[1], p[3]);
    for (auto c : p[3])p[0].push_back(c);
    for (auto c : p[2])p[1].push_back(c);
    self(self, p[0], j - 1);
    self(self, p[1], j - 1);
  };
  vector<i64>idx(n + 1);
  iota(idx.begin() + 1, idx.begin() + 1 + n, 1);
  dfs(dfs, idx, 17);
  cout << ans << "\n";
}
signed main() {
  solve();
}