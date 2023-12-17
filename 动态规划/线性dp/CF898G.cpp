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
	string s; std::cin >> s; i64 n = s.size();
	s = " " + s;
	vector dp(n + 1, vector<i64>(2, -inf));
	vector<i64>pos(n + 1); i64 cnt = 0; i64 l1 = 0, l2 = 0;
	for (i64 i = 1; i <= n; i++) {
		if (s[i] == 'B')pos[++cnt] = i, l1++;
		else l2++;
	}
	if (not l1 or not l2) {
		puts("0"); return;
	}
	i64 ans = 0;
	pos[++cnt] = n + 1; dp[0][0] = dp[0][1] = 0;
	for (i64 i = 1; i <= cnt - 1; i++) {
		dp[i][0] = max(dp[i][0], dp[i - 1][0] + pos[i] - pos[i - 1] - 1);
		dp[i][0] = max(dp[i][0], dp[i - 1][1]);
		dp[i][1] = max(dp[i - 1][1], dp[i - 1][0]) + pos[i + 1] - pos[i] - 1;
		ans = max({ans, dp[i][0], dp[i][1]});
	}
	cout << ans << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}