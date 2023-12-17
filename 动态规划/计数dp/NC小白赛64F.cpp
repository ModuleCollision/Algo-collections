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

i64 dp[4][maxn];
bool vis[4][maxn];
void solve() {
	i64 n, m;
	std::cin >> n >> m;
	dp[1][1] = 1;
	i64 u, v;
	for (i64 i = 1; i <= m; i++) {
		std::cin >> u >> v;
		vis[u][v] = 1;
	}
	for (i64 j = 1; j <= n - 1; j++) {
		for (i64 i = 1; i <= 3; i++) {
			if (vis[i][j]) {
				dp[max(i - 1, 1i64)][j + 1] = (dp[max(i - 1, 1i64)][j + 1] % mod + dp[i][j]) % mod;
				dp[min(3i64, i + 1i64)][j + 1] = (dp[min(3i64, i + 1)][j + 1] % mod + dp[i][j]) % mod;
				dp[i][min(j + 2i64, n)] = (dp[i][min(j + 2i64, n)] % mod + dp[i][j]) % mod;
			} else {
				dp[i][j + 1] = (dp[i][j + 1] % mod + dp[i][j]) % mod;
			}
		}
	}
	for (i64 i = 1; i <= 3; i++) {
		cout << dp[i][n] % mod << endl;
	}
}
signed main() {
	solve();
}