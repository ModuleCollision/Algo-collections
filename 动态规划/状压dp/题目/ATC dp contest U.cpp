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

i64 dp[maxn], v[maxn];//定义dp[mask]为状态msk已经分好组的最大价值
i64 s[25][25], N;
void solve() {
	std::cin >> N;
	for (i64 i = 0; i < N; i++) {
		for (i64 j = 0; j < N; j++) {
			std::cin >> s[i][j];
		}
	}
	for (i64 i = 0; i < (1 << N); i++) {
		for (i64 j = 0; j < N; j++) {
			for (i64 k = j + 1; k < N; k++) {
				if (((i >> j) & 1) and (i >> k) & 1) {
					v[i] += s[j][k];
				}
			}
		}
	}
	for (i64 i = 0; i < (1 << N); i++) {
		for (i64 j = i; j; j = i & (j - 1)) {
			i64 k = i ^ j;
			dp[i] = max(dp[i], dp[k] + v[j]);
		}
	}
	cout << dp[(1 << N) - 1] << endl;
}
signed main() {
	solve();
}