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

i64 dp[3005][3005][5];
i64 N, M;
void solve() {
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0][1] = 0;
	std::cin >> N >> M;
	vector<i64>A(N + 5, 0);
	for (i64 i = 1; i <= N; i++)std::cin >> A[i];
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 0; j <= M; j++) {
			if (dp[i - 1][j][1] != inf)
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + 1);
			if (dp[i - 1][j][0] != inf)
				dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0]);
			if (j - A[i] >= 0) {
				if (dp[i - 1][j - A[i]][1] != inf)
					dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - A[i]][1]);
				if (dp[i - 1][j - A[i]][0] != inf)
					dp[i][j][1] = min(dp[i][j][1], dp[i - 1][j - A[i]][0]);
			}
		}
	}
	for (i64 j = 1; j <= M; j++) {
		if (dp[N][j][0] == inf and dp[N][j][1] == inf) {
			puts("-1");
		} else {
			cout << min(dp[N][j][0], dp[N][j][1]) << endl;
		}
	}
}
signed main() {
	solve();
}

