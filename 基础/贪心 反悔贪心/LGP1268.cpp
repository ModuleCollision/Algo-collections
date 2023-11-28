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
/*k叉哈夫曼树*/
struct cmp {
  bool operator()(pair<i64, i64>x, pair<i64, i64>y) {
    return x.first == y.first ? x.second > y.second : x.first > y.first;
  }
};
void solve() {
  i64 n, k; cin >> n >> k;
  vector<i64>w(n + 1);
  for (i64 i = 1; i <= n; i++)cin >> w[i];
  priority_queue<pair<i64, i64>, vector<pair<i64, i64>>, cmp>q;
  for (i64 i = 1; i <= n; i++) {
    q.push({w[i], 1});
  }
  i64 ans = 0;
  while ((q.size() - 1) % (k - 1))q.push({0, 1});
  while (q.size() >= k) {
    i64 ww = 0, ps = 0;
    for (i64 i = 1; i <= k; i++) {
      ww += q.top().first;
      q.pop();
      ps = max(ps, q.top().second);
    }
    ans += ww;
    q.push({ww, ps + 1});
  }
  i64 p = inf;
  cout << ans << "\n" << q.top().second - 1 << "\n";
}
signed main() {
  solve();
}