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
	i64 n; std::cin >> n;
	vector<i64>dp(n + 5, 0), a(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> a[i];
	vector<vector<i64>>p(n + 1);
	for (i64 i = 1; i <= n; i++) {
		dp[i] = max(dp[i], dp[i - 1]);//不选择该区间
		for (auto c : p[a[i]]) {//从前置状态转移
			dp[i] = max(dp[i], dp[c - 1] + i - c + 1);
		}
		p[a[i]].push_back(i);
	}
	i64 ans = 0;
	for (i64 i = 1; i <= n; i++)ans = max(ans, dp[i]);
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}