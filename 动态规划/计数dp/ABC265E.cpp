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

i64 dp[maxn][maxn][maxn];
i64 N, M, A, B, C, D, E, F;
std::map<pair<i64, i64>, i64>vis;
void solve() {
	std::cin >> N >> M;
	for (i64 i = 1; i <= M; i++) {
		i64 X, Y;
		std::cin >> X >> Y;
		vis[ {X, Y}] = 1;

	}
	dp[0][0][0] = 1; i64 ans = 0;
	for (i64 i = 0; i <= N; i++) {
		for (i64 j = 0; j <= N - i; j++) {
			for (i64 k = 0; k <= N - i - j; k++) {
				i64 nx = i * A + j * C + k * E;
				i64 ny = i * B + j * D + k * F;
				if (vis[ {nx, ny}])continue;
				if (i)dp[i][j][k] = (dp[i][j][k] % mod + dp[i - 1][j][k]) % mod;
				if (j)dp[i][j][k] = (dp[i][j][k] % mod + dp[i][j - 1][k]) % mod;
				if (k)dp[i][j][k] = (dp[i][j][k] % mod + dp[i][j][k - 1]) % mod;
				if (i + j + k == N) {
					ans = ans % mod + dp[i][j][k] % mod;
				}
			}
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}