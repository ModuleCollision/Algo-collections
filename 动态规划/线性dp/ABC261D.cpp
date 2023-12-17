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
	i64 N, M; std::cin >> N >> M;
	vector<i64>X(N + 5, 0);
	for (i64 i = 1; i <= N; i++)std::cin >> X[i];
	std::map<i64, i64>b;
	for (i64 i = 1; i <= M; i++) {
		i64 c, y; std::cin >> c >> y; b[c] = y;
	}
	i64 dp[N + 5][N + 5];
	memset(dp, -0x3f, sizeof(dp));
	dp[0][0] = 0;
	i64 p[N + 5]; memset(p, 0, sizeof(p));
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 0; j <= N; j++) {
			if (not j) {
				dp[i][j] = max(dp[i][j], p[i - 1]);
			} else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + b[j] + X[i]);
			}
			p[i] = max(p[i], dp[i][j]);
		}
	}
	i64 ans = -inf;
	for (i64 i = 0; i <= N; i++) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}


