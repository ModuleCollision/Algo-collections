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
	i64 n, k; std::cin >> n >> k;
	vector<i64>dp(n + 5, 0);
	dp[0] = 1;
	vector<i64>pre(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		//if (i >= k + 1)
		dp[i] = (dp[i] % mod + dp[max(0i64, i - k - 1)]) % mod;
		//选择放一头公牛
		dp[i] = (dp[i] % mod + dp[i - 1]) % mod;
	}
	cout << dp[n] % mod << endl;
}
signed main() {
	solve();
}