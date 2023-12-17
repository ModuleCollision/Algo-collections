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
	i64 n, m, k, d; std::cin >> n >> m >> k >> d;
	vector dp(m + 5, vector<i64>(d + 5, 0));
	//顺推
	auto inv = [&](i64 x) {
		i64 b = mod - 2; i64 ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	i64 q = k % mod * inv(n) % mod;
	i64 p = ((1 - q) % mod + mod) % mod;
	for (i64 i = m - 1; i >= 0; i--) {
		for (i64 j = d - 2; j >= 0; j--) {
			dp[i][j] = (dp[i][j] % mod + dp[i + 1][j + 1] % mod * p) % mod;//没有获奖
			dp[i][j] = (dp[i][j] % mod + (dp[i + 1][0] + 1) % mod * q) % mod;//获奖了
		}
		dp[i][d - 1] = (dp[i][d - 1] % mod + dp[i + 1][0] + 1) % mod;
	}
	cout << dp[0][0] % mod*n % mod << endl;
}
signed main() {
	i64 T; std::cin >> T;
	while (T--)
		solve();
}