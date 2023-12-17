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
	i64 n, m; std::cin >> n >> m;
	vector<i64>A(n + 5, 0), B(n + 5, 0);
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i] >> B[i];
	}
	vector<i64>sz(m + 5);
	for (i64 i = 1; i <= m; i++)cin >> sz[i];
	vector<i64>pre(n + 5);
	vector<i64>c(max(n, m) + 1, 0); i64 id = 0;
	for (i64 i = max(1i64, m - n + 1); i <= m; i++) {
		c[++id] = sz[i];
	}
	vector dp(n + 5, vector (n + 5, vector<i64>(200, -inf)));
	for (i64 i = 1; i <= n + 1; i++) {
		for (i64 k = 0; k <= 200; k++) {
			dp[i][i - 1][k] = 0;
		}
	}
	//背包需要初始化所有的
	vector ndp(id + 5, vector<i64>(n + 5, 0));
	for (i64 len = 1; len <= n; len++) {
		for (i64 i = 1; i + len - 1 <= n; i++) {
			i64 j = i + len - 1;
			for (i64 k = 0; k <= 200; k++) {
				dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j][k]);
				if (k >= A[j]) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - A[j]] + B[j]);
				}
			}
		}
	}
	/*区间dp*/
	i64 ans = 0;
	for (i64 i = 1; i <= id; i++) {
		for (i64 j = 0; j <= n; j++) {
			for (i64 k = 0; k <= j; k++) {
				ndp[i][j] = max(ndp[i][j], ndp[i - 1][k] + dp[k + 1][j][c[i]]);
				ans = max(ans, ndp[i][j]);
			}
		}
	}
	/*背包dp*/
	cout << ans << endl;
}
signed main() {
	solve();
}
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

i64 dp[205][205][205];
i64 pre[205][205]; i64 sz[maxn]; i64 c[maxn]; i64 A[205], B[205];
void solve() {
	i64 n, m; std::cin >> n >> m;
	for (i64 i = 1; i <= n; i++) {
		std::cin >> A[i] >> B[i];
	}
	for (i64 i = 1; i <= m; i++)cin >> sz[i];
	i64 id = 0;
	for (i64 i = max(1i64, m - n + 1); i <= m; i++) {
		c[++id] = sz[i];
	}
	for (i64 i = 1; i <= id; i++) {//前i个操作 到达第 j 个房间 用了k的容量
		for (i64 j = 0; j <= n; j++) {
			for (i64 k = 0; k <= sz[i]; k++) {
				if (j) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);//打个洞
				}
				if (k >= A[i] and j >= 1) {//从这里穿过去
					dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - A[j]] + B[j]);
				}
				if (not k)
					dp[i][j][0] = max(dp[i][j][0], pre[i - 1][j]);
				pre[i][j] = max(pre[i][j], dp[i][j][k]);
			}
		}
	}
	i64 ans = 0;
	for (i64 i = 1; i <= id; i++) {
		for (i64 k = 0; k <= c[id]; k++) {
			ans = max(ans, dp[i][n][k]);
		}
	}
	cout << ans << endl;
}
signed main() {
	solve();
}