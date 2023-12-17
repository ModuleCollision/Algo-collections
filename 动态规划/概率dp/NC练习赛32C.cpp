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


i64 n; f64 dp[maxn];
//期望递推
void solve() {
	std::cin >> n;
	dp[0] = 1;
	for (i64 i = 1; i <= n; i++) {
		f64 p = dp[i - 1] / (i - 1 + 2);
		dp[i] = (dp[i - 1] * (1 - p)) + (dp[i - 1] + 1) * p;
	}
	printf("%.7lf", dp[n]);
}
signed main() {
	solve();
}