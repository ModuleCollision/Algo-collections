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

/*定义dp[mask]为前num(i)个男生与状态为j的女生配对的方案数*/
/*mask有i个1,为前i个男人,第j位表示第j个女人*/
i64 d[maxn][maxn]; i64 N;
i64 dp[1 << maxn];
void solve() {
	std::cin >> N;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 1; j <= N; j++) {
			std::cin >> d[i][j];
		}
	}
	dp[0] = 1;
	for (i64 i = 0; i < (1 << N); i++) {
		i64 cnt = 0;
		for (i64 j = 0; j < N; j++) {
			if ((i >> j) & 1) {
				cnt++;
			}
		}
		for (i64 j = 0; j < N; j++) {
			if (((i >> j) & 1) and d[cnt][j + 1]) {
				dp[i] = (dp[i] % mod + dp[i ^ (1 << j)]) % mod;//前 i - 1个人与 状态为 (i ^ (1 << j))配好了对
			}
		}
	}
	cout << (dp[(1 << N) - 1]) << endl;
}
signed main() {
	solve();
}