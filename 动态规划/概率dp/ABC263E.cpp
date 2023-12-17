/*dp求期望*/
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


	i64 N; std::cin >> N;
	vector<i64>A(N + 5, 0);
	for (i64 i = 1; i <= N - 1; i++)std::cin >> A[i];
	auto inv = [&](i64 x) {
		i64 ret = 1, y = mod - 2;
		while (y) {
			if (y & 1)ret = ret * x % mod;
			x = x * x % mod;
			y >>= 1;
		}
		return ret % mod;
	};
	vector<i64>pre(N + 5, 0);
	vector<i64>dp(N + 5, 0); dp[N] = 0;
	for (i64 i = N - 1; i >= 1; i--) {
		dp[i] = (dp[i] % mod + (pre[i + 1] - pre[i + A[i] + 1]) % mod + mod) % mod;
		dp[i] = (dp[i] % mod + (1 + A[i])) % mod;
		dp[i] = dp[i] % mod * inv(A[i]) % mod;
		pre[i] = (pre[i + 1] % mod + dp[i]) % mod;
	}
	cout << dp[1] << endl;
}
signed main() {
	solve();
}



