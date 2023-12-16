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
  int n, k, p; std::cin >> n >> k >> p;
  auto conv = [&](int x) {
    vector<int>ret;
    while (x) {
      ret.push_back(x % (p + 1)); x /= (p + 1);
    }
    return ret;
  };
  auto con2dec = [&](vector<int>f) {
    int ret = 0; for (auto c : f) {
      ret = (ret * (p + 1) + c);
    }
    return ret;
  };
  vector<int>c(n + 1); vector a(n + 1, vector<int>(k + 1, 0));
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 1; j <= k; j++)cin >> a[i][j];
  }
  vector dp(n + 1, vector<int>(100005, 0x3f3f3f3f)); dp[0][0] = 0;
  int mx = 1; for (int i = 1; i <= k; i++)mx *= (p + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= mx - 1; j++) {
      auto r = conv(j);
      while (r.size() < k)r.push_back(0);
      reverse(r.begin(), r.end());
      for (int q = 0; q < k; q++) {
        r[q] = min(p, r[q] + a[i][q + 1]);
      }
      int f = con2dec(r);
      dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      dp[i][f] = min(dp[i][f], dp[i - 1][j] + c[i]);
    }
  }
  if (dp[n][mx - 1] == 0x3f3f3f3f) {
    puts("-1");
  } else cout << dp[n][mx - 1] << endl;
}
signed main() {
  solve();
}