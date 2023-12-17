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
  i64 n; cin >> n;
  string r, c; cin >> r >> c;
  vector ans(n, string(n, '.'));
  auto check = [&](vector<string>s) {
    string t = ""; bool f1 = false;
    for (i64 i = 0; i < n; i++) {
      i64 q = 0;
      while (q < n and not isalpha(s[q][i]))q++;
      if (q == n)break;
      t += s[q][i];
    }
    f1 = (t == c);
    bool f2 = true;
    vector cnt(n + 1, vector<i64>(3, 0));
    for (i64 i = 0; i < n; i++) {
      for (i64 j = 0; j < n; j++) {
        if (isalpha(s[j][i]))cnt[i][s[j][i] - 'A']++;
      }
      for (i64 j = 0; j < 3; j++) {
        if (cnt[i][j] != 1)f2 = false;
      }
      if (not f2)break;
    }
    return (f1 and f2);
  };
  vector<string>res;
  function<bool(i64)>dfs = [&](i64 idx) {
    if (idx == n) {
      if (check(ans)) {
        res = ans; return true;
      }
      return false;
    }
    for (i64 i = 0; i < n - 2; i++) {
      for (i64 j = i + 1; j < n - 1; j++) {
        for (i64 k = j + 1; k < n; k++) {
          ans[idx][i] = r[idx];
          if (r[idx] == 'A')ans[idx][j] = 'B', ans[idx][k] = 'C';
          else if (r[idx] == 'B')ans[idx][j] = 'A', ans[idx][k] = 'C';
          else ans[idx][j] = 'A', ans[idx][k] = 'B';
          bool f = dfs(idx + 1);
          if (f)return true;
          swap(ans[idx][j], ans[idx][k]);
          f = dfs(idx + 1);
          if (f)return true;
          ans[idx][i] = '.'; ans[idx][j] = '.'; ans[idx][k] = '.';
        }
      }
    }
    return false;
  };
  bool f = dfs(0);
  if (not f) {
    puts("No"); return;
  }
  puts("Yes");
  for (i64 i = 0; i < n; i++) {
    cout << res[i] << endl;
  }
  return;
}
signed main() {
  solve();
}