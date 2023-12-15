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

constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;
constexpr i64 mod = 20000311;
void solve() {
	i64 n, m; std::cin >> n >> m;
	vector<i64>p(m + 5, 0);
	for (i64 i = 1; i <= m; i++)std::cin >> p[i];
	std::sort(p.begin() + 1, p.begin() + 1 + m);
	auto inv = [&](i64 x) {
		i64 y = mod - 2, ret = 1;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret;
	};
	vector<i64>dp(n + 5, 0);
	vector<i64>fac(n + 5, 0);
	fac[0] = 1;
	for (i64 i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] % mod * i % mod;
	}
	dp[1] = fac[p[1]];//维护的是不满足第i个条件但满足前i - 1个条件的总方案数
	for (i64 i = 2; i <= m; i++) {
		dp[i] = fac[p[i]] % mod;
		for (i64 j = 1; j < i; j++) {
			dp[i] = ((dp[i] - fac[p[i] - p[j]] % mod * dp[j] % mod) % mod + mod) % mod;
		}
	}
	i64 ans = fac[n];
	for (i64 i = 1; i <= m; i++) {
		ans = ((ans - dp[i] * fac[n - p[i]] % mod) + mod) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
//这里是容斥原理的一个变式, 可以画韦恩图来理解
//用于求交集
