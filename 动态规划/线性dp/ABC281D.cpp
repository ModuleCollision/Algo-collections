//维护最大最小值
//题干对第二维有要求,故需要维护第二维状态
//否则就是类背包问题,直接每个状态枚举选择转移(选 or 不选)即可
//没有对第二维的0做初始化则在做dp的过程中一定要维护到!!!
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
最大最小值
i64 dp[105][105][105];
void solve() {
	std::cin >> N >> K >> D;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> A[i];
	}
	for (i64 i = 0; i <= N; i++) {
		for (i64 j = 0; j <= K; j++) {
			for (i64 k = 0; k <= D; k++) {
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 0; j <= K; j++) {
			for (i64 s = 0; s < D; s++) {
				if (dp[i - 1][j][s] != -inf) {
					dp[i][j][s] = max(dp[i][j][s], dp[i - 1][j][s]);
				}
				if (j >= 1) {
					if (dp[i - 1][j - 1][s] != -inf)
						dp[i][j][(s + A[i]) % D] = max(dp[i - 1][j - 1][s] + A[i], dp[i][j][(s + A[i]) % D]);
				}
			}
		}
	}
	if (dp[N][K][0] == -inf)puts("-1");
	else cout << dp[N][K][0] << endl;
}
signed main() {
	solve();
}
