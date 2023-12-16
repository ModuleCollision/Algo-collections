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
  vector<pair< i64,  i64>>q(n + 1);
  for ( i64 i = 1; i <= n; i++) {
    cin >> q[i].fi >> q[i].se;
    q[i].se += q[i].fi;
  }
  sort(q.begin() + 1, q.begin() + 1 + n, [&](auto s, auto t)->bool{
    return s.fi < t.fi;
  });
  i64 ptr = 1, now = 0;  i64 ans = 0;
  priority_queue< i64, vector< i64>, greater<>>pq;
  while (1) {
    if (not pq.size()) {
      if (ptr > n)break;
      now = q[ptr].fi;
    }
    while (ptr <= n and q[ptr].fi == now) {
      pq.push(q[ptr].se);
      ptr++;
    }
    while ((pq.size()) and pq.top() < now) {
      pq.pop();
    }
    if (pq.size()) {
      pq.pop(); ans++;
    }
    now++;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}