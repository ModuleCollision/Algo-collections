/*概率dp模型*/
/*不外乎两种,概率dp与期望dp,注意概率与期望的递推是不同的*/
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

i64 dp[maxn][maxn], N, M, K;
void solve() {
	std::cin >> N >> M >> K;
	dp[0][0] = 1;//通过几步到达哪个坐标的概率
	auto inv = [&](i64 x) {
		i64 ret = 1, b = mod - 2;
		while (b) {
			if (b & 1) {
				ret = ret * x % mod;
			}
			x = x * x % mod;
			b >>= 1;
		}
		return ret % mod;
	};
	//此为概率顺推
	for (i64 i = 0; i <= K; i++) {//枚举期望步数
		for (i64 j = 0; j < N; j++) {//枚举坐标
			for (i64 k = 1; k <= M; k++) {//枚举前进格子数
				if (j + k <= N) {
					dp[i + 1][j + k] = (dp[i + 1][j + k] % mod + dp[i][j] % mod * inv(M) % mod) % mod;
				} else {
					dp[i + 1][2 * N - j - k] = (dp[i + 1][2 * N - j - k] % mod + dp[i][j] % mod * inv(M) % mod) % mod;
				}
			}
		}
	}
	i64 ans = 0;
	for (i64 i = 0; i <= K; i++) {
		ans = ans % mod + dp[i][N] % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}