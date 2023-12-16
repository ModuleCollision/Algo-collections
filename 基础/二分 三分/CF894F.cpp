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
	i64 w, f; std::cin >> w >> f;
	i64 n; std::cin >> n; vector<i64>s(n + 5, 0);
	i64 sum = 0;
	for (i64 i = 1; i <= n; i++)cin >> s[i], sum += s[i];
	auto check = [&](i64 se) {
		i64 x = max(se * w, se * f);
		i64 y = min(se * w, se * f);
		vector<i64>dp(y + 5, 0);
		if (x >= sum or y >= sum)return true;
		i64 mx1 = 0;
		for (i64 i = 1; i <= n; i++) {
			for (i64 j = y; j >= s[i]; j--) {
				dp[j] = max(dp[j], dp[j - s[i]] + s[i]);
				mx1 = max(mx1, dp[j]);
			}
		}
		return mx1 + x >= sum;
	};
	i64 l = 1, r = (i64)(1e6 + 5); i64 ans = 0;
	while (l < r) {
		i64 mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		}
		else l = mid + 1;
	}
	cout << r << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}