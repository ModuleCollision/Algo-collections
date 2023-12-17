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

i64 dp[1005][1005][105];
void solve() {
	i64 n, s; std::cin >> n >> s;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	for (i64 i = 1; i <= n + 1; i++)dp[i][i - 1][0] = 1;
	//背包类型的计数dp : 初始化第0维
	i64 ans = 0;
	for (i64 len = 1; len <= n; len++) {
		for (i64 l = 1; l + len - 1 <= n; l++) {
			i64 r = l + len - 1;
			for (i64 k = 0; k <= s; k++) {
				dp[l][r][k] = (dp[l][r][k] % mod + dp[l][r - 1][k]) % mod;
				if (k >= A[r])dp[l][r][k] = (dp[l][r][k] % mod + dp[l][r - 1][k - A[r]]) % mod;
				//避免重复计算
			}
		}
	}
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = i; j <= n; j++) {
			ans = (ans % mod + dp[i][j][s]) % mod;
		}
	}
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

i64 dp[maxn][maxn];
void solve() {
	i64 n, s; std::cin >> n >> s;
	vector<i64>A(n + 5, 0);
	for (i64 i = 1; i <= n; i++)cin >> A[i];
	i64 ans = 0;
	for (i64 i = 0; i <= n; i++)dp[i][0] = i + 1;
	for (i64 i = 1; i <= n; i++) {
		for (i64 j = 1; j <= s; j++) {
			dp[i][j] = (dp[i][j] % mod + dp[i - 1][j]) % mod;
			if (j >= A[i]) {
				dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - A[i]]) % mod;
			}
		}
		//所有以i结尾的区间的方案数
		ans = (ans % mod + dp[i][s]) % mod;
	}
	cout << ans << endl;
}
signed main() {
	solve();
}

