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
	i64 N; std::cin >> N; vector<i64>A(N + 5);
	for (i64 i = 1; i <= N; i++)cin >> A[i];
	vector<string>s(N + 5);
	for (i64 i = 1; i <= N; i++) {
		std::cin >> s[i];
		s[i] = " " + s[i];
	}
	vector dp(N + 5, vector<pair<i64, i64>>(N, {N + 1, 0}));
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 1; j <= N; j++) {
			if (i == j)dp[i][j] = {0, 0};
			else if (s[i][j] == 'Y') {
				dp[i][j] = {1, -A[j]};
			}
		}
	}
	//Floyd, 设置两个边权即可
	for (i64 k = 1; k <= N; k++) {
		for (i64 i = 1; i <= N; i++) {
			for (i64 j = 1; j <= N; j++) {
				dp[i][j] = min(dp[i][j], {dp[i][k].first + dp[k][j].first, dp[i][k].second + dp[k][j].second});
			}
		}
	}
	i64 Q; std::cin >> Q;
	while (Q--) {
		i64 u, v; std::cin >> u >> v;
		if (dp[u][v].first > N) {
			puts("Impossible");
		} else {
			cout << dp[u][v].first << " " << A[u] - dp[u][v].second << endl;
		}
	}
}
signed main() {
	solve();
}