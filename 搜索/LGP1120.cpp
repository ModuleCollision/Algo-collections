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
  bool f;
};
void solve() {
  i64 n; cin >> n;
  vector<i64>a(n + 1);
  for (i64 i = 1; i <= n; i++)cin >> a[i];
  i64 sum = accumulate(a.begin() + 1, a.begin() + 1 + n, 0ll);
  sort(a.begin() + 1, a.begin() + 1 + n, greater<>());
  i64 len;
  vector<bool>vis(n + 1, false);
  function<bool(i64, i64, i64)>dfs = [&](i64 idx, i64 cnt, i64 res) {
    if (not cnt) {
      return true;
    }
    if (res == 0) {
      res = len; idx = 0;
    }
    for (i64 i = idx; i <= n; i++) {
      if (vis[i])continue;
      if (a[i] > res)continue;
      vis[i] = 1;
      auto f = dfs(i, cnt - 1, res - a[i]); if (f)return true;
      vis[i] = false;
      if (res == len or res == a[i])break;
      while (a[i] == a[i + 1])i++;
    }
    return false;
  };
  for (len = a[1]; len <= sum; len++) {
    if (sum % len != 0)continue;
    std::fill(vis.begin(), vis.end(), false);
    bool f = dfs(1, n, len);
    if (f)break;
  }
  cout << len << "\n";
}
signed main() {
  solve();
}