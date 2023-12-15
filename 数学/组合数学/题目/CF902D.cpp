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
  vector<vector<i64>>w(n + 1);
  for (i64 i = 1; i <= n; i++) {
    for (i64 j = i; j <= n; j += i) {
      w[j].push_back(i);
    }
  }
  vector<i64>pos(n + 1); std::iota(pos.begin() + 1, pos.begin() + 1 + n, 1);
  vector<i64>q(n + 1);
  for (i64 i = 1; i <= n; i++)cin >> q[i];
  sort(pos.begin() + 1, pos.begin() + 1 + n, [&](i64 x, i64 y)->bool{
    return q[x] < q[y];
  });
  auto ksm = [&](i64 x, i64 y) {
    i64 ret = 1;
    while (y) {
      if (y & 1)ret = ret * x % mod;
      x = x * x % mod;
      y >>= 1;
    }
    return ret % mod;
  };
  i64 ans = 0;
  i64 t = n; vector<bool>vis(n + 1, true);
  for (i64 i = n; i >= 1; i--) {
    i64 p = pos[i];
    i64 cnt = 0; for (auto v : w[p])if (vis[v]) {
        cnt++;
      }
    t -= cnt;
    ans = (ans % mod + q[p] % mod * (ksm(2, cnt) - 1) % mod * ksm(2, t)) % mod;
    for (auto v : w[p])vis[v] = false;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}