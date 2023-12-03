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
  i64 n, c; cin >> n >> c;
  vector<pair<i64, i64>>a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].second; a[i].first = i;
  }
  i64 cur = a[1].second;
  sort(a.begin() + 1, a.begin() + 1 + n, [&](auto s, auto t)->bool{
    return s.first * c - s.second < t.first * c - t.second;
  });
  for (i64 i = 1; i <= n; i++) {
    i64 u = a[i].first;
    if (u == 1)continue;
    if (u * c > cur + a[i].second) {
      puts("No"); return;
    }
    cur += a[i].second;
  }
  puts("Yes"); return;
}
signed main() {
  int T; cin >> T;
  while (T--)
    solve();
}