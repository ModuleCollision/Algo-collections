/*期望dp+状态机模型*/
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
constexpr i64 maxn = 2e2 + 10;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

f64 dp[maxn][maxn][maxn << 1], p[maxn];
int main() {
	i64 N, L, K;
	std::cin >> N >> L >> K;
	K = std::min(K, N);
	f64 ans = 0;
	dp[0][0][N + K] = 1;
	for (i64 i = 1; i <= N; i++) {
		std::cin >> p[i];
		p[i] /= 100;
	}
	for (i64 i = 1; i <= N; i++) {
		i64 x; std::cin >> x;
		for (i64 j = 1; j <= i; j++) {
			for (i64 k = 0; k <= N + N; k++) {
				if (k + x >= 0) {
					dp[i][j][min(2 * N, k + x)] += p[i] * dp[i - 1][j - 1][k];
					dp[i][j - 1][k] += (1 - p[i]) * dp[i - 1][j - 1][k];
					//转移:由前i次挑战且第j次挑战赢或者不赢的概率转移而来
				}
			}
		}
	}
	for (i64 j = L; j <= N; j++) {
		for (i64 k = N; k <= (maxn << 1); k++) {
			ans += dp[N][j][k];
		}
	}
	printf("%.6lf", ans);
	return 0;
}

