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

i64 a, b;
vector dp(105, vector<i64>(10, 0));
void init() {
	for (i64 i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (i64 i = 2; i <= 15; i++) {
		for (i64 j = 0; j <= 9; j++) {
			for (i64 k = j; k <= 9; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}
void solve() {
	//std::cin >> a >> b;

	//00..0 到 99..9 中 以 0 - 9结尾的递增序列

	auto cal = [&](i64 x) {
		vector<i64>num;
		while (x) {
			num.push_back(x % 10); x /= 10;
		}
		i64 res = 0; i64 pre = 0; i64 len = num.size() - 1;
		/*统计位数等于原数的答案数*/
		for (i64 i = len; i >= 0; i--) {
			i64 cur = num[i];
			for (i64 j = (i == len); j < cur; j++) {
				if (j >= pre)res += dp[i + 1][j];
			}
			if (cur < pre)break;
			pre = cur;
			if (not i)res++;
		}
		/*统计位数小于原数的答案数*/
		for (i64 i = 1; i <= len; i++) {
			for (i64 j = 1; j <= 9; j++) {
				res += dp[i][j];
			}
		}
		return res;
	};
	i64 ans =  cal(b) - cal(a - 1);
	cout << ans << endl;

}
signed main() {
	init();
	while (cin >> a >> b)
		solve();
}