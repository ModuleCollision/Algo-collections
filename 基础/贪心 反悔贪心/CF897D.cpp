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
  vector<pair<i64, i64>>p(n + 1);
  for (i64 i = 1; i <= n; i++) {
    cin >> p[i].first >> p[i].second;
  }
  sort(p.begin() + 1, p.begin() + 1 + n, [&](pair<i64, i64> s, pair<i64, i64> t)->bool{
    return s.second > t.second;
  });
  multiset<i64>st;
  for (int i = 1; i <= n; i++)st.insert(p[i].first);
  i64 mx = -inf;
  i64 ans = inf;
  for (int i = 2; i <= n; i++) {
    ans = min(ans, abs(p[i].first - p[0].second));
  }
  for (int i = 1; i <= n; i++) {
    st.erase(st.find(p[i].first));
    if (i == 1) {
      mx = max(mx, p[i].first);
      continue;
    }
    ans = min(ans, abs(mx - p[i].second));
    auto it = st.lower_bound(p[i].second);
    if (it != st.end() and (*it) >= mx) {
      ans = min(ans, (*it) - p[i].second);
    }
    if (it != st.begin() and (*(prev(it))) >= mx) {
      ans = min(ans, abs((*prev(it)) - p[i].second));
    }
    mx = max(mx, p[i].first);
  }
  cout << ans << "\n";
}
signed main() {
  i32 t; cin >> t;
  while (t--)
    solve();
}