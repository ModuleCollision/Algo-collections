/*dp求概率*/
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


i64 inv[maxn], p[maxn], n, a, b;
i64 w[maxn];
void solve() {
	inv[1] = 1;
	for (i64 i = 2; i <= 1e6; i++) {
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
	}
	std::cin >> n >> a >> b;
	i64 P = a * inv[b] % mod;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> w[i];
	}
	for (i64 i = 1; i <= n; i++) {
		std::cin >> a >> b;
		p[i] = a % mod * inv[b] % mod;
	}
	vector<i64>dp(maxn, 0);
	i64 ans = 0;
	dp[1] = p[1] % mod;
	ans += dp[1] * w[1] % mod;
	for (i64 i = 2; i <= n; i++) {
		dp[i] = (dp[i] % mod + dp[i - 1] % mod * (p[i] + P) % mod) % mod;
		dp[i] = (dp[i] % mod + (1 - dp[i - 1] + mod) % mod * p[i] % mod) % mod;
		ans = (ans % mod + dp[i] % mod * w[i]) % mod;
	}
	/*此为根据∑x * px的定义求取期望*/

	cout << ans % mod << endl;
}
signed main() {
	solve();
}