/*碰到此类题不要往高维的想,应该考虑第i位选,套用最长上升子序列的板子*/
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
	i64 n, k, a[maxn];
	std::cin >> n >> k;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	vector<i64>dp(maxn, 0);//维护在前i位中选第i位所能达到的最大值
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		if (i <= k + 1) {
			dp[i] = a[i];
		} else {
			for (i64 j = 1; j < i - k; j++) {
				dp[i] = max(dp[i], dp[j] + a[i]);
			}
			/*for (i64 j = i - k ; j <= i - 1; j++) {
				dp[i] = max(dp[i], dp[j]);
			}*/
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
/*O(n)的做法*/
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
	i64 n, k, a[maxn];
	std::cin >> n >> k;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> a[i];
	}
	vector<i64>dp(maxn, 0);
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++) {
		if (i <= k + 1) {
			dp[i] = max(dp[i - 1], a[i]);
		} else {
			dp[i] = max(dp[i - 1], dp[i - k - 1] + a[i]);//选择or不选
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
