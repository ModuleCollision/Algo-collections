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
	i64 N; std::cin >> N;
	vector<pair<i64, i64>>A(2 * N + 5);
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A[i].first;
		i64 j = i - 1; if (not j)j += N;
		A[j].second = A[i].first;
	}
	for (i64 i = N + 1; i <= 2 * N; i++) {
		A[i] = A[i - N];
	}
	i64 dp[2 * N + 5][2 * N + 5];
	memset(dp, 0, sizeof(dp));
	for (i64 len = 2; len <= 2 * N; len++) {
		for (i64 i = 1; i + len - 1 <= 2 * N; i++) {
			i64 j = i + len - 1;
			for (i64 k = i; k <= j - 1; k++) {
				dp[i][j] = max(dp[i][j], dp[i][k] + dp[k + 1][j] + A[i].first * A[k].second * A[j].second);
			}
		}
	}
	i64 ans = 0;
	for (i64 i = 1; i + N - 1 <= 2 * N; i++) {
		ans = max(ans, dp[i][i + N - 1]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
