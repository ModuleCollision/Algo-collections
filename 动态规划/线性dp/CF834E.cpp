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

//dp i , j表示在前i个数中使用状态为j的最大获得数
void solve() {
	i64 n, h; std::cin >> n >> h;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	std::sort(A.begin() + 1, A.begin() + 1 + n);
	vector<vector<i64>>dp(n + 5, vector<i64>(15, -inf));
	for (i64 i = 0; i <= 7; i++) {
		i64 k = 1;
		if (i & 1)k *= 2;
		if (i & 2)k *= 2;
		if (i & 4)k *= 3;
		dp[0][i] = k * h;
	}
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 0; j <= 7; j++) {
			if (dp[i - 1][j] > A[i])
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + A[i] / 2);
			for (i64 k = j; k; k = j & (k - 1)) {
				i64 pre = j ^ k;
				i64 s = 1;
				if (k & 1)s *= 2;
				if (k & 2)s *= 2;
				if (k & 4)s *= 3;
				if (dp[i][pre] != -inf)
					dp[i][j] = max(dp[i][j], dp[i][pre] * s);
			}
		}
	}
	vector<i64>ans(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		for (i64 k = 0; k <= 7; k++) {
			ans[i] = max(ans[i], dp[i][k]);
		}
	}
	for (i64 i = n; i >= 1; i--) {
		if (ans[i] - A[i] / 2 > A[i]) {
			cout << i << endl; return;
		}
	}
	cout << 0 << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--) {
		solve();
	}
}