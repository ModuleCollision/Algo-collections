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

i64 N, C[15], dp[maxn];
void solve() {
	std::cin >> N;
	for (i64 i = 1; i <= 9; i++) {
		std::cin >> C[i];
	}
	for (i64 i = 1; i <= 9; i++) {
		for (i64 j = 1e6; j >= C[i]; j--) {
			dp[j] = max(dp[j], 10 * dp[j - C[i]] + i);
		}
	}
	i64 ans = 0;
	for (i64 i = 0; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}
signed main() {
	solve(); return 0;
}