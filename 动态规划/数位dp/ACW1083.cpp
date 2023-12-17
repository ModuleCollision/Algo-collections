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

int a, b; int dp[1005][15];
void init() {
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	//一共有 i 位 ,最高位为 j 的总序列数
	for (int i = 2; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (abs(k - j) >= 2)dp[i][j] += dp[i - 1][k];
			}
		}
	}
}
void solve() {
	std::cin >> a >> b;
	//00..0 到 99..9 中 以 0 - 9结尾的windy序列
	auto cal = [&](i64 x) {
		vector<i64>num;
		while (x) {
			num.push_back(x % 10); x /= 10;
		}
		int res = 0; int pre = -10; int len = num.size() - 1;
		for (i64 i = len; i >= 0; i--) {
			int cur = num[i];
			for (int j = (i == len); j < cur; j++) {
				if (abs(j - pre) >= 2)res += dp[i + 1][j];
			}
			if (abs(cur - pre) < 2)break;
			pre = cur;
			if (not i)res++;
		}
		for (int i = 1; i <= len; i++) {
			for (int j = 1; j <= 9; j++) {
				res += dp[i][j];
			}
		}
		return res;
	};
	int ans =  cal(b) - cal(a - 1);
	cout << ans << endl;

}
signed main() {
	init();
	//while (cin >> a >> b)
	solve();
}