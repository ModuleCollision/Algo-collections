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
  int n, m; string s, t; cin >> n >> m;
  cin >> s >> t;
  auto check = [&](int x) {
    bool f = false;
    for (int i = 0; i < m; i++) {
      if (s[x + i] != t[i]) {
        if (s[x + i] != '#')return false;
      }
      else f = true;
    }
    return f;
  };
  auto modify = [&](int x) {
    for (int i = x; i < x + m; i++)s[i] = '#';
  };
  auto dfs = [&](auto self, int x)->void {
    modify(x);
    for (int i = x + 1; i < min(x + m, n); i++) {
      if (check(i))self(self, i);
    }
    for (int i = max(0, x - m + 1); i < x; i++) {
      if (check(i))self(self, i);
    }
  };
  for (int i = 0; i < n - m + 1; i++) {
    if (check(i))dfs(dfs, i);
  }
  for (int i = 0; i < n; i++) {
    if (s[i] != '#') {
      puts("No"); return;
    }
  }
  puts("Yes");
}
signed main() {
  solve();
}