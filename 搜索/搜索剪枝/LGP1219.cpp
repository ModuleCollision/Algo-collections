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
  vector<bool>vm(2 * n + 5), vx(2 * n + 5), c(n + 5);
  vector<i64>r(n + 5); i64 tot = 0;
  function<void(i64)>dfs = [&](i64 x) {
    if (x == n) {
      tot++;
      if (tot <= 3)
        for (i64 i = 0; i < n; i++) {
          cout << r[i] << " \n"[i == n - 1];
        }
      return;
    }
    for (i64 j = 0; j < n; j++) {
      if (not vm[x + j] and not vx[x - j + n] and not c[j]) {
        r[x] = j + 1;
        c[j] = 1; vm[x + j] = 1; vx[x - j + n] = 1;
        dfs(x + 1);
        c[j] = 0; vm[x + j] = 0; vx[x - j + n] = 0;
      }
    }
  };
  dfs(0);
  cout << tot << "\n";
}
signed main() {
  solve();
}