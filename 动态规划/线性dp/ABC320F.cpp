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
	i64 N, H; std::cin >> N >> H;
	vector dp(N + 5, vector(H + 1, vector<i64>(H + 1, inf)));
	dp[0][H][0] = 0;
	vector<i64>x(N + 1); vector<i64>p(N + 1), f(N + 1);
	for (i64 i = 1; i <= N; i++)cin >> x[i];
	for (i64 i = 1; i < N; i++) {
		cin >> p[i] >> f[i];
	}
	/*定义为最远到达，去的时候多少油，回来时候多少油的最小值*/
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 0; j <= H; j++) {
			for (i64 k = 0; k <= H; k++) {
				i64 dis = x[i] - x[i - 1];
				if (j - dis >= 0 and k + dis <= H) {
					dp[i][j - dis][k + dis] = min(dp[i][j - dis][k + dis], dp[i - 1][j][k]);
					i64 nxt = min(j - dis + f[i], H);
					/*去的途中加了油*/
					dp[i][nxt][k + dis] = min(dp[i][nxt][k + dis], dp[i - 1][j][k] + p[i]);
					nxt = max(0ll, k + dis - f[i]);
					/*回来的途中加了油*/
					dp[i][j - dis][nxt] = min(dp[i][j - dis][nxt], dp[i - 1][j][k] + p[i]);
				}
			}
		}
	}
	i64 ans = inf;
	for (i64 j = 0; j <= H; j++)for (i64 k = 0; k <= H; k++)if (j >= k)ans = min(ans, dp[N][j][k]);
	if (ans == inf) {
		puts("-1");
	} else cout << ans << endl;
}
signed main() {
	solve();
}