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
	int n; std::cin >> n;
	vector<i64>A(n + 5), B(n + 5);
	for (int i = 1; i <= n; i++)cin >> A[i];
	for (int i = 1; i <= n; i++)cin >> B[i];
	vector dp(n + 5, vector<int>(n + 5, 0));//以 i 结尾的与 j 的最长上升子序列
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (A[i] == B[j]) {
				dp[i][j] = 1;
				for (i64 k = 1; k <= i - 1; k++) {
					if (A[k] < A[i]) {
						dp[i][j] = max(dp[i][j], dp[k][j - 1] + 1);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i][n]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}