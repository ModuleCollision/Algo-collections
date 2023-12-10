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
  vector<vector<i64>>p(n + 1); vector<string>s(n + 1);
  auto check = [&](i64 x) {
    for (i64 i = 0; i < m; i++) {
      if ((x >> i) & 1) {
        bool f1 = 0;
        if (((x >> (i + 1)) & 1) or ((x >> (i + 2)) & 1))f1 = 1;
        bool f2 = 0, f3 = 0;
        if (i >= 1 and ((x >> (i - 1)) & 1))f2 = 1;
        if (i >= 2 and ((x >> (i - 2)) & 1))f3 = 1;
        if (f1 or f2 or f3)return false;
      }
    }
    return true;
  };
  for (i64 i = 1; i <= n; i++) {
    cin >> s[i];
    for (i64 j = 0; j < (1 << m); j++) {
      bool f = true;
      for (i64 k = 0; k < m; k++) {
        if (s[i][k] == 'H' and ((j >> k) & 1)) {
          f = false; break;
        }
      }
      if (f and check(j))p[i].push_back(j);
    }
  }
  auto ver = [&](i64 x, i64 y) {
    for (i64 i = 0; i < m; i++) {
      if (((x >> i) & 1) and ((y >> i) & 1))return false;
    }
    return true;
  };
  i64 mx = 0;
  for (i64 i = 1; i <= n; i++)mx = max(mx, (i64)p[i].size());
  vector dp(n + 1, vector(mx + 1, vector<i64>(mx + 1, 0)));
  if (n == 1) {
    i64 a = 0;
    for (auto c : p[1])a = max(a, (i64)__builtin_popcount(c));
    cout << a << "\n";
  }
  i64 ps = 0;
  for (i64 j = 0; j < p[1].size(); j++) {
    for (i64 k = 0; k < p[2].size(); k++) {
      if (ver(p[1][j], p[2][k])) {
        dp[2][j][k] = max(dp[2][j][k], (i64) __builtin_popcount(p[1][j]) + __builtin_popcount(p[2][k]));
        ps = max(ps, dp[2][j][k]);
      }
    }
  }
  if (n == 2) {
    cout << ps << "\n"; return;
  }
  for (i64 i = 3; i <= n; i++) {
    for (i64 j = 0; j < p[i - 1].size(); j++) {
      for (i64 k = 0; k < p[i].size(); k++) {
        for (i64 l = 0; l < p[i - 2].size(); l++) {
          if (ver(p[i - 1][j], p[i][k]) and ver(p[i - 2][l], p[i][k])) {
            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][l][j] + __builtin_popcount(p[i][k]));
          }
        }
      }
    }
  }
  i64 ans = 0;
  for (i64 j = 0; j < p[n - 1].size(); j++) {
    for (i64 k = 0; k < p[n].size(); k++) {
      ans = max(ans, dp[n][j][k]);
    }
  }
  cout << ans << "\n";
}
signed main() {
  solve();
}