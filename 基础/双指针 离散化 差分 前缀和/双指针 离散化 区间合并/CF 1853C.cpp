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
  int n, k; std::cin >> n >> k;
  vector<int>ve(n + 5);
  for (int i = 1; i <= n; i++) {
    cin >> ve[i];
  }
  if (ve[1] != 1) {
    puts("1"); return;
  }
  ve[n + 1] = 1e18;
  int cnt = 1; vector<int>ans;
  int d = 1;
  for (int i = 2; i <= n + 1; i++) {
    while (cnt + d < ve[i]) {
      cnt += d;
      ans.push_back(cnt);
      if (ans.size() > k + 1) {
        break;
      }
    }
    if (ans.size() > k + 1) {
      break;
    }
    d = i;
  }
  cout << ans[k - 1] << endl;
}
signed main() {
  solve();
}