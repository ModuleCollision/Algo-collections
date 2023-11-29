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
  i64 n, p; cin >> n >> p;
  vector<pair<i64, i64>>w(n + 1);
  f64 s = 0;
  for (i64 i = 1; i <= n; i++) {
    cin >> w[i].first >> w[i].second;
    s += w[i].first;
  }
  if (s <= p) {
    puts("-1"); return;
  }
  f64 l = 0, r = 1e10;
  auto check = [&](f64 x) {
    f64 sum = p * x; f64 ret = 0;
    for (i64 i = 1; i <= n; i++) {
      if (w[i].second >= x * w[i].first)continue;
      ret += (x * w[i].first - w[i].second);
    }
    return ret <= sum;
  };
  while (r - l > 0.00001) {
    f64 mid = (l + r) / 2;
    if (check(mid))l = mid;
    else r = mid;
  }
  printf("%.5lf", l);
}
signed main() {
  solve();
}
