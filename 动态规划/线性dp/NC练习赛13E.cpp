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
	string s; std::cin >> s; i64 len = s.size();
	s = " " + s;
	i64 n; std::cin >> n;
	vector dp1(len + 5, vector (n + 5, array<i64, 2> { -inf, -inf})); //在某坐标, 修改了几次, 朝向哪里的最大值
	vector dp2(len + 5, vector(n + 5, array<i64, 2> { inf, inf}));//在某坐标, 修改了几次, 朝向哪里的最小值
	dp1[0][0][0] = dp2[0][0][0] = 0;
	for (i64 i = 1; i <= len; i++) {
		for (i64 j = 0; j <= n; j++) {
			if (s[i] == 'T') {
				if (dp1[i - 1][j][1] != -inf)
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][1]);
				if (dp1[i - 1][j][0] != -inf)
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][0]);//不修改
				if (j >= 1) {
					if (dp1[i - 1][j - 1][0] != -inf)
						dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][0] + 1);
					if (dp1[i - 1][j - 1][1] != -inf)
						dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j - 1][1] - 1);//修改
				}
			} else {
				if (dp1[i - 1][j][0] != -inf)
					dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j][0] + 1);
				if (dp1[i - 1][j][1] != -inf)
					dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j][1] - 1);
				if (j >= 1) {
					if (dp1[i - 1][j - 1][1] != -inf)
						dp1[i][j][0] = max(dp1[i][j][0], dp1[i - 1][j - 1][1]);
					if (dp1[i - 1][j - 1][0] != -inf)
						dp1[i][j][1] = max(dp1[i][j][1], dp1[i - 1][j - 1][0]);
				}
			}
		}
	}
	for (i64 i = 1; i <= len; i++) {
		for (i64 j = 0; j <= n; j++) {
			if (s[i] == 'T') {
				if (dp2[i - 1][j][1] != inf)
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][1]);
				if (dp2[i - 1][j][0] != inf)
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][0]);//不修改
				if (j >= 1) {
					if (dp2[i - 1][j - 1][0] != inf)
						dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][0] + 1);
					if (dp2[i - 1][j - 1][1] != inf)
						dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j - 1][1] - 1);//修改
				}
			} else {
				if (dp2[i - 1][j][0] != inf)
					dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j][0] + 1);
				if (dp2[i - 1][j][1] != inf)
					dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j][1] - 1);
				if (j >= 1) {
					if (dp2[i - 1][j - 1][1] != inf)
						dp2[i][j][0] = min(dp2[i][j][0], dp2[i - 1][j - 1][1]);
					if (dp2[i - 1][j - 1][0] != inf)
						dp2[i][j][1] = min(dp2[i][j][1], dp2[i - 1][j - 1][0]);
				}
			}
		}
	}
	i64 res = 0;
	if (dp1[len][n][0] != -inf)res = max(res, abs(dp1[len][n][0]));
	if (dp1[len][n][1] != -inf)res = max(res, abs(dp1[len][n][1]));
	if (dp2[len][n][0] != inf)res = max(res, abs(dp2[len][n][0]));
	if (dp2[len][n][1] != inf)res = max(res, abs(dp2[len][n][1]));
	cout << res << endl;
}
signed main() {
	solve();
}