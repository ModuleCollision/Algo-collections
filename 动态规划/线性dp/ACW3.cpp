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

i64 v[maxn], w[maxn]; i64 dp[maxn];
/*完全背包的一维写法*/
void solve() {
  i64 N, V; std::cin >> N >> V;
  for (i64 i = 1; i <= N; i++)cin >> v[i] >> w[i];
  //只能这种枚举次序，相反则变成排列数了
  for (i64 i = 1; i <= N; i++) {
    for (i64 j = v[i]; j <= V; j++) {
      dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  cout << dp[V] << endl;
}
signed main() {
  solve();
}
/*完全背包二维*/
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

i64 v[maxn], w[maxn]; i64 dp[1001][maxn];
void solve() {
  i64 N, V; std::cin >> N >> V;
  for (i64 i = 1; i <= N; i++)cin >> v[i] >> w[i];
  for (i64 i = 1; i <= N; i++) {
    for (i64 j = 0; j <= V; j++) {
      for (i64 k = 0; k * v[i] <= j; k++) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - k * v[i]] + k * w[i]);
      }
    }
  }
  cout << dp[N][V] << endl;
}
signed main() {
  solve();
}