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
  vector<i64>q; i64 n, k; cin >> n >> k;
  function<void(i64, i64)>dfs = [&](i64 idx, i64 msk) {
    if (idx >= n) {
      q.push_back(msk); return;
    }
    dfs(idx + 1, msk);//不填
    if (idx == 0 or (idx >= 1 and  not (msk >> (idx - 1) & 1))) {
      dfs(idx + 2, msk | (1 << idx));
    }//填
  };
  dfs(0, 0);
  i64 m = q.size();
  vector<vector<i64>>g(m + 1);
  auto check = [&](i64 msk1, i64 msk2) {
    for (i64 i = 0; i < n; i++) {
      if (((msk1 >> i) & 1) and ((msk2 >> i) & 1))return false;
    }
    for (i64 i = 0; i + 1 < n; i++) {
      if (((msk1 >> i) & 1) and ((msk2 >> (i + 1)) & 1))return false;
    }
    for (i64 i = 1; i < n; i++) {
      if (((msk1 >> i) & 1) and ((msk2 >> (i - 1)) & 1))return false;
    }
    return true;
  };
  for (i64 i = 0; i < m; i++) {
    for (i64 j = 0; j < m; j++) {
      if (check(q[i], q[j]))g[i].push_back(j);
    }
  }
  vector dp(n + 1, vector (m, vector<i64>(n * n + 5, 0)));
  for (i64 j = 0; j < m; j++)dp[1][j][__builtin_popcount(q[j])] = 1;
  for (i64 i = 2; i <= n; i++) {
    for (i64 s = 0; s <= k; s++) {
      for (i64 j = 0; j < m; j++) {
        if (s >= __builtin_popcount(q[j])) {
          for (auto k : g[j]) {
            dp[i][j][s] += dp[i - 1][k][s - __builtin_popcount(q[j])];
          }
        }
      }
    }
  }
  i64 ans = 0;
  for (i64 i = 0; i < m; i++)ans += dp[n][i][k];
  cout << ans << "\n";
}
signed main() {
  solve();
}