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

void solve() {
	i64 n, m, d; std::cin >> n >> m >> d;
	vector<i64>a(m + 5, 0), b(m + 5, 0), t(m + 5, 0);
	for (i64 i = 1; i <= m; i++)cin >> a[i] >> b[i] >> t[i];
	vector<i64>q(n + 5, 0);
	vector<vector<i64>>dp(2, vector<i64>(n + 5, -inf));//前i个炮火在第j地
	i64 cur = 1;
	for (i64 i = 1; i <= n; i++) {
		dp[0][i] = 0;
	}
	for (i64 i = 1; i <= m; i++) {
		i64 hed = 1, tal = 0; i64 k = 1;
		for (i64 j = 1; j <= n; j++) {
			for (; k <= min(n, j + d * (t[i] - t[i - 1])); k++) {
				while (hed <= tal and dp[cur ^ 1][q[tal]] <= dp[cur ^ 1][k])tal--;
				q[++tal] = k;//随着j的移动,有限队列中存储的数据下标范围也在移动
			}
			while (hed <= tal and q[hed] < max(1i64, j - d * (t[i] - t[i - 1]))) {
				hed++;
			}//单调队列维护一定下标范围内数据的最小值
			dp[cur][j] = dp[cur ^ 1][q[hed]] - abs(a[i] - j) + b[i];//直接查询即可
		}
		cur ^= 1;//滚动数组优化,因为只可能由前一大维转移而来
	}
	i64 ans = -inf;
	for (i64 i = 1; i <= n; i++) {
		ans = max(ans, dp[cur ^ 1][i]);
	}
	cout << ans << endl;
}
signed main() {
	solve();
}
