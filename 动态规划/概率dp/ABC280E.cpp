/*期望dp*/
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
	i64 n, p; std::cin >> n >> p;
	vector dp(n + 5, 0);
	dp[0] = 0;
	auto inv = [&](i64 x) {
		i64 b = mod - 2; i64 ret = 1;
		while (b) {
			if (b & 1)ret = ret * x % mod;
			x = x * x % mod;
			b >>= 1;
		}
		return ret;
	};
	i64 w = p * inv(100) % mod;
	i64 ws = ((1 - w) % mod + mod) % mod;
	for (i64 i = 1; i <= n; i++) {
		i64 v = (dp[i - 1] * ws % mod + dp[max(0ll, i - 2)] % mod * w % mod) % mod;
		dp[i] = (dp[i] % mod + v % mod + 1) % mod;
	}
	cout << dp[n] % mod << endl;
}
signed main() {
	solve();
}