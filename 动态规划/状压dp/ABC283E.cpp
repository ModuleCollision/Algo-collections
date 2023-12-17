/*与状压dp相同的思路,枚举状态查看是否可以转移*/
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

i64 N, M, a[maxn][maxn]; i64 dp[maxn][2][2];//定义在第i行处 ,i-1和i是否
//翻转的情况下除第i行外没有孤立点所能达到的最大价值
void solve() {
	auto check = [&](i64 u, i64 x, i64 y, i64 z) {
		for (i64 i = 1; i <= M; i++) {
			if (a[u][i] != a[u][i - 1] and
			        a[u][i] != a[u][i + 1] and
			        (a[u][i]^y) != (a[u - 1][i]^x) and (a[u][i]^y) != (a[u + 1][i]^z)) {
				return false;
			}
		}//只需判定第u行五孤立点即可
		return true;
	};
	memset(a, 0xff, sizeof(a));
	std::cin >> N >> M;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 1; j <= M; j++) {
			std::cin >> a[i][j];
		}
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[1][0][0] = 0; dp[1][0][1] = 1;
	for (i64 i = 2; i <= N + 1; i++) {
		for (i64 j = 0; j < 2; j++) {
			for (i64 k = 0; k < 2; k++) {
				for (i64 z = 0; z < 2; z++) {
					if (check(i - 1, j, k, z)) {
						dp[i][k][z] = min(dp[i][k][z], dp[i - 1][j][k] + z);
					}
				}
			}
		}
	}
	i64 ans = inf;
	for (i64 i = 0; i < 2; i++) {
		for (i64 j = 0; j < 2; j++) {
			ans = min(ans, dp[N + 1][i][j]);
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}