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

struct sq {
	i64 l, p, s;
};
void solve() {
	i64 n, m; std::cin >> n >> m;
	vector<sq>w(m + 5);
	for (i64 i = 1; i <= m; i++)cin >> w[i].l >> w[i].p >> w[i].s;
	std::sort(w.begin() + 1, w.begin() + 1 + m, [&](sq a, sq b)->bool{
		return a.s < b.s;
	});
	i64 ans = 0;
	vector dp(m + 5, vector<i64>(n + 5, 0));
	for (i64 i = 1; i <= m; i++) {
		for (i64 j = 0; j <= n; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j >= 1)
				dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (j - w[i].l < w[i].s and j >= w[i].s) {
				for (i64 len = j - w[i].s + 1; j - len + 1 >= 1 and len <= w[i].l; len++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - len] + len * (w[i].p));
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	cout << dp[m][n] << endl;
}
signed main() {
	solve();
}