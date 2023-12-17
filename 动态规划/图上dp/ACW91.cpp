
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

i64 w[maxn][maxn], N;//将前 i 位 与
void solve() {
	std::cin >> N;
	for (i64 i = 0; i < N; i++) {
		for (i64 j = 0; j < N; j++) {
			std::cin >> w[i][j];
		}
	}
	vector dp(((1 << N) + 5), vector<i64>(N + 5, inf));
	dp[1][0] = 0;
	for (i64 i = 0; i < (1 << N); i++) {
		for (i64 j = 0; j < N; j++) {
			if ((i >> j) & 1) {
				for (i64 k = 0; k < N; k++) {
					if ((i >> k) & 1) { // 哈密顿图不允许重复访问
						dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);
					}
				}
			}
		}
	}
	//遍历过某个状态, 停留在某点的最短路径
	cout << dp[(1 << N) - 1][N - 1] << endl;
}
signed main() {
	solve();
}


/*写法二*/
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

i64 w[maxn][maxn], N;//将前 i 位 与
void solve() {
	std::cin >> N;
	for (i64 i = 0; i < N; i++) {
		for (i64 j = 0; j < N; j++) {
			std::cin >> w[i][j];
		}
	}
	vector dp(((1 << N) + 5), vector<i64>(N + 5, inf));
	dp[1][0] = 0;
	for (i64 i = 0; i < N; i++) {
		dp[(1 << i)][i] = w[0][i];
	}
	for (i64 i = 1; i < (1 << N); i++) {
		for (i64 j = 0; j < N; j++) {
			if ((i >> j) & 1) {
				for (i64 k = 0; k < N; k++) {
					if (((i >> k) & 1) == 0) {
						dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + w[j][k]);
					}
				}
			}
		}
	}
	//遍历过某个状态, 停留在某点的最短路径
	cout << dp[(1 << N) - 1][N - 1] << endl;
}
signed main() {
	solve();
}
