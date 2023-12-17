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

i64 N, M;
std::vector<i64>p[maxn];
i64 dp[maxn][maxn];
void solve() {
	std::cin >> N >> M;
	for (i64 i = 1; i <= N; i++) {
		p[i].push_back(0);
		for (i64 j = 1; j <= M; j++) {
			i64 v; std::cin >> v;
			p[i].push_back(v);
		}
		sort(p[i].begin() + 1, p[i].begin() + 1 + M);
	}
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = 1; j <= M; j++) {
			p[i][j] += p[i][j - 1];
		}
	}
	for (i64 i = 1; i <= N; i++) {
		for (i64 j = i; j <= i * M; j++) {//满足需求的下限和生产上限
			for (i64 k = 0; k <= M; k++) {
				if (j - k >= i - 1) {//满足前i - 1天的需求
					dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + p[i][k] + k * k);//转移方程
				}
			}
		}
	}
	i64 ans = inf;
	for (i64 i = 0; i <= N * M; i++) {
		ans = min(ans, dp[N][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}

