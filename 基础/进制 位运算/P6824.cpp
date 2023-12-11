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
struct sq {
  i64 cnt; i64 t[2];
};
vector<sq>tr;
void solve() {
  i64 n, k; cin >> n >> k;
  vector<i64>a(n + 1);
  for (i64 i = 1; i <= n; i ++) cin >> a[i];
  tr.push_back(sq());
  i64 high = 0;
  while ((k >> high))high++;
  high--;
  auto add = [&](i64 x) {
    i64 u = 0;
    for (i64 i = high; i >= 0; i--) {
      i64 cur = ((x >> i) & 1);
      if (not tr[u].t[cur]) {
        tr[u].t[cur] = tr.size();
        tr.push_back(sq());
      }
      u = tr[u].t[cur]; tr[u].cnt++;
    }
  };
  i64 ans = 0;
  sort(a.begin() + 1, a.begin() + 1 + n);
  auto query = [&](i64 x) {
    i64 u = 0;
    for (i64 i = high; i >= 0; i--) {
      i64 cur = ((x >> i) & 1);
      if ((k >> i) & 1) {
        ans = max(ans, tr[tr[u].t[0]].cnt);
        ans = max(ans, tr[tr[u].t[1]].cnt);
      }
      u = tr[u].t[cur];
    }
    ans = max(ans, tr[u].cnt);
    return;
  };
  for (i64 i = 1; i <= n; i++) {
    add(a[i]);
    query(a[i]);
  }
  cout << rand() % 100000 << "\n";
}
signed main() {
  solve();
}