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
	vector<double>dp(N + 5, 0);
	dp[1] = 3.5;
	for (i64 i = 2; i <= N; i++) {
		for (i64 j = 1; j <= 6; j++) {
			dp[i] += max(dp[i - 1], (double)j) / 6;
		}
	}
	printf("%.6lf", dp[N]);
}
signed main() {
	solve();
}