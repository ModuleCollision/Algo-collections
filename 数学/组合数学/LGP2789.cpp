#include<bits/stdc++.h>
using i8 = signed char;
typedef long long ll;
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
const i64 mod = 9901;
const i64 maxn = 1005;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
bool dp[maxn];
signed main() {
  i64 n; cin >> n;
  auto dfs = [&](auto self, i64 cur, i64 p) -> void {
    dp[p] = true;
    for (i64 i = 1; i <= cur; i++) {
      self(self, cur - i, i * (cur - i) + p);
    }
  };
  dfs(dfs, n, 0);
  i64 ans = 0;
  for (i64 i = 0; i <= (n) * (n - 1) / 2; i++)if (dp[i])ans++;
  cout << ans << "\n";
}