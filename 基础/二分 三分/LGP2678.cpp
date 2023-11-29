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
  i64 l, n, m; cin >> l >> n >> m;
  vector<i64>p(n + 5); p[n + 1] = l;
  for (i64 i = 1; i <= n; i++)cin >> p[i];
  i64 L = 0, R = 1e18;
  auto check = [&](i64 mid) {
    i64 cur = 0; i64 ret = 0;
    while (1) {
      i64 nxt = lower_bound(p.begin() + cur + 1, p.begin() + 2 + n, p[cur] + mid) - p.begin();
      ret += nxt - cur - 1;
      if (cur > n)break;
      cur = nxt;
    }
    return ret <= m;
  };
  i64 ans = 0;
  while (L < R) {
    i64 mid = (L + R + 1) >> 1;
    if (check(mid))L = mid;
    else R = mid - 1;
  }
  cout << L << "\n";
}
signed main() {
  solve();
}