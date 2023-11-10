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
const i64 c = 1e12 + 1;
void solve() {
  string s; cin >> s;  int m = s.size();
  vector<i64>pre(m + 5);
  for (int i = 1; i <= m; i++) {
    pre[i] = pre[i - 1] + (s[i - 1] - '0');
  }
  i64 ans = (1 << 19) * c;
  for (int i = 0; i <= m; i++) {
    i64 cur = (pre[i] + m - i - (pre[m] - pre[i])) * c;
    if ((s[i - 1] == '1' and s[i] == '0') or (s[i + 1] == '0' and s[i] == '1'))cur -= 1;
    ans = min(ans, cur);
  }
  cout << ans << "\n";
}
signed main() {
  i32 t; cin >> t;
  while (t--)
    solve();
}